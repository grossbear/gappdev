////////////////////////////////////////////////////////////////////////////////////////////////
//	PerlinTabsGen.h 
//	
//	Class generates gradient tables and permutation table that is used to generate Perlin noise.
//	
////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _PERLIN_NOISE_TABLES_GEN_CLASS_H_
#define _PERLIN_NOISE_TABLES_GEN_CLASS_H_

#include "IntNumGen.h"

#ifndef _PLATFORMTYPES_H_
typedef unsigned char   ubyte;
typedef unsigned short  uint16t;
#endif //_PLATFORMTYPES_H_

#define MAX_FUNC_PTR_TAB_SIZE 9


////////////////////////////////////////////////////////////////////////////////////////////////
class CPerlinTabsGen
{
public:
    CPerlinTabsGen(unsigned short seed);
    ~CPerlinTabsGen();
    
    const float *GetGradientTable1D() const;
    const float *GetGradientTable2D() const;
    const float *GetGradientTable3D() const;
    const float *GetGradientTable4D() const;
    const ubyte *GetPermutationTable() const;
    int GetTablesSize() const;
    
private:
    void AllocTabels();
    void DeallocTables();
    void ResetPointers();
    
    void InitFltGenPtrsTab();
    void ShuffleFltGenPtrs(unsigned short seed);
    
    float GenRandomFloat();
    void GenerateLookUpTables();
    
    //Gradient tables
    float               *mGradientTable1D;
    CMVector2D<float>   *mGradientTable2D;
    CMVector3D<float>   *mGradientTable3D;
    CMVector4D<float>   *mGradientTable4D;
    //Permutation table
    ubyte               *mPermutationTable;
    
    CIntNumGen          mIntNumGen;
    
private:
    float RndFloatGen1();
    float RndFloatGen2();
    float RndFloatGen3();
    float RndFloatGen4();
    
    //float (CPerlinTabsGen::*fptr)(void);
    
    float (CPerlinTabsGen::*m_fpRndFltGen[MAX_FUNC_PTR_TAB_SIZE])(void);
    int mPtrTabIndex;
    
};
////////////////////////////////////////////////////////////////////////////////////////////////

#endif //_PERLIN_NOISE_TABLES_GEN_CLASS_H_