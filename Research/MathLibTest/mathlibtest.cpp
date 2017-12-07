#include <stdio.h>
#include "Base/Math/MathLib.h"

int main()
{
    printf("MathLib test programme\n");

    float f_pi = CMathConst<float>::MATH_PI;
    printf("flt PI = %.20f\n",f_pi);

    double d_pi = CMathConst<double>::MATH_PI;
    printf("dbl PI = %.20f\n",d_pi);
    
    int ival = 2;
    float fval = mitof(ival);
    printf("converted fval = %.6f\n",fval);

    float cval = 0.5f;
    float packedval = mpack01(cval);
    printf("packed value 01: %.6f\n",packedval);
    
    float fval1 = -0.25f;
    fval1 = mabs(fval1);
    
    int32t ival1 = -4;
    ival1 = mabs(ival1);
    
    float fval2 = mclamp(3.f,6.f,1.f);
    int ival2 = mclamp(-3,9,2);
    
    float ressqr = m_tsqrt(4.f);
    printf("sqrt = %.6f",ressqr);

    return 0;
}
