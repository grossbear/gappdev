#include <stdio.h>
#include "Base/Math/MathLib.h"

int main()
{
    printf("MathLib test programm\n");

    float fpi = CMathConst<float>::MATH_PI;
    printf("float pi = %.6f\n",fpi);
    
    uint16t hpival = mftoh(fpi);
    printf("half pi = %u\n",hpival);
    
    float fpi_from_h = mhtof(hpival);
    printf("float pi from half = %.6f\n",fpi_from_h);
    
    return 0;
}
