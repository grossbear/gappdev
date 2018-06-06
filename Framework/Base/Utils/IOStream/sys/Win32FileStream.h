///////////////////////////////////////////////////////////////////////////////////////
//  Win32FileStream.h
//
//  Win32 File Input/Output Stream Class
//  Created: 23-11-2011
//  Modified: 28-05-2018
//
///////////////////////////////////////////////////////////////////////////////////////

#ifndef __WIN32_FILE_STREAM_H__
#define __WIN32_FILE_STREAM_H__

#include <windows.h>


///////////////////////////////////////////////////////////////////////////////////////
class CWin32FileStream : public IDataStream
{
public:
    CWin32FileStream();
    virtual ~CWin32FileStream();

    bool    Open(const char *filename, OpenMode mode);
    bool    Close();

    uint_t  Read(void *data, uint_t size);
    uint_t  Write(const void *data, uint_t size);

    bool    IsOpened();
    bool    Seek(isize_t offset, SeekMode pos);

    isize_t   GetPos();
    isize_t   GetSize();

    bool    IsEOS();

protected:
    HANDLE  m_handle;
    int_t   m_error;
    int_t   m_size;
};

///////////////////////////////////////////////////////////////////////////////////////


#endif //__WIN32_FILE_STREAM_H__

