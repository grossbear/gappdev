#include <stdio.h>
#include "Base/Math/MathLib.h"

int main()
{
    printf("MathLib test programm\n");

    int32t i_val = 3;
    tfixed32<16> fx1(i_val);
    printf("raw fx1 = %d\n",*(int32t*)fx1);
    
    float f_val = 5.25f;
    tfixed32<16> fx2(f_val);
    printf("raw fx2 = %d\n",*(int32t*)fx2);
    
    tfixed32<16> fx3 = fx1 + fx2;
    tfixed32<16> fx4 = fx1 * fx2;
    
    printf("fx3 = %.6f\n",(float)fx3);
    printf("fx4 = %.6f\n",(float)fx4);
    
    

    return 0;
}
