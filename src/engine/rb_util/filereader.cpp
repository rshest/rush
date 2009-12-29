//****************************************************************************/
//  File:  FileReader.cpp
//  Desc:  
//****************************************************************************/
#include "stdafx.h"
#include "FileReader.h"

//****************************************************************************/
//  FileReader implementation
//****************************************************************************/
FileReader::FileReader()
{
    m_hFile		= INVALID_HANDLE_VALUE;
    m_TotalSize = 0;
}

FileReader::FileReader( const char* fileName )
{
    m_FileName  = fileName;
    m_hFile		= INVALID_HANDLE_VALUE;
    m_TotalSize = 0;
    OpenFile( fileName );
}

bool FileReader::OpenFile( const char* fileName )
{
    m_FileName = fileName;
    m_hFile = CreateFile(   fileName, 
                            GENERIC_READ, 
                            FILE_SHARE_READ, 0, 
                            OPEN_EXISTING, 
                            FILE_ATTRIBUTE_NORMAL, 
                            NULL );

    if (m_hFile == INVALID_HANDLE_VALUE)
    {
        DWORD err = GetLastError();
        m_TotalSize = 0;
        return false;
    }
    else
    {
        m_TotalSize = ::GetFileSize( m_hFile, NULL );
        return true;
    }
} // FileReader::OpenFile

int FileReader::ReadStream( void* buf, int nBytes )
{
    if (m_hFile == INVALID_HANDLE_VALUE) return false;
    DWORD readBytes;

    if (buf == 0)
    {
        SetFilePointer( m_hFile, nBytes, NULL, FILE_CURRENT );
        return nBytes;
    }

    BOOL res = ReadFile( m_hFile, buf, nBytes, &readBytes, NULL );
    if (res == FALSE)
    {
        DWORD err = GetLastError();
        return 0;
    }
    return readBytes;
} // FileReader::ReadStream

void FileReader::Close()
{
    if (m_hFile == INVALID_HANDLE_VALUE) return;
    BOOL res = CloseHandle( m_hFile );
    if (res == FALSE) return;
    m_hFile = INVALID_HANDLE_VALUE;
} // FileReader::Close

bool FileReader::IsValid() const
{
    return (m_hFile != INVALID_HANDLE_VALUE);
} // FileReader::IsValid

