///////////////////////////////////////////////////////////////////////////////////////
//  Trigonometry.cpp
//
//  Trigonometrical Functions
//  
//
///////////////////////////////////////////////////////////////////////////////////////

#include <math.h>

#include "Base/Common/PlatformTypes.h"

#include "MathConst.h"
#include "MathLibDefs.h"

#include "MathPrim.h"

#include "Trigonometry.h"


///////////////////////////////////////////////////////////////////////////////////////
// Triginometry Functions
///////////////////////////////////////////////////////////////////////////////////////

#define     TABLESIZE_SIN   256
#define     TWOPISCALE      ((float)TABLESIZE_SIN * ((float)CONST_1_2PI))

INTFLOAT        tsin [] = 
{
    #include "sin_table256.h"
};

const INTFLOAT  bias = {((23 + 127) << 23) + (1 << 22)};

///////////////////////////////////////////////////////////////////////////////////////
// Sinus Function Using Precalculated Table
float m_tsinf(float angle)
{
    ASSERT(angle >= -10000.0f && angle <= 10000.0f);

    INTFLOAT fi;    
    fi.f = angle * TWOPISCALE + bias.f;
    int32t i = fi.i & (TABLESIZE_SIN - 1);
    return tsin[i].f;
}

///////////////////////////////////////////////////////////////////////////////////////
// Cosinus Function Using Precalculated Table
float m_tcosf(float angle)
{
    ASSERT(angle >= -10000.0f && angle <= 10000.0f);

    INTFLOAT  fi;
    fi.f = angle * TWOPISCALE + bias.f;
    int32t i = (fi.i + (TABLESIZE_SIN/4)) & (TABLESIZE_SIN - 1);
    return tsin[i].f;
}

///////////////////////////////////////////////////////////////////////////////////////
// SinCos Function Using Precalculated Table
void m_tsincosf(float angle, float &sin_val, float &cos_val)
{
    ASSERT(angle >= -10000.0f && angle <= 10000.0f);

    INTFLOAT fi;    
    fi.f = angle * TWOPISCALE + bias.f;

    int i = fi.i & (TABLESIZE_SIN - 1);
    sin_val = tsin[i].f;

    i = (fi.i + (TABLESIZE_SIN/4)) & (TABLESIZE_SIN - 1);
    cos_val = tsin[i].f;
}
///////////////////////////////////////////////////////////////////////////////////////
