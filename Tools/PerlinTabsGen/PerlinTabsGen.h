////////////////////////////////////////////////////////////////////////////////////////////////
//	PerlinTabsGen.h 
//	
//	Class generates gradient tables and permutation table that is used to generate Perlin noise.
//	
////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _PERLIN_NOISE_TABLES_GEN_CLASS_H_
#define _PERLIN_NOISE_TABLES_GEN_CLASS_H_

#ifndef _PLATFORMTYPES_H_
typedef unsigned char   ubyte;
typedef unsigned short  uint16t;
#endif //_PLATFORMTYPES_H_


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
    
    int CalcNextPositionValue();

private:
    void AllocTabels();
    void DeallocTables();
    void ResetPointers();
    
    void InitSeriesValues(unsigned short seed);
    
    void GenerateLookUpTables();
    
    //Gradient tables
    float               *mGradientTable1D;
    CMVector2D<float>   *mGradientTable2D;
    CMVector3D<float>   *mGradientTable3D;
    CMVector4D<float>   *mGradientTable4D;
    //Permutation table
    ubyte               *mPermutationTable;
    
    int mFibbVal1;
    int mFibbVal2;
    int mSumVal1;
    int mSumVal2;
};
////////////////////////////////////////////////////////////////////////////////////////////////

#endif //_PERLIN_NOISE_TABLES_GEN_CLASS_H_