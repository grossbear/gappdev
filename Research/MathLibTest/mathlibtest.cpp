#include <stdio.h>
#include "Base/Math/MathLib.h"

int main()
{
    printf("MathLib test programm\n");

    tfixed32<16> fx1(5.f);
    tfixed32<16> fx1_sqrt = m_fxsqrt(fx1);
    printf("fx1 sqrt = %.5f\n",(float)fx1_sqrt);
    
    return 0;
}
