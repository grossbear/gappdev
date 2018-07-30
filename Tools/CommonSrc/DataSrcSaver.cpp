////////////////////////////////////////////////////////////////////////////////////////////////
//  DataSrcSaver.cpp
//	
//  Class for saving tables data and variables as C/C++ header
//	
////////////////////////////////////////////////////////////////////////////////////////////////

//#include <stdint.h>
//#include "Base/Common/PlatformTypes.h"
#include "DataSrcSaver.h"
#include <utility>
#include <iostream>
#include <stdio.h>

#define FILE_EXTENSION      ".h"

#define PROGRAMME_INFO      "File automatically generated by "

#define STATIC_KEYWORD      "static"
#define CONST_KEYWORD       "const"
#define UNSIGNED_KEYWORD    "unsigned"
#define CHAR_KEYWORD        "char"   
#define SHORT_KEYWORD       "short"
#define INT_KEYWORD         "int"
#define FLOAT_KEYWORD       "float"
#define DOUBLE_KEYWORD      "double"
#define INT64_KEYWORD       "long long"
#define LONG_DOUBLE_KEYWORD "long double"

#define MAX_LINE_LEN        96
#define MAX_BITMAPS_NUM     256
#define MAX_BITMAP_SIZEX    128
#define MAX_BITMAP_SIZEY    128

#define MAX_BUFFER_SIZE     1024


static const char HexTab[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};


////////////////////////////////////////////////////////////////////////////////////////////////
CDataSrcSaver::CDataSrcSaver(const char *path, const char *file_name, bool inline_table):
mFileStream(NULL),
m_bWriteTableOnce(inline_table),
mSaveStage(SourceStageBegin)
{
    m_strFileName = std::string(file_name);
    
    OpenSrcFile(path,file_name);
}
////////////////////////////////////////////////////////////////////////////////////////////////
CDataSrcSaver::~CDataSrcSaver()
{
    CloseSrcFile();
}

////////////////////////////////////////////////////////////////////////////////////////////////
bool CDataSrcSaver::IsSrcFileOpened() const
{
    return mFileStream != NULL;
}

////////////////////////////////////////////////////////////////////////////////////////////////
bool CDataSrcSaver::WriteIntValue(unsigned int flags, const char *variable_name, char ch_val)
{
    return this->WriteIntValue(flags,variable_name,(int)sizeof(char),true,&ch_val);
}

////////////////////////////////////////////////////////////////////////////////////////////////
bool CDataSrcSaver::WriteIntValue(unsigned int flags, const char *variable_name, unsigned char uc_val)
{
    return this->WriteIntValue(flags,variable_name,(int)sizeof(unsigned char),false,&uc_val);
}

////////////////////////////////////////////////////////////////////////////////////////////////
bool CDataSrcSaver::WriteIntValue(unsigned int flags, const char *variable_name, short i16_val)
{
    return this->WriteIntValue(flags,variable_name,(int)sizeof(short),true,&i16_val);
}

////////////////////////////////////////////////////////////////////////////////////////////////
bool CDataSrcSaver::WriteIntValue(unsigned int flags, const char *variable_name, unsigned short ui16_val)
{
    return this->WriteIntValue(flags,variable_name,(int)sizeof(unsigned short),false,&ui16_val);
}

////////////////////////////////////////////////////////////////////////////////////////////////
bool CDataSrcSaver::WriteIntValue(unsigned int flags, const char *variable_name, int i32_val)
{
    return this->WriteIntValue(flags,variable_name,(int)sizeof(int),true,&i32_val);
}

////////////////////////////////////////////////////////////////////////////////////////////////
bool CDataSrcSaver::WriteIntValue(unsigned int flags, const char *variable_name, unsigned int ui32_val)
{
    return this->WriteIntValue(flags,variable_name,(int)sizeof(unsigned int),false,&ui32_val);
}

////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////
bool CDataSrcSaver::WriteIntValue(unsigned int flags, const char *variable_name, int value_size,
                                    bool is_signed, const void *value)
{ 
    return WriteSingleValue(flags,value_size,is_signed,false,variable_name,value);
}

////////////////////////////////////////////////////////////////////////////////////////////////
bool CDataSrcSaver::WriteFltValue(unsigned int flags, const char *variable_name, float flt_val)
{
    return this->WriteFltValue(flags,variable_name,4,&flt_val);
}
////////////////////////////////////////////////////////////////////////////////////////////////
bool CDataSrcSaver::WriteDblValue(unsigned int flags, const char *variable_name, double dbl_val)
{ 
    return this->WriteFltValue(flags,variable_name,8,&dbl_val);
}

////////////////////////////////////////////////////////////////////////////////////////////////
// ToDo: Also able to convert to hexadecimal notation
bool CDataSrcSaver::WriteFltValue(unsigned int flags, const char *variable_name, int value_size, const void *value)
{
    return WriteSingleValue(flags,value_size,false,true,variable_name,value);
}

////////////////////////////////////////////////////////////////////////////////////////////////
bool CDataSrcSaver::WriteSingleValue(unsigned int flags, int value_size, bool is_signed,
                                        bool is_float, const char *variable_name, const void *value)
{
    //String that collects all data strings
    std::string strdata;
    strdata.reserve(2048);
    //Starts integer variable form new line and skipping one line
    strdata.append("\r\n\r\n");
    //Getting string that contains variable type and name
    std::string strvariable = GetVariableTypeAndName(flags,value_size,is_float,variable_name);
    strdata.append(strvariable); //Put into string data
    
    strdata.append(" = "); //Writing equals symbol
    
    if(flags & SRC_VALUE_HEXADECIMAL_NOTATION_FLAG) {
        std::string strvalue = GetStringValueHex(value_size, value);
        strdata.append(strvalue);
    }
    else {
        std::string strvalue = (is_float) ? (GetStringFltValue(value_size, value)) : 
                                            (GetStringIntValue(value_size, is_signed, value));
        strdata.append(strvalue);
    }
    
    strdata.append(1, ';');//End of putting strings into data string

    //Write variable data into file
    bool bresult = WriteToFile(strdata.c_str(),strdata.size());
    
    return bresult;
}

////////////////////////////////////////////////////////////////////////////////////////////////
bool CDataSrcSaver::WriteIntTable(unsigned int flags, const char *table_name, int value_size, bool is_signed, 
                                    int elem_count, int block_size, const void *data)
{
    if(table_name == nullptr) return false;
    if(elem_count < 2) return false;
    if(data == nullptr) return false;
    if(block_size > 1 && (elem_count % block_size)) return false;


    bool bhex = flags & SRC_VALUE_HEXADECIMAL_NOTATION_FLAG;

    const unsigned char *dataptr = reinterpret_cast<const unsigned char*>(data);

    std::string tabledatastr;
    if(block_size > 1) {
        int blockcnt = elem_count / block_size;
        for(int i = 0; i < blockcnt; i++) {
            std::string blockstr("{");
            for(int j = 0; j < block_size; j++) {
                std::string strval = (bhex) ? (GetStringValueHex(value_size,dataptr)) :
                                                 (GetStringIntValue(value_size,is_signed,dataptr));
                blockstr.append(strval);
                blockstr.append(",");
                dataptr += value_size;
            }
            blockstr.pop_back();
            blockstr.append("}, ");
            tabledatastr.append(blockstr);
        }
    }
    else {
        for(int i = 0; i < elem_count; i++)
        {
            std::string strval = (bhex) ? (GetStringValueHex(value_size,dataptr)) :
                                             (GetStringIntValue(value_size,is_signed,dataptr));
            tabledatastr.append(strval);
            tabledatastr.append(", ");
            dataptr += value_size;
        }
    }

    tabledatastr.pop_back();
    tabledatastr.pop_back();
    
    std::list<std::string> splitstrs = GetSplitStrings(tabledatastr);
    
    std::string newline("\r\n");
    WriteToFile(newline.c_str(), newline.size());

    for(auto it = splitstrs.begin(); it != splitstrs.end(); it++) {
        std::string strline = *it;
        if(m_bWriteTableOnce==false) {strline.insert(0,4,0x20);}
        strline.append("\r\n");
        WriteToFile(strline.c_str(), strline.size());
    }
    
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////
bool CDataSrcSaver::WriteFltTable(unsigned int flags, const char *table_name, int val_size, int elem_count, 
                                    int block_size, const void *data)
{
    return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////
//ToDo: split into multiple lines
bool CDataSrcSaver::WriteFileHeaderInfo(const char *description, const char *programme_info)
{
    if(mSaveStage != SourceStageBegin) return false; //Info in header had already been written or user already started writing tables data
    
    std::string strcommentline(MAX_LINE_LEN,'/');
    std::string strheader = strcommentline;
    strheader += "\r\n";
    strheader += "//  ";
    strheader += m_strFileName;
    strheader += FILE_EXTENSION;
    strheader += "\r\n//\r\n";
    
    //Write description in header file
    if(description != NULL) {
        
        strheader += "//  ";
        std::string strdesc(description);
        strheader += strdesc;
        strheader += "\r\n//\r\n";
    }
    
    //Write programme info
    if(programme_info != NULL) {
        strheader += "//  ";
        std::string strproginfo(PROGRAMME_INFO);
        strproginfo += programme_info;
        strheader += strproginfo;
        strheader += "\r\n//\r\n";
    }
    
    strheader += strcommentline;
    strheader += "\r\n";
    
    //Write header info 
    bool bresult = WriteToFile(strheader.c_str(),strheader.size());
    
    mSaveStage = SourceStageInfoWritten;
    
    return bresult;
}

////////////////////////////////////////////////////////////////////////////////////////////////
bool CDataSrcSaver::WriteBitmapData(unsigned int flags, const char *table_name, int *sizes, unsigned int count, 
                    const char *descriptions, const unsigned char *data)
{
    return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////         
bool CDataSrcSaver::WriteInitializerList(const char *class_name, const char *object_name)
{
    return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////
// Protected methods
////////////////////////////////////////////////////////////////////////////////////////////////
// Opening source header file for writing source code
bool CDataSrcSaver::OpenSrcFile(const char *path, const char *file_name)
{
    std::string strpath = (path==NULL) ? ("") : (path);
    
    if(!strpath.empty()) 
    {
        if(strpath.back() != char('/') || strpath.back() != char('\\'))
            strpath.push_back('/');
    }
    
    std::string strfilename = strpath + file_name;
    strfilename += FILE_EXTENSION;
    
    mFileStream = fopen(strfilename.c_str(),"wb");
    if(mFileStream == NULL)
        return false;
    
    return true;
}

/////////////////////////////////////////////////////////////////////int///////////////////////////
bool CDataSrcSaver::CloseSrcFile()
{
    if(mFileStream == NULL) return false;
    
    fclose(mFileStream);
    mFileStream = NULL;
    
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////
bool CDataSrcSaver::WriteToFile(const char *data, size_t size)
{
    size_t writtensize = fwrite(data, size, 1, mFileStream);
    return writtensize == size;
}

////////////////////////////////////////////////////////////////////////////////////////////////
std::string CDataSrcSaver::GetVariableTypeAndName(unsigned int flags, int value_size,
                                            bool is_float, const char *variable_name)
{
    //String for collecting variable type and name strings
    std::string strvariable;
    strvariable.reserve(256);
    
    //Remove SRC_VALUE_UNSIGNED_FLAG flag for float variable
    unsigned int newflags = (is_float) ? (flags ^ SRC_VALUE_UNSIGNED_FLAG) : (flags);
    std::string (CDataSrcSaver::*vartypefunc)(int) = (is_float) ? 
                                                        (&CDataSrcSaver::GetVariableFloatType) : 
                                                        (&CDataSrcSaver::GetVariableIntType);
    
    //Getting variables keywords
    std::string strkeywords = GetVariableKeywords(newflags);
    strvariable.append(strkeywords);
    
    //Getting variable type
    std::string strvartype = (*this.*vartypefunc)(value_size);
    strvariable.append(strvartype);
    
    //Getting variable name
    std::string strvarname = GetVariableName(flags, variable_name);
    strvariable.append(strvarname);
    
    return strvariable;
}

////////////////////////////////////////////////////////////////////////////////////////////////
std::string CDataSrcSaver::GetVariableKeywords(unsigned int flags)
{
    std::string strkeywords;
    if(flags & SRC_VALUE_STATIC_FLAG) {
        strkeywords.append(STATIC_KEYWORD);
        strkeywords.append(1, 0x20); //space character
    }
    if(flags & SRC_VALUE_CONST_FLAG) {
        strkeywords.append(CONST_KEYWORD);
        strkeywords.append(1, 0x20); //space character
    }
    if(flags & SRC_VALUE_UNSIGNED_FLAG) {
        strkeywords.append(UNSIGNED_KEYWORD);
        strkeywords.append(1, 0x20); //space character
    }
    
    return strkeywords;
}

////////////////////////////////////////////////////////////////////////////////////////////////
std::string CDataSrcSaver::GetVariableIntType(int value_size)
{
    std::string strvartype;
    if(value_size == 1) {
        strvartype.append(CHAR_KEYWORD);
        strvartype.append(1, 0x20); //space character
    }
    else if(value_size == 2) {
        strvartype.append(SHORT_KEYWORD);
        strvartype.append(1, 0x20); //space character
    }
    else if(value_size == 4) {
        strvartype.append(INT_KEYWORD);
        strvartype.append(1, 0x20); //space character
    }
    else if(value_size == 8) {
        strvartype.append(INT64_KEYWORD);
        strvartype.append(1, 0x20); //space character
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
std::string CDataSrcSaver::GetVariableFloatType(int value_size)
{
    std::string strvartype;
    if(value_size == 4) {
        strvartype.append(FLOAT_KEYWORD);
        strvartype.append(1, 0x20); //space character
    }
    else if(value_size == 8) {
        strvartype.append(DOUBLE_KEYWORD);
        strvartype.append(1, 0x20); //space character
    }
    else if(value_size > 8) {
        strvartype.append(LONG_DOUBLE_KEYWORD);
        strvartype.append(1, 0x20); //space character
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
std::string CDataSrcSaver::GetVariableName(unsigned int flags, const char *variable_name)
{
    std::string strvarname;
    if(flags & SRC_VALUE_FILENAME_FLAG) {
        strvarname.append(m_strFileName);
        strvarname.append(1, '_');
    }
    strvarname.append(variable_name);
    
    return strvarname;
}

////////////////////////////////////////////////////////////////////////////////////////////////
std::string CDataSrcSaver::GetStringIntValue(int value_size, bool is_signed, const void *value)
{
    std::string strvalue;
  
    if(value_size == 1) {
        if(is_signed) strvalue = std::to_string( int(*(char*)value) );
        else strvalue = std::to_string( unsigned(*(unsigned char*)value) );
    }
    else if(value_size == 2) {
        if(is_signed) strvalue = std::to_string( int(*(short*)value) );
        else strvalue = std::to_string( unsigned(*(unsigned short*)value) );
    }
    else if(value_size == 4) {
        if(is_signed) strvalue = std::to_string( *(int*)value );
        else strvalue = std::to_string( *(unsigned int*)value );
    }
    else if(value_size == 8) {
        if(is_signed) strvalue = std::to_string( *(long long*)value );
        else strvalue = std::to_string( *(unsigned long long*)value );
    }
    
    return strvalue;
}

////////////////////////////////////////////////////////////////////////////////////////////////
std::string CDataSrcSaver::GetStringFltValue(int value_size, const void *value)
{
    std::string strvalue;
    if(value_size == 4) {
        const float &fvalue = *(const float*)value;
        strvalue = std::to_string(fvalue);
    }
    else if(value_size == 8) {
        const double &dvalue = *(const double*)value;
        strvalue = std::to_string(dvalue);
    }
    
    return strvalue;
}
////////////////////////////////////////////////////////////////////////////////////////////////
std::string CDataSrcSaver::GetStringValueHex(int value_size, const void *value)
{
    std::string strvalue;
    strvalue.append("0x");
    
    const unsigned char *ucvaluetab = reinterpret_cast<const unsigned char*>(value);
    for(int i = value_size-1; i >= 0; i--) 
    {
        unsigned char uchsymbol = ucvaluetab[i];
        unsigned char valueidx2 = (uchsymbol >> 4) & 0xf;
        unsigned char valueidx1 = (uchsymbol) & 0xf;
        
        char leftsymbol = HexTab[valueidx2];
        char rightsymbol = HexTab[valueidx1];
        strvalue.append(1, leftsymbol);
        strvalue.append(1, rightsymbol);
    }
    
    return strvalue;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//Split data string in multiple lines
std::list<std::string> CDataSrcSaver::GetSplitStrings(const std::string &strdata)
{
    size_t maxsymbols = MAX_LINE_LEN - 8;//left border 4 spaces and right border 4 spaces
    std::list<std::string> splitstr;

    const std::string strsymbs({0x20,'\r','\n','\t',0});
    size_t infpos = std::string::npos;

    size_t pos1,searchpos,prevpos;
    bool searchnewline = true;
    SetNextPos(strdata,strsymbs,0,pos1,searchpos,prevpos);
    
    unsigned itercnt = 0;
    while(true)
    {
        size_t newpos = strdata.find_first_of(strsymbs,searchpos);
        if(newpos == std::string::npos) {
            size_t strlength = strdata.size() - pos1;
            bool breakline = strlength > maxsymbols && prevpos != infpos;
            std::string strline;
            if(breakline) {
                strline = strdata.substr(pos1,prevpos - pos1); 
                SetNextPos(strdata, strsymbs, prevpos, pos1,searchpos,prevpos);
            }
            else {
                strline = strdata.substr(pos1);
            }
            RemoveUslessChars(strline);
            splitstr.push_back(strline);
            if(breakline) continue;
           
            break;
        }
        
        char atchar = strdata.at(newpos);
        size_t strlength = newpos - pos1;
        bool newline = (atchar == '\r' || atchar == '\n');
        bool exceedmaxsymbs = (strlength > maxsymbols);
        bool breakline = exceedmaxsymbs || newline;
        if(breakline) {
            size_t lastpos = (exceedmaxsymbs && prevpos != infpos) ? (prevpos) : (newpos);

            std::string strline = strdata.substr(pos1,lastpos-pos1);
            RemoveUslessChars(strline);
            splitstr.push_back(strline);
            
            size_t nextpos = (!newline && prevpos != infpos) ? (prevpos) : (newpos);
            SetNextPos(strdata, strsymbs, nextpos, pos1,searchpos,prevpos);
            if(searchpos == infpos) break;
            
            continue;  
        }
        
        prevpos = newpos;
        searchpos = strdata.find_first_not_of(strsymbs,newpos);
        
        //also search between if there is no new line characters
        if(searchnewline) {
            size_t newlnpos = strdata.find_first_of({'\r','\n',0},newpos);
            if(newlnpos != infpos && newlnpos < searchpos) {
                searchpos = newlnpos;
            }
            searchnewline = (newlnpos != infpos);
        }
       
        itercnt++;
        if(itercnt > 0x7fffffff) {
            std::cerr << "Reached large amount of loop iterations\nLoop is in infinite cycle" << std::endl;
            break;
        }
    }

    return splitstr;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
// Private functions
/////////////////////////////////////////////////////////////////////////////////////////////////
void CDataSrcSaver::SetNextPos(const std::string &strdata, const std::string &symbs, size_t startpos, 
                    size_t &nextpos, size_t &searchpos, size_t &prevpos)
{
    nextpos = strdata.find_first_not_of(symbs,startpos);
    searchpos = nextpos;
    prevpos = std::string::npos;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
void CDataSrcSaver::RemoveUslessChars(std::string &strline)
{
    size_t tabpos = strline.find('\t');
    while(tabpos != std::string::npos) {
        strline[tabpos] = 0x20;
        tabpos = strline.find('\t');
    }
    
    size_t nlpos = strline.find({'\r','\n',0});
    while(nlpos != std::string::npos) {
        strline = strline.erase(nlpos,1);
        nlpos = strline.find({'\r','\n',0});
    }
    
    size_t spcpos = strline.find({0x20,0x20});
    while(spcpos != std::string::npos) {
        strline = strline.erase(spcpos,1);
        spcpos = strline.find({0x20,0x20});
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
