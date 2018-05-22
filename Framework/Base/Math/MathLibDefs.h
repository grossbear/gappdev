///////////////////////////////////////////////////////////////////////////////////////
//  MathLibDefs.h
//
//  Inside Library Defines Compilation Functions Specification
//  
//
///////////////////////////////////////////////////////////////////////////////////////

#ifndef _MATH_LIB_DEFINES_H_
#define _MATH_LIB_DEFINES_H_

#define M_API

// In-line Function And Force In line Macros
#define M_INLINE       __inline
#ifdef __linux__
#define M_FORCEINL     __attribute__((always_inline)) inline
#elif _WIN32
#define M_FORCEINL     __forceinline
#else
#define M_FORCEINL     __inline
#endif // Force Inline For Different Platforms

// Primary Function That Has SSE Implementation
#define MATH_PRIM_SSE

// Library Uses It's Own Conversion From Floating Point Number To Integer And Vice-Versa
#define MATH_NO_FPU

// Library Uses ILM Functions In Converting Float Types Into Half Type
#define MATH_ILM_HALF_CONVERSION

// Build Classes Instantiation Using Following Data Types  
#define MATH_DOUBLE_INST
#define MATH_LONG_DOUBLE_INST
#define MATH_FIXED_INST
#define MATH_HALF_INST

//#define CMATH_VEC2_FAST_SQRT
//#define CMATH_VEC2_TABLE_SQRT
#define CMATH_VEC2_HIGH_PREC_FLOAT_SQRT
//#define CMATH_VEC2_TABLE_TRIGONOMETRY

//#define CMATH_VEC3_FAST_SQRT
//#define CMATH_VEC3_TABLE_SQRT
#define CMATH_VEC3_HIGH_PREC_FLOAT_SQRT
//#define CMATH_VEC3_TABLE_TRIGONOMETRY

//#define CMATH_VEC4_FAST_SQRT
//#define CMATH_VEC4_TABLE_SQRT
#define CMATH_VEC4_HIGH_PREC_FLOAT_SQRT
//#define CMATH_VEC4_TABLE_TRIGONOMETRY

//#define CMATH_MTX33_FAST_SQRT
//#define CMATH_MTX33_TABLE_SQRT
//#define CMATH_MTX33_TABLE_TRIGONOMETRY

//#define CMATH_MTX44_FAST_SQRT
//#define CMATH_MTX44_TABLE_SQRT
//#define CMATH_MTX44_TABLE_TRIGONOMETRY

//#define CMATH_QUAT_FAST_SQRT
//#define CMATH_QUAT_TABLE_SQRT
//#define CMATH_QUAT_TABLE_TRIGONOMETRY

#endif //_MATH_LIB_DEFINES_H_
