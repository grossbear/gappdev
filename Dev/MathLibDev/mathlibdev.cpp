#include <stdio.h>
#include "Base/Math/MathLib.h"

void PrintConsts();
void PrintIntToRealConv();
void PrintSqrtCalc();
void PrintTrigCalc();

///////////////////////////////////////////////////////////////////////////////////////
int main()
{
    printf("MathLib development programme\n");
    
    PrintConsts();
    PrintIntToRealConv();
    PrintSqrtCalc();
    PrintTrigCalc();
    
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////
void PrintConsts()
{
    printf("pi = %f\n",CMathConst<float>::MATH_PI);
}

///////////////////////////////////////////////////////////////////////////////////////
void PrintIntToRealConv()
{
    int ival = 3;
    float fval = mitof(ival);
    
    printf("Converted float val = %.6f\n",fval);
}

///////////////////////////////////////////////////////////////////////////////////////
void PrintSqrtCalc()
{
    float fval = 5.f;
    float sqval = msqrt(fval);
    float sqtabval = m_tsqrt(fval);
    
    printf("msqrt val = %.6f\n",sqval);
    printf("table sqrt val = %.6f\n",sqtabval);
}

///////////////////////////////////////////////////////////////////////////////////////
void PrintTrigCalc()
{
    float fval = 45.f;
    float tabsinval = m_tsinf(CMathConst<float>::MATH_DEG2RAD*fval);
    
    printf("sin table val = %.6f\n", tabsinval);
}