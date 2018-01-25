////////////////////////////////////////////////////////////////////////////////////////////////
//	IntNumGen.h 
//	
//	Class generates integer value in ascending and descending order
//	
////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __INTNUMGEN_H__
#define __INTNUMGEN_H__

#ifndef _PLATFORMTYPES_H_
typedef unsigned char   ubyte;
typedef unsigned short  uint16t;
#endif //_PLATFORMTYPES_H_

class CIntNumGen
{
public:   
    CIntNumGen(uint16t seed);
    
    int GenNewIntValue();
    
    int GetSequenceValue1() const;
    
private:
    void InitSeriesValues(uint16t seed);

    // Base value that starts number generation process
    int mBaseValue1;
    int mBaseValue2;
    
    // Variables that are changed through iteration process of value generation
    int mSequenceValue1;
    int mSequenceValue2;
    
    // Used for adding to sequence value to produce new values
    int mAddValue1;
    int mAddValue2;
};

#endif //__INTNUMGEN_H__
