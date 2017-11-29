#include <stdio.h>
#include "Base/Math/MathLib.h"

int main()
{
    printf("MathLib test programme\n");

    float f_pi = CMathConsts<float>::MATH_PI;
    printf("flt PI = %.20f\n",f_pi);

    double d_pi = CMathConsts<double>::MATH_PI;
    printf("dbl PI = %.20f\n",d_pi);
    
    int ival = 2;
    float fval = mitof(ival);
    printf("converted fval = %.6f\n",fval);

    return 0;
}
