#include <stdio.h>
#include "CommonSrc/DataSrcSaver.h"

void test_save_int_table()
{
    printf("saving test int table\n");
    CDataSrcSaver datasaver("headers","int_table",false);
    datasaver.WriteFileHeaderInfo("int table description","headersgen");
    datasaver.WriteIntTable(0,"int_tab",0,true,100,1,"data");
}
