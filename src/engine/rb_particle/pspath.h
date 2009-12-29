//****************************************************************************/
//  File:   PSPath.h
//  Date:   12.07.2006
//  Author: Ruslan Shestopalyuk
//****************************************************************************/
#ifndef __PSPath_H__
#define __PSPath_H__

//****************************************************************************/
//  Class:  PSPath
//  Desc:   Base class for particle system operators
//****************************************************************************/
class PSPath : public PSOperator
{
public: 
    PSPath();

    expose( PSPath )
    {
        parent(PSOperator);
    }
}; // class PSPath

#endif // __PSPath_H__


