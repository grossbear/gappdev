#include <stdio.h>
#include "Base/Math/MathLib.h"

int main()
{
    printf("MathLib test programme\n");

    int32t i_val = 3;
    tfixed32<16> fx1(i_val);
    printf("fx1 = %d\n",fx1.get());
    
    float f_val = 5.f;
    tfixed32<16> fx2(f_val);
    printf("fx2 = %d\n",fx2.get());
    

    return 0;
}
