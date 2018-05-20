#include <stdio.h>
#include "Base/Math/MathLib.h"

void conv_to_half_print(float fval)
{
    uint16t half1 = mftoh(fval);
    //uint16t half2 = mftoh2(fval);
    
    fprintf(stderr, "----------------------------------------------------------\n");
    fprintf(stderr, "float val = %f\n",fval);
    fprintf(stderr, "half1 = %d\n",half1);
    //fprintf(stderr, "half2 = %d\n",half2);
}

///////////////////////////////////////////////////////////////////////////////////////
int main()
{
    printf("MathLib half type test programme\n");
   
    float one_half = 1.5f;
    conv_to_half_print(one_half);
    
    float minus_one = -1.0f;
    conv_to_half_print(minus_one);
    
    float fltval1 = 16.25f;
    conv_to_half_print(fltval1);
    
    float fltval2 = -16.25f;
    conv_to_half_print(fltval2);
    
    
    conv_to_half_print(CMathConst<float>::MATH_PI);
    conv_to_half_print(CMathConst<float>::MATH_2PI);
    conv_to_half_print(CMathConst<float>::MATH_RAD2DEG);
    conv_to_half_print(CMathConst<float>::MATH_E);
    
    conv_to_half_print(CMathConst<float>::MATH_SQRT_2);
    conv_to_half_print(CMathConst<float>::MATH_LN2);
    conv_to_half_print(CMathConst<float>::MATH_LN10);
    conv_to_half_print(CMathConst<float>::MATH_PHI);
    
    
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////
