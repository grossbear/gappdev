// Perlin Noise Tables Generator

#include <iostream>
#include <string>
#include "Base/Math/MathLib.h"
#include "IntNumGen.h"
#include "PerlinTabsGen.h"


int main()
{
    std::cout << "Perlin Noise Tables Gen Programme\n";
    
    unsigned short seed = 565;
    
    std::cout << "cplusplus = " << __CPLUSPLUS_VER_ << std::endl;

    CPerlinTabsGen PerlinGenTabs(seed);
    
    const float *gradTable1D = PerlinGenTabs.GetGradientTable1D();
    const float *gradTable2D = PerlinGenTabs.GetGradientTable2D();
    
    for(int i = 0; i < 10; i+=2)
    {
        //float x = gradTable2D[i];
        //float y = gradTable2D[i+1];
        //std::cout << "vecx = " << x << ", vecy = " << std::endl;
        std::cout << "vecx = " << gradTable2D[i] << ", vecy = " << gradTable2D[i+1] << std::endl;
    }
    /*for(int i = 0; i < 10; i++)
    {
        float rndflt = PerlinGenTabs.GenRandomFloat();
        std::cout << "rnd flt = " << rndflt << std::endl;
    }*/
   
    
    
    return 0;
}
