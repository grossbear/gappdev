//Numeric Limits main programme
#include <stdio.h>


#include "Base/Math/MathLib.h"

#include "arithmetic_type_num_limits.h"

////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    printf("Numeric Limits Development Programme\n");
    
    print_arithmetic_type_numeric_limits<int>();
    print_arithmetic_type_numeric_limits<float>();
    print_arithmetic_type_numeric_limits<double>();
    
    //size_t lngdblsize = sizeof(long double);
    //printf("long double size: %lu\n", lngdblsize);
    
    //size_t szt = sizeof(size_t);
    //printf("size_t size: %lu\n", szt);

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////







