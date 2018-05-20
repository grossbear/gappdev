///////////////////////////////////////////////////////////////////////////////////////
//  MathConsts.h
//
//  Math Constants  
//
///////////////////////////////////////////////////////////////////////////////////////

#ifndef _MATHLIB_CONSTS_
#define _MATHLIB_CONSTS_

///////////////////////////////////////////////////////////////////////////////////////
// Constants defines
#define CONST_PI        3.1415926535897932384626433832795       // - pi
#define CONST_2PI       6.283185307179586476925286766559        // - 2pi
#define CONST_DEG2RAD   0.017453292519943295769236907684886     // - pi/180
#define CONST_RAD2DEG   57.295779513082320876798154814114       // - 180/pi (1 rad)
#define CONST_PI_2      1.5707963267948966192313216916398       // - pi/2
#define CONST_PI_4      0.785398163397448309615660845811988     // - pi/4
#define CONST_1_PI      0.318309886183790671537767526745        // - 1/pi
#define CONST_2_PI      0.63661977236758134307553505349006      // - 2/pi
#define CONST_1_2PI     0.15915494309189533576888376337251      // - 1/2pi

#define CONST_SQRT_2    1.4142135623730950488016887242097       // - sqrt(2)
#define CONST_SQRT_1_2  0.7071067811865475244008443621048       // - 1/sqrt(2)
#define CONST_2_SQRTPI  1.1283791670955125738961589031215       // - 2/sqrt(pi)
#define CONST_SQRT_3    1.7320508075688772935274463415059       // - sqrt(3)

#define CONST_E         2.7182818284590452353602874713527       // - e
#define CONST_LOG2E     1.4426950408889634073599246810019       // - log2(e)
#define CONST_LOG10E    0.43429448190325182765112891891         // - log10(e)
#define CONST_LN2       0.69314718055994530941723212145818      // - ln(2)
#define CONST_LN10      2.3025850929940456840179914546844       // - ln(10)
#define CONST_PHI       1.6180339887498948482045888343656       // - phi (Golden Number)


///////////////////////////////////////////////////////////////////////////////////////
#ifdef _WIN32
#define MATH_INT64_MAX  0x7fffffffffffffff
#define MATH_INT64_MIN  0x8000000000000000
#else //__GNUC__
#define MATH_INT64_MAX  0x7fffffffffffffffLL
#define MATH_INT64_MIN  0x8000000000000000LL
#endif

#define MATH_INT_MAX    0x7fffffff
#define MATH_INT_MIN    0x80000000

#define MATH_DOUBLE_MAX 1.7976931348623158e+308
#define MATH_FLOAT_MAX  3.402823466e+38F

#define FLOAT_EPS       1e-6
#define DOUBLE_EPS      1e-12


///////////////////////////////////////////////////////////////////////////////////////
template <typename T>
class CMathConst
{
public:
    static const T MATH_PI;
    static const T MATH_2PI;
    static const T MATH_PI_2;
    static const T MATH_PI_4;
    static const T MATH_1_PI;
    static const T MATH_2_PI;
    static const T MATH_1_2PI;

    static const T MATH_DEG2RAD;
    static const T MATH_RAD2DEG;

    static const T MATH_SQRT_2;
    static const T MATH_SQRT_1_2;
    static const T MATH_2_SQRTPI;
    static const T MATH_SQRT_3;

    static const T MATH_E;
    static const T MATH_LOG2E;
    static const T MATH_LOG10E;
    static const T MATH_LN2;
    static const T MATH_LN10;
    static const T MATH_PHI;
};
///////////////////////////////////////////////////////////////////////////////////////

template <typename T>
const T CMathConst<T>::MATH_PI          = T(CONST_PI);          // - pi
///////////////////////////////////////////////////////////////////////////////////////
template <typename T>
const T CMathConst<T>::MATH_2PI         = T(CONST_2PI);         // - 2pi
///////////////////////////////////////////////////////////////////////////////////////
template <typename T>
const T CMathConst<T>::MATH_PI_2        = T(CONST_PI_2);        // - pi/2
///////////////////////////////////////////////////////////////////////////////////////
template <typename T>
const T CMathConst<T>::MATH_PI_4        = T(CONST_PI_4);        // - pi/4
///////////////////////////////////////////////////////////////////////////////////////
template <typename T>
const T CMathConst<T>::MATH_1_PI        = T(CONST_1_PI);        // - 1/pi
///////////////////////////////////////////////////////////////////////////////////////
template <typename T>
const T CMathConst<T>::MATH_2_PI        = T(CONST_2_PI);        // - 2/pi
///////////////////////////////////////////////////////////////////////////////////////
template <typename T>
const T CMathConst<T>::MATH_1_2PI       = T(CONST_1_2PI);       // - 1/2pi
///////////////////////////////////////////////////////////////////////////////////////
template <typename T>
const T CMathConst<T>::MATH_DEG2RAD     = T(CONST_DEG2RAD);     // - pi/180
///////////////////////////////////////////////////////////////////////////////////////
template <typename T>
const T CMathConst<T>::MATH_RAD2DEG     = T(CONST_RAD2DEG);     // - 180/pi (1 rad)
///////////////////////////////////////////////////////////////////////////////////////
template <typename T>
const T CMathConst<T>::MATH_SQRT_2      = T(CONST_SQRT_2);      // - sqrt(2)
///////////////////////////////////////////////////////////////////////////////////////
template <typename T>
const T CMathConst<T>::MATH_SQRT_1_2    = T(CONST_SQRT_1_2);    // - 1/sqrt(2)
///////////////////////////////////////////////////////////////////////////////////////
template <typename T>
const T CMathConst<T>::MATH_2_SQRTPI    = T(CONST_2_SQRTPI);    // - 2/sqrt(pi)
///////////////////////////////////////////////////////////////////////////////////////
template <typename T>
const T CMathConst<T>::MATH_SQRT_3      = T(CONST_SQRT_3);      // - sqrt(3)
///////////////////////////////////////////////////////////////////////////////////////
template <typename T>
const T CMathConst<T>::MATH_E           = T(CONST_E);           // - e
///////////////////////////////////////////////////////////////////////////////////////
template <typename T>
const T CMathConst<T>::MATH_LOG2E       = T(CONST_LOG2E);       // - log2(e)
///////////////////////////////////////////////////////////////////////////////////////
template <typename T>
const T CMathConst<T>::MATH_LOG10E      = T(CONST_LOG10E);      // - log10(e)
///////////////////////////////////////////////////////////////////////////////////////
template <typename T>
const T CMathConst<T>::MATH_LN2         = T(CONST_LN2);         // - ln(2)
///////////////////////////////////////////////////////////////////////////////////////
template <typename T>
const T CMathConst<T>::MATH_LN10        = T(CONST_LN10);         // - ln(10)
///////////////////////////////////////////////////////////////////////////////////////
template <typename T>
const T CMathConst<T>::MATH_PHI         = T(CONST_PHI);          // - phi (Golden Number)
///////////////////////////////////////////////////////////////////////////////////////
#endif //_MATHLIB_CONSTS_

