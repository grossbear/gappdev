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

#include "tfixed32.h"
#include "tfixed64.h"
#include "thalf.h"

#include "MathPrim.h"

#include "Trigonometry.h"


///////////////////////////////////////////////////////////////////////////////////////
// Triginometry Functions
///////////////////////////////////////////////////////////////////////////////////////

#define     TABLESIZE_SIN       256
#define     FIXED_TABLE_SIZE    1024
#define     TWOPISCALE          ((float)TABLESIZE_SIN * ((float)CONST_1_2PI))

const INTFLOAT sinus_tab [TABLESIZE_SIN] = 
{
    #include "sin_table256.h"
};
///////////////////////////////////////////////////////////////////////////////////////
const uint32t fxcos_tab [FIXED_TABLE_SIZE+1] = 
{
    #include "fxcos_table1024.h"
};
///////////////////////////////////////////////////////////////////////////////////////
const uint32t fxsin_tab [FIXED_TABLE_SIZE+1] =
{
    #include "fxsin_table1024.h"
};
///////////////////////////////////////////////////////////////////////////////////////
const uint32t fxtan_tab [FIXED_TABLE_SIZE+1] =
{
    #include "fxtan_table1024.h"
};
///////////////////////////////////////////////////////////////////////////////////////
const uint32t fxacos_tab [FIXED_TABLE_SIZE+1] =
{
    #include "fxacos_table1024.h"
};
///////////////////////////////////////////////////////////////////////////////////////
const ubyte acosdeg_tab [101] = 
{
    #include "acosdeg_table.h"
};
///////////////////////////////////////////////////////////////////////////////////////
const INTFLOAT bias = {((23 + 127) << 23) + (1 << 22)};

///////////////////////////////////////////////////////////////////////////////////////
// Sinus Function Using Precalculated Table
float m_sinus_tabf(float angle)
{
    ASSERT(angle >= -10000.0f && angle <= 10000.0f);

    INTFLOAT fi;    
    fi.f = angle * TWOPISCALE + bias.f;
    int32t i = fi.i & (TABLESIZE_SIN - 1);
    return sinus_tab[i].f;
}

///////////////////////////////////////////////////////////////////////////////////////
// Cosinus Function Using Precalculated Table
float m_tcosf(float angle)
{
    ASSERT(angle >= -10000.0f && angle <= 10000.0f);

    INTFLOAT  fi;
    fi.f = angle * TWOPISCALE + bias.f;
    int32t i = (fi.i + (TABLESIZE_SIN/4)) & (TABLESIZE_SIN - 1);
    return sinus_tab[i].f;
}

///////////////////////////////////////////////////////////////////////////////////////
// SinCos Function Using Precalculated Table
void m_tsincosf(float angle, float &sin_val, float &cos_val)
{
    ASSERT(angle >= -10000.0f && angle <= 10000.0f);

    INTFLOAT fi;    
    fi.f = angle * TWOPISCALE + bias.f;

    int i = fi.i & (TABLESIZE_SIN - 1);
    sin_val = sinus_tab[i].f;

    i = (fi.i + (TABLESIZE_SIN/4)) & (TABLESIZE_SIN - 1);
    cos_val = sinus_tab[i].f;
}

///////////////////////////////////////////////////////////////////////////////////////
// Sinus Function Using Precalculated Table
tfixed32<16> m_tsinx(const tfixed32<16> &x)
{
    /*
    TFix32<16> fxval = (x.Raw() < 0) ? (CMath::fxPI - x) : (x);
    fxval /= CMath::fxTWOPI;
    fxval &= 0x0000FFFF;
    TFix32<16> fx_ent;
    fx_ent.Raw(FIXED_TABLE_SIZE-1);
    fxval *= fx_ent;

    int tabpos = fxval.Raw();
    int tabval = fxsin_tab[tabpos];

    fxval.Raw(tabval);
    return fxval;
    */
    
    //CMathConst< tfixed32<16> >::MATH_2PI; - not compiling
    //ToDo: make it compile
    
    /*static const tfixed32<16> fx2pi(CONST_2PI);
    tfixed32<16> fxval = (*(int32t*)x < 0) ? (fx2pi - x) : (x);
    fxval /= fx2pi;
    fxval &= 0x0000FFFF; //fraction part
    tfixed32<16> fxent;
    *(int32t*)fxent = FIXED_TABLE_SIZE-1;
    fxval *= fxent;
    
    int32t tabidx = *(int32t*)fxval;
    int32t intval = fxsin_tab[tabidx];
    
    tfixed32<16> out;
    *(int32t*)out = intval;
    
    return out;*/
   
   return tfixed32<16>(0);
}

///////////////////////////////////////////////////////////////////////////////////////
// Cosinus Function Using Precalculated Table
tfixed32<16> m_tcosx(const tfixed32<16> &x)
{
    /*
    TFix32<16> fxval = (x.Raw() < 0) ? (-x) : (x);
    fxval /= CMath::fxTWOPI;
    fxval &= 0x0000FFFF;
    TFix32<16> fx_ent;
    fx_ent.Raw(FIXED_TABLE_SIZE-1);
    fxval *= fx_ent;

    int tabpos = fxval.Raw();
    int tabval = fxcos_tab[tabpos];

    fxval.Raw(tabval);
    return fxval;
    */
    return tfixed32<16>(0);
}

///////////////////////////////////////////////////////////////////////////////////////
// Arcus Cosinus Function Using Precalculated Table
tfixed32<16> m_tacosx(const tfixed32<16> &x)
{
    /*
    TFix32<16> fxval = x + TFix32<16>(1);
    fxval >>= 1;
    fxval &= 0x0000FFFF;
    TFix32<16> fx_ent;
    fx_ent.Raw(FIXED_TABLE_SIZE-1);
    fxval *= fx_ent;

    int tabpos = fxval.Raw(); 
    int tabval = fxacos_tab[tabpos];
    fxval.Raw(tabval);

    return fxval;
    */
    
    return tfixed32<16>(0);
}

///////////////////////////////////////////////////////////////////////////////////////
// SinCos Function Using Precalculated Table
void m_tsincosx(const tfixed32<16> &angle, tfixed32<16> &sin_val, tfixed32<16> &cos_val)
{
    /*
    sina = (angle.Raw() < 0) ? (CMath::fxPI - angle) : (angle);
    sina /= CMath::fxTWOPI;
    sina &= 0x0000FFFF;

    cosa = (angle.Raw() < 0) ? (-angle) : (angle);
    cosa /= CMath::fxTWOPI;
    cosa &= 0x0000FFFF;

    TFix32<16> fx_ent;
    fx_ent.Raw(FIXED_TABLE_SIZE-1);

    sina *= fx_ent;
    int tabpos = sina.Raw();
    int tabval = fxsin_tab[tabpos];
    sina.Raw(tabval);

    cosa *= fx_ent;
    tabpos = cosa.Raw();
    tabval = fxcos_tab[tabpos];
    cosa.Raw(tabval);
    */
}

///////////////////////////////////////////////////////////////////////////////////////
// Arcus Cosinus Table Approxiamtion In Degrees
int32t m_tacosdeg(float f)
{
    int32t index = mftoi(f * 100);
    if(index > 100) index = 100;
    ubyte degval = acosdeg_tab[index];
    return (uint32t)degval;
}
///////////////////////////////////////////////////////////////////////////////////////
int32t m_tacosdeg(const tfixed32<16> &x)
{
    static const tfixed32<16> max_idx(100);
    tfixed32<16> fx_index = max_idx * x;
    if( fx_index > max_idx) fx_index = max_idx;
    int32t index = (int32t)fx_index;
    ubyte degval = acosdeg_tab[index];
    return (uint32t)degval;
}
