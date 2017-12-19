#include <stdio.h>
#include "Base/Math/MathLib.h"

int main()
{
    printf("MathLib test programm\n");
    
    const int bits = 16;

    tfixed32<bits> fx1(5);
    
    /*uint32t sqrbits = (uint32t)(bits >> 1);
    sqrbits = (0x1) << sqrbits;
    printf("sqrbits = %u\n",sqrbits);*/
    
    tfixed32<16> fx1_sqrt = m_xsqrt(fx1);
    float fval1 = (float)fx1_sqrt;

    printf("fval1 = %.6f\n",fval1);
    
    /*int32t fx1_sqrt = m_xsqrt(fx1);
    printf("fx1 sqrt = %d\n",fx1_sqrt);*/
    
    return 0;
}
