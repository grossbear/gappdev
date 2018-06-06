///////////////////////////////////////////////////////////////////////////////////////
//  StdFileStream.cpp
//
//  File Input/Output Stream Class Using Standard C Functions
//  Created: 23-11-2011
//  Modified: 28-05-2018
//
///////////////////////////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "../FileStream.h"


///////////////////////////////////////////////////////////////////////////////////////
CStdioFileStream::CStdioFileStream():m_file(NULL),m_error(0),m_size(0){}

///////////////////////////////////////////////////////////////////////////////////////
CStdioFileStream::~CStdioFileStream()
{
    Close();
}

///////////////////////////////////////////////////////////////////////////////////////
bool CStdioFileStream::Open(const char *filename, OpenMode mode)
{
    if(filename == NULL)
        return (bool)false;

    if(m_file != NULL)
        return (bool)false;

    static const char mode_tab[][4] = {"rb","wb+","wb+","ab","ab+"};

    m_file = fopen(filename,&mode_tab[mode][0]);
    if(m_file == NULL)
    {
        //m_error = -1;
        return (bool)false;
    }

    return (bool)true;
}

///////////////////////////////////////////////////////////////////////////////////////
bool CStdioFileStream::Close()
{
    if(!m_file)
        return false;

    int error = fclose(m_file);
    m_file = NULL;
    m_size = 0;
    m_error = 0;
    return (bool)(error == 0);
}

///////////////////////////////////////////////////////////////////////////////////////
uint_t CStdioFileStream::Read(void *data, uint_t size)
{
    if(m_file == NULL)
        return -1;

    size_t readed = fread(data,size,1,m_file);

    return (uint_t)readed;
}

///////////////////////////////////////////////////////////////////////////////////////
uint_t CStdioFileStream::Write(const void *data, uint_t size)
{
    if(m_file == NULL)
        return -1;
    size_t written = fwrite(data,size,1,m_file);

    return (uint_t)written;
}

///////////////////////////////////////////////////////////////////////////////////////
bool CStdioFileStream::IsOpened()
{
    return (bool)(m_file != NULL);
}

///////////////////////////////////////////////////////////////////////////////////////
bool CStdioFileStream::Seek(isize_t offset, SeekMode mode)
{
    int error = 0;
    static const int mode_tab[] = {SEEK_SET,SEEK_CUR,SEEK_END};
#ifdef SIZE_INT_64
    error = _fseeki64(m_file,(__int64)offset,mode_tab[mode]);
#else
    error = fseek(m_file,offset,mode_tab[mode]);
#endif
    return (bool)(error==0);
}

///////////////////////////////////////////////////////////////////////////////////////
isize_t CStdioFileStream::GetPos()
{
    if(m_file == NULL)
        return -1;

    isize_t pos = -1;
#ifdef SIZE_INT_64
    pos = _ftelli64(m_file);
#else
    pos = ftell(m_file);
#endif
    return pos;
}

///////////////////////////////////////////////////////////////////////////////////////
isize_t CStdioFileStream::GetSize()
{
    if(m_file == NULL)
        return -1;

    if(m_size == 0)
    {
        isize_t currpos = GetPos();
        Seek(0,seek_end);
        m_size = GetPos();
        Seek(currpos,seek_set);
    }

    return m_size;
}

///////////////////////////////////////////////////////////////////////////////////////
bool CStdioFileStream::IsEOS()
{
    if(m_file == NULL)
        return (bool)false;
    int eof = feof(m_file);
    return (bool)(eof==0);
}

///////////////////////////////////////////////////////////////////////////////////////
