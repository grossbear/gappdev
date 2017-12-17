#include <stdio.h>
#include "Base/Math/MathLib.h"

int main()
{
    printf("MathLib test programm\n");

    int32t i_val = 3;
    tfixed32<16> fx1(i_val);
    printf("fx1 = %d\n",*(int32t*)fx1);
    
    float f_val = 5.25f;
    tfixed32<16> fx2(f_val);
    printf("fx2 = %d\n",*(int32t*)fx2);

    return 0;
}
