////////////////////////////////////////////////////////////////////////////////////////////////
//	IntNumGen.cpp
//	
//	Class generates integer value in ascending and descending order
//	
////////////////////////////////////////////////////////////////////////////////////////////////

#include "Base/Math/MathLib.h"
#include "IntNumGen.h"

#define BASE_VAL1   1
#define BASE_VAL2   2
#define MAX_BASE_VAL 1073741824
#define PRIM_DEF_VAL 11
#define MIN_CHECK_VALUE 10

////////////////////////////////////////////////////////////////////////////////////////////////
CIntNumGen::CIntNumGen(uint16t seed):
mBaseValue1(BASE_VAL1),
mSequenceValue1(BASE_VAL1),
mBaseValue2(BASE_VAL2),
mSequenceValue2(BASE_VAL2)
{
    InitSeriesValues(seed);
}

////////////////////////////////////////////////////////////////////////////////////////////////
int CIntNumGen::GenNewIntValue()
{
    int NextSequenceValue = mSequenceValue1 + mSequenceValue2;
    int GenValue = mSequenceValue1 + mAddValue1;
    
    if(NextSequenceValue < 0 && mSequenceValue2 > 0)
    {
        mSequenceValue1 = -mBaseValue1;
        mSequenceValue2 = -mBaseValue2;
        NextSequenceValue = mSequenceValue1 + mSequenceValue2;
        GenValue = mSequenceValue1 + mAddValue1;
    }
    else if(NextSequenceValue > 0 && mSequenceValue2 < 0)
    {
        mBaseValue1++;
        mBaseValue2++;
        mSequenceValue1 = mBaseValue1;
        mSequenceValue2 = mBaseValue2;
        NextSequenceValue = mSequenceValue1 + mSequenceValue2;
        GenValue = mSequenceValue1 + mAddValue1;
        
        if(mBaseValue2 > MAX_BASE_VAL) {
            mBaseValue1 = BASE_VAL1;
            mBaseValue2 = BASE_VAL2;
        }
    }
    
    mSequenceValue1 = mSequenceValue2;
    mSequenceValue2 = NextSequenceValue;
    
    int tmp = mAddValue1;
    mAddValue1 = mAddValue2;
    mAddValue2 = tmp;
    
    return GenValue;
}

////////////////////////////////////////////////////////////////////////////////////////////////
int CIntNumGen::GetSequenceValue1() const
{
    return mSequenceValue1;
}

////////////////////////////////////////////////////////////////////////////////////////////////
void CIntNumGen::InitSeriesValues(uint16t seed)
{
    mAddValue1 = seed;
    mAddValue2 = seed >> 1;
    
    //find nearest prim number
    uint32t prim = (mAddValue1 < MIN_CHECK_VALUE) ? (PRIM_DEF_VAL) : (mAddValue1++);
    while(!misprim(prim))
        prim++;
    
    mAddValue1 = mAddValue1 & prim;
}

////////////////////////////////////////////////////////////////////////////////////////////////