///////////////////////////////////////////////////////////////////////////////////////
//  MathFunc.h
//
//  Some Mathematics Primary Functions Definitions
//  Created: 11-03-2007
//  Refactor: 06-10-2017
//
///////////////////////////////////////////////////////////////////////////////////////

#include <math.h>

#include "Base/Common/PlatformTypes.h"

#include "MathConsts.h"
#include "MathLibDefs.h"

#ifdef MATH_PRIM_SSE 
#include <xmmintrin.h>
#include <memory.h>
#endif

#include "MathPrim.h"

// INTORFLOAT Union For Easy Access To Bits Of A Float.
typedef union tINTFLOAT
{
    int32t  i;          // As Integer
    float   f;          // As Float
    struct              // As Bit Fields
    {
        unsigned int    sign:1;
        unsigned int    biasedexponent:8;
        unsigned int    significand;
    }
    bits;
}
INTFLOAT;

// Bias Constant Used For Fast Conversions Between Int And Float. First Element
// In INTORFLOAT Union Is Integer -- We Are Storing Biased Exponent 23, Mantissa .1, Which
// Is Equivalent To 1.5 x 2^23. 
const INTFLOAT  bias = {((23 + 127) << 23) + (1 << 22)};

///////////////////////////////////////////////////////////////////////////////////////
// Converting Functions From Integer To Float Type And Vice Versa
///////////////////////////////////////////////////////////////////////////////////////
M_API int32t mftoi(float f)
{
    ASSERT(f >= -4194304.0f && f <= 4194304.0f);

    INTFLOAT fi;    
    fi.f = f + bias.f;
    return fi.i - bias.i;
}
///////////////////////////////////////////////////////////////////////////////////////
M_API float mitof(int32t i)
{
    ASSERT(i >= -4194304 && i <= 4194304);

    INTFLOAT fi;    
    fi.i = i + bias.i;
    return fi.f - bias.f;
}
///////////////////////////////////////////////////////////////////////////////////////