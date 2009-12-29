/***********************************************************************************/
//  File:   JModelAnim.cpp
//  Date:   10.08.2005
//  Author: Ruslan Shestopalyuk
/***********************************************************************************/
#include "stdafx.h"
#include "AABox.h"
#include "JMesh.h"
#include "JMaterial.h"
#include "JBone.h"
#include "FStream.h"
#include "Path.h"
#include "TrackPRS.h"
#include "JModel.h"
#include "JBoneInstance.h"
#include "JModelAnim.h"
#include "IFileServer.h"

/***********************************************************************************/
/*  JModelAnim implementation
/***********************************************************************************/
decl_class(JModelAnim);
JModelAnim::JModelAnim()
{
    m_Duration = 0.0f;
    m_ModelID  = -1;
} // JModelAnim::JModelAnim

void JModelAnim::Init()
{
} // JModelAnim::Init

TrackPRS& JModelAnim::AddTrack()
{
    m_Tracks.push_back( TrackPRS() );
    return m_Tracks.back();
} // JModelAnim::AddTrack

void JModelAnim::Clear()
{
    m_Tracks.clear();
} // JModelAnim::Clear 


const DWORD c_AnimFileFOURCC  = *((DWORD*)"RBAN");
const DWORD c_AnimFileVersion = 1;

template <class TTrack>
inline void SaveTrack( OutStream& os, const TTrack& track )
{
    int nKeys = track.GetNKeys();
    os << nKeys;
    os.Write( (BYTE*)track.GetTimes(), nKeys*sizeof( float ) );
    os.Write( (BYTE*)track.GetValues(), nKeys*sizeof( TTrack::ValType ) );
} // SaveTrack

template <class TTrack>
inline void LoadTrack( InStream& is, TTrack& track )
{
    int nKeys = 0;
    is >> nKeys;
    track.SetNKeys( nKeys );
    is.Read( (BYTE*)track.GetTimes(), nKeys*sizeof( float ) );
    is.Read( (BYTE*)track.GetValues(), nKeys*sizeof( TTrack::ValType ) );
} // SaveTrack

void JModelAnim::Serialize( OutStream& os ) const
{
    int nTracks = m_Tracks.size();
    os << c_AnimFileFOURCC << c_AnimFileVersion;
    JString c_Dummy( "" );
    os << c_Dummy;
    os << m_Duration << nTracks;
    for (int i = 0; i < nTracks; i++)
    {
        const TrackPRS& track = m_Tracks[i];
        os << track.m_Name << track.m_Flags << track.m_TM;
        SaveTrack( os, track.m_Pos          );
        SaveTrack( os, track.m_Rot          );
        SaveTrack( os, track.m_Scale        );
        SaveTrack( os, track.m_Visibility   );
    }
} 

bool JModelAnim::Unserialize( InStream& is )
{
    int nTracks = 0;
    DWORD fourcc = 0;
    DWORD version = -1;
    is >> fourcc >> version;
    
    JString dummy;
    if (version > 0)
    {
        is >> dummy;
        if (dummy.size() > 0)
        {
            m_ModelName = dummy;
        }
    }

    if (fourcc != c_AnimFileFOURCC)
    {
        rlog.err( "File %s is not model animation file.", GetName() );
        return false;
    }

    if (version > c_AnimFileVersion)
    {
        rlog.err( "Animation file %s has incompatible version (%d).", GetName(), version );
        return false;
    }

    is >> m_Duration >> nTracks;
    m_Tracks.resize( nTracks );
    for (int i = 0; i < nTracks; i++)
    {
        TrackPRS& track = m_Tracks[i];
        is >> track.m_Name >> track.m_Flags >> track.m_TM;
        LoadTrack( is, track.m_Pos          );
        LoadTrack( is, track.m_Rot          );
        LoadTrack( is, track.m_Scale        );
        LoadTrack( is, track.m_Visibility   );
    }
    return true;
} 

bool JModelAnim::Bind( JModel* pModel )
{
    if (!pModel) return false;
    JBoneInstance* pBones = pModel->GetBoneInstances();
    int nBones = pModel->GetNBones();
    int nTracks = m_Tracks.size();
    bool bOK = true;
    for (int i = 0; i < nTracks; i++)
    {
        TrackPRS& track = m_Tracks[i];
        track.m_Tag = -1;
        for (int j = 0; j < nBones; j++)
        {
            JBone* pBone = pBones[j].m_pBone;
            if (!stricmp( track.m_Name.c_str(), pBone->GetName() ))
            {
                track.m_Tag = j;
                break;
            }
        }
        if (track.m_Tag == -1)
        {
            bOK = false;
        }
    }
    return bOK;
} // JModelAnim::Bind

bool JModelAnim::Apply( JBoneInstance* pBones, float cTime, float weight )
{
    int nTracks = m_Tracks.size();
    for (int i = 0; i < nTracks; i++)
    {
        const TrackPRS& track = m_Tracks[i];
        if (track.m_Tag == -1) continue;
        JBoneInstance& bone = pBones[track.m_Tag];
        Vec3       pos    = track.m_Pos.GetValue( cTime );
        Vec3       scale  = track.m_Scale.GetValue( cTime );
        Quaternion rot    = track.m_Rot.GetValue( cTime );
        BYTE       vis    = track.m_Visibility.GetValue( cTime );
        
        if (weight < 1.0f)
        {
            Vec3 oldPos, oldScale;
            Quaternion oldRot;
            bone.m_LocalTM.factorize( oldScale, oldRot, oldPos );
            float oldW = 1.0f - weight;
            pos   = oldPos*oldW + weight*pos;
            scale = oldScale*oldW + weight*scale;
            float cosTheta = oldRot.dot( rot );
		    if (cosTheta < 0.0f)
		    {
			    oldRot.reverse();
		    }
            rot.slerp( oldRot, rot, weight );
        }

        bone.m_LocalTM.srt( scale, rot, pos );
        const BYTE c_InvisibleValue = 1;
        bone.m_bVisible = (vis == c_InvisibleValue) ? false : true;
    }
    return false;
} // JModelAnim::Apply



