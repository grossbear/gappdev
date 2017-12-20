#include <stdio.h>
#include "Base/Math/MathLib.h"

int main()
{
    printf("MathLib test programm\n");
    
    CMVector2D<float> vec1(2.f,3.f);
    CMVector2D<float> vec2(4.5f,7.f);
    CMVector2D<float> vec3 = vec1 + vec2;
    
    CMVector2D<float> vec4;
    CMVec2Rotate(vec4,vec1,CMathConst<float>::MATH_PI);
    
    return 0;
}
