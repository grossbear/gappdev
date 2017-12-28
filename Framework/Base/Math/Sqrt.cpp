///////////////////////////////////////////////////////////////////////////////////////
//  Sqrt.cpp
//
//  Square Root Function Calculation Methods
//  
//
///////////////////////////////////////////////////////////////////////////////////////

#include <math.h>

#include "Base/Common/PlatformTypes.h"

#include "MathConst.h"
#include "MathLibDefs.h"
#include "tfixed32.h"

#include "MathPrim.h"

#include "Sqrt.h"

///////////////////////////////////////////////////////////////////////////////////////
// Square Root Table Values
///////////////////////////////////////////////////////////////////////////////////////
INTFLOAT        tsqrt [] = 
{
    #include "sqrt_table256.h"
};

///////////////////////////////////////////////////////////////////////////////////////
float m_tsqrt(float f)
{
    ASSERT(!mless0(f));

    INTFLOAT fi;    
    fi.f = f;
    int32t n = fi.i;
    int32t e = (n >> 1) & 0x3f800000;
    n = (n >> 16) & 0xff;
    fi.i = e + tsqrt[n].i;

    return fi.f;
}

///////////////////////////////////////////////////////////////////////////////////////
float m_rfsqrt(float number)
{
    ASSERT(!mless0(number));
    
    int32t i;
	float x2, y;
	const float threehalfs = 1.5f;

	x2 = number * 0.5f;
	y  = number;
	i  = * ( int32t * ) &y;		            // evil floating point bit level hacking
	i  = 0x5f3759df - ( i >> 1 );               // 
	y  = * ( float * ) &i;
	y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
	y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

	return y;
}

///////////////////////////////////////////////////////////////////////////////////////
float m_fsqrt(float number)
{
    ASSERT(!mless0(number));
    
    int32t i;
	float x2, y;
	const float threehalfs = 1.5f;
    
    /*
        float xhalf = 0.5f * f;
        int i = *(int*)&f; 
        i = 0x5f3759d5 - (i >> 1); 
        f = *(float*)&i; 
        f = f*(1.5f - xhalf*f*f); 
        return f;
    */

	x2 = number * 0.5f;
	y  = number;
	i  = * ( int32t * ) &y;		            // evil floating point bit level hacking
	i  = 0x5f3759df - ( i >> 1 );               // 
	y  = * ( float * ) &i;
	y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
	y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

	return 1.0f/y;
}

///////////////////////////////////////////////////////////////////////////////////////
float m_asqrt(float x)
{
    int32t iter = 12;

    float sum = 1.0f;
    float val = 1.0f;

    float nfact1 = 1.0f;
    float factVal1 = 1.0f;
    float factVal2 = 1.0f;
    float n = 0.0f;
    float cnstVal2 = 1.0f;


    for(int32t i = 1; i < iter; i++)
    {
        float tmp1, tmp2;
        val = val*x;
        tmp1 = (i%2)?(-1.0f):(1.0f);

        factVal1 *= nfact1;
        nfact1 += 1.0f;
        factVal1 *= nfact1;
        nfact1 += 1.0f;
        
        n += 1.0f;
        tmp2 = 1.0f - 2.0f*n;
        factVal2 *= n;
        cnstVal2 *= 4.0f;

        sum = sum + (tmp1*factVal1)/(tmp2*factVal2*factVal2*cnstVal2)*val;
    }

    return sum;
}

///////////////////////////////////////////////////////////////////////////////////////
uint32t m_isqrt(uint32t x)
{
//
// this follows http://www.finesse.demon.co.uk/steven/sqrt.html
// 4 cycle/bit C routine
// Wilco Dijkstra also provided the following C code which produces optimised ARM code which takes 4 cycles per bit:

// fixed-point square root
#define ITER1(N) \
    tr = root + (1 << (N)); \
    if (n >= tr << (N))   \
    {   n -= tr << (N);   \
        root |= 2 << (N); \
    }

    unsigned int root;
    unsigned int tr;
    unsigned int n = x;
    root = 0;
        
    ITER1 (15);    ITER1 (14);    ITER1 (13);    ITER1 (12);
    ITER1 (11);    ITER1 (10);    ITER1 ( 9);    ITER1 ( 8);
    ITER1 ( 7);    ITER1 ( 6);    ITER1 ( 5);    ITER1 ( 4);
    ITER1 ( 3);    ITER1 ( 2);    ITER1 ( 1);    ITER1 ( 0);
    
    return root>>1;
#undef ITER1   
}

///////////////////////////////////////////////////////////////////////////////////////
uint64t m_isqrt(uint64t x)
{
#define ITER1(N) \
    tr = root + (1LL << (N)); \
    if (n >= tr << (N))   \
    {   n -= tr << (N);   \
        root |= 2LL << (N); \
    }
    unsigned long long root;
    unsigned long long tr;
    unsigned long long n = x;
    root = 0LL;

    ITER1 (31LL);    ITER1 (30LL);    ITER1 (29LL);    ITER1 (28LL);
    ITER1 (27LL);    ITER1 (26LL);    ITER1 (25LL);    ITER1 (24LL);
    ITER1 (23LL);    ITER1 (22LL);    ITER1 (21LL);    ITER1 (20LL);
    ITER1 (19LL);    ITER1 (18LL);    ITER1 (17LL);    ITER1 (16LL);
        
    ITER1 (15LL);    ITER1 (14LL);    ITER1 (13LL);    ITER1 (12LL);
    ITER1 (11LL);    ITER1 (10LL);    ITER1 ( 9LL);    ITER1 ( 8LL);
    ITER1 ( 7LL);    ITER1 ( 6LL);    ITER1 ( 5LL);    ITER1 ( 4LL);
    ITER1 ( 3LL);    ITER1 ( 2LL);    ITER1 ( 1LL);    ITER1 ( 0LL);
      
    return root>>1LL;
#undef ITER1   
}

///////////////////////////////////////////////////////////////////////////////////////