// Perlin Noise Tables Generator

#include <iostream>
#include <string>
#include "Base/Math/MathLib.h"
#include "PerlinTabsGen.h"



int main()
{
    std::cout << "Perlin Noise Tables Gen Programme\n";
    
    int x = 568;
    float genval = mprng(x);
     
    std::cout << "generated value: " << genval << std::endl;
    
    std::string strval = std::to_string(genval);
    std::cout << "gen value string: " << strval << std::endl;
    
    unsigned short seed = 65;
    CPerlinTabsGen TabsGen(seed);
    
    std::cout << "cplusplus = " << __CPLUSPLUS_VER_ << std::endl;

    
    /*int val1 = TabsGen.CalcNextPositionValue();
    int val2 = TabsGen.CalcNextPositionValue();
    int val3 = TabsGen.CalcNextPositionValue();
    int val4 = TabsGen.CalcNextPositionValue();
    int val5 = TabsGen.CalcNextPositionValue();
    int val6 = TabsGen.CalcNextPositionValue();
    
    std::cout << "val1 = " << val1 << std::endl;
    std::cout << "val2 = " << val2 << std::endl;
    std::cout << "val3 = " << val3 << std::endl;
    
    std::cout << "val4 = " << val4 << std::endl;
    std::cout << "val5 = " << val5 << std::endl;
    std::cout << "val6 = " << val6 << std::endl;*/
    

    return 0;
}
