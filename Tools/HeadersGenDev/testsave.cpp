// Test functions for creating data headers
#include <stdio.h>
#include "CommonSrc/DataSrcSaver.h"

void test_save_int_table()
{
    printf("saving test int table\n");

    const int tablesize = 50;
    int int_table[tablesize] = {0};
    for(int i = 0; i < tablesize; i++)
    {
        int_table[i] = i + 980;
    }

    unsigned int flags = 0;//SRC_VALUE_HEXADECIMAL_NOTATION_FLAG;
    const char table_name[] = {"int_table"};
    bool signedvalues = true;
    int blocksize = 1;

    CDataSrcSaver datasaver("headers","int_table",true);
    datasaver.WriteFileHeaderInfo("int table description","headersgen");
    datasaver.WriteIntTable(flags,table_name,sizeof(int),signedvalues,tablesize,blocksize,int_table);
}
