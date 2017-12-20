///////////////////////////////////////////////////////////////////////////////////////
//  Sqrt.h
//
//  Square Root Function Calculation Methods Declarations
//  
//
///////////////////////////////////////////////////////////////////////////////////////

#ifndef _SQRT_H_
#define _SQRT_H_

M_FORCEINL float msqrt(float x);
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double msqrt(double x);

float m_tsqrt(float x);
///////////////////////////////////////////////////////////////////////////////////////
float m_rfsqrt(float x);
///////////////////////////////////////////////////////////////////////////////////////
float m_fsqrt(float x);
///////////////////////////////////////////////////////////////////////////////////////
float m_asqrt(float x);
///////////////////////////////////////////////////////////////////////////////////////
uint32t m_isqrt(uint32t x);
///////////////////////////////////////////////////////////////////////////////////////
uint64t m_isqrt(uint64t x);
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed32<bits> m_ifxsqrt(tfixed32<bits> x);
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed32<bits> m_xsqrt(tfixed32<bits> x);

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float msqrt(float x)
{
#ifdef CMATH_TABLE_SQRT
    return m_tsqrt(x);
#elif CMATH_FAST_SQRT
    return 1.0f/m_rfsqrt(x);
#else
    return sqrtf(x);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double msqrt(double x)
{
    return sqrt(x);
}

///////////////////////////////////////////////////////////////////////////////////////
/*
TFix32<16> CMath::sqrt(TFix32<16> val)
{
    TFix32<16> root(0);
    TFix32<16> temp, squaretemp;
    TFix32<16> bits(128);

    if(val < TFix32<16>(1))
    {    
        bits = TFix32<16>(1);
        bits >>= 1;
    }

    while(bits.Raw())
    {
        temp = root | bits;

        if((squaretemp = temp*temp) <= val)
        {
            root = temp;

            if (squaretemp == val)
			{
				return root;
			}
        }

        bits >>= 1;
    }

    return root;
}
*/

template <int bits>
tfixed32<bits> m_ifxsqrt(tfixed32<bits> val)
{
    tfixed32<bits> root(int32t(0));
    tfixed32<bits> temp, squaretemp;
    tfixed32<bits> bts(int32t(128));
    
    static const tfixed32<bits> one(int32t(1));
    
    if(val < one)
    {
        bts = one;
        bts >>= 1;
    }
    
    while(*((int32t*)bts))
    {
        temp = root | bts;
        
        if((squaretemp = temp*temp) <= val)
        {
            root = temp;

            if (squaretemp == val)
			{
				return root;
			}
        }

        bts >>= 1;
    }
    
    return root;
}

///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed32<bits> m_xsqrt(tfixed32<bits> x)
{
    uint32t offbits = (uint32t)(bits >> 1);
    uint32t sqrmult = (0x1)<<offbits;
     
    uint32t uval = (uint32t)*(int32t*)x;
    
    uint32t uvalsqrt = m_isqrt(uval);
    uvalsqrt *= sqrmult;
    
    tfixed32<bits> sqrtxval;
    int32t *ptrsqrtval = (int32t*)sqrtxval;
    *ptrsqrtval = (int32t)uvalsqrt;
    
    return sqrtxval;
}

///////////////////////////////////////////////////////////////////////////////////////

#endif //_SQRT_H_