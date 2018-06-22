////////////////////////////////////////////////////////////////////////////////////////////////
//  DataSrcSaver.h
//	
//  Class for saving tables data and variables as C/C++ header
//	
////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __DATASOURCESAVER_H__
#define __DATASOURCESAVER_H__

#include <stdio.h>
#include <string>
#include <vector>
#include <list>
////////////////////////////////////////////////////////////////////////////////////////////////
// Write variables flags
#define SRC_VALUE_STATIC_FLAG                   0x1
#define SRC_VALUE_CONST_FLAG                    0x2
#define SRC_VALUE_UNSIGNED_FLAG                 0x4
#define SRC_VALUE_FILENAME_FLAG                 0x8
#define SRC_VALUE_HEXADECIMAL_NOTATION_FLAG     0x10
//#define SRC_VALUE_SCIENTIFIC_NOTATION_FLAG      0x20

////////////////////////////////////////////////////////////////////////////////////////////////
class CDataSrcSaver
{
public:
    CDataSrcSaver(const char *path, const char *file_name, bool inline_table);
    ~CDataSrcSaver();
    
    bool IsSrcFileOpened() const;
    
    bool WriteIntValue(unsigned int flags, const char *variable_name, char ch_val);
    bool WriteIntValue(unsigned int flags, const char *variable_name, unsigned char uc_val);
    bool WriteIntValue(unsigned int flags, const char *variable_name, short i16_val);
    bool WriteIntValue(unsigned int flags, const char *variable_name, unsigned short ui16_val);
    bool WriteIntValue(unsigned int flags, const char *variable_name, int i32_val);
    bool WriteIntValue(unsigned int flags, const char *variable_name, unsigned int ui32_val);
    bool WriteIntValue(unsigned int flags, const char *variable_name, int value_size, bool is_signed, const void *value);
    
    bool WriteFltValue(unsigned int flags, const char *variable_name, float flt_val);
    bool WriteDblValue(unsigned int flags, const char *variable_name, double dbl_val);
    bool WriteFltValue(unsigned int flags, const char *variable_name, int value_size, const void *value);
   
    bool WriteIntTable(unsigned int flags, const char *table_name, int value_size, bool is_signed, 
                        int elem_count, int block_size, const void *data);
    bool WriteFltTable(unsigned int flags, const char *table_name, int val_size, int elem_count, int block_size, const void *data);
    
    bool WriteFileHeaderInfo(const char *description, const char *programme_info);
    
    bool WriteBitmapData(unsigned int flags, const char *table_name, int *sizes, unsigned int count, 
                        const char *descriptions, const unsigned char *data);
                        
    bool WriteInitializerList(const char *class_name, const char *object_name);
    
protected:
    FILE *mFileStream;
    std::string m_strFileName;
    bool m_bWriteTableOnce;
    std::vector<std::string> m_VarNamesVec;
    
    enum SourceSavingStage {
        SourceStageBegin = 0,
        SourceStageInfoWritten = 1,
        SourceStageInitListWritten = 2,
    };
    
    SourceSavingStage mSaveStage;
    
    /////////////////////////////////////////////////////////////////////////////////////////////////
    bool OpenSrcFile(const char *path, const char *file_name);
    bool CloseSrcFile();
    bool WriteToFile(const char *data, size_t size);
    
    /////////////////////////////////////////////////////////////////////////////////////////////////
    bool WriteSingleValue(unsigned int flags, int value_size, bool is_signed,
                                        bool is_float, const char *variable_name, const void *value);
                                        
    /////////////////////////////////////////////////////////////////////////////////////////////////
    std::string GetVariableTypeAndName(unsigned int flags, int value_size,
                                        bool is_float, const char *variable_name);
    /////////////////////////////////////////////////////////////////////////////////////////////////
    std::string GetVariableKeywords(unsigned int flags);
    std::string GetVariableIntType(int value_size);
    std::string GetVariableFloatType(int value_size);
    std::string GetVariableName(unsigned int flags, const char *variable_name);
    /////////////////////////////////////////////////////////////////////////////////////////////////
    std::string GetStringIntValue(int value_size, bool is_signed, const void *value);
    std::string GetStringFltValue(int value_size, const void *value);
    std::string GetStringValueHex(int value_size, const void *value);
    /////////////////////////////////////////////////////////////////////////////////////////////////

    /////////////////////////////////////////////////////////////////////////////////////////////////
    //Split data string in multiple lines
    std::list<std::string> GetSplitStrings(const std::string &strdata);
    /////////////////////////////////////////////////////////////////////////////////////////////////

private:
    /////////////////////////////////////////////////////////////////////////////////////////////////
    inline void SetNextPos(const std::string &strdata, const std::string &symbs, size_t startpos, 
                    size_t &nextpos, size_t &searchpos, size_t &prevpos);
    /////////////////////////////////////////////////////////////////////////////////////////////////
    void RemoveUslessChars(std::string &strline);

};
////////////////////////////////////////////////////////////////////////////////////////////////

#endif //__DATASOURCESAVER_H__
