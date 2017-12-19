///////////////////////////////////////////////////////////////////////////////////////
//  PrimFunc.h
//
//  Elementary Functions In Algebra Classes 
//  
//
///////////////////////////////////////////////////////////////////////////////////////

#ifndef _ALGEBRA_FUNCTIONS_SPEC_H_
#define _ALGEBRA_FUNCTIONS_SPEC_H_

///////////////////////////////////////////////////////////////////////////////////////
// Vec2 
M_FORCEINL float MVEC2SQRT(float x)
{
#ifdef CMATH_VEC2_TABLE_SQRT
    return m_tsqrt(x);
#elif CMATH_VEC2_FAST_SQRT
    return m_fsqrt(x);
#else
    return sqrtf(x);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MVEC2SQRT(double x)
{
    return sqrt(x);
}

M_FORCEINL float MVEC2SQRT(float x, float y)
{
#ifdef CMATH_VEC2_TABLE_SQRT
    return m_tsqrt(x*x + y*y);
#elif CMATH_VEC2_FAST_SQRT
    return m_fsqrt(x*x + y*y);
#else 
    return sqrtf(x*x + y*y);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MVEC2SQRT(double x, double y)
{
    return sqrt(x*x + y*y);
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MVEC2REVSQRT(float x, float y)
{
    ASSERT((x*x + y*y) > FLOAT_EPS);

#ifdef CMATH_VEC2_TABLE_SQRT
    return m_rtsqrt(x*x + y*y);
#elif CMATH_VEC2_FAST_SQRT
    return m_rfsqrt(x*x + y*y);
#else
    return 1.0f/sqrtf(x*x + y*y);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MVEC2REVSQRT(double x, double y)
{
    ASSERT((x*x + y*y) > DOUBLE_EPS);

    return sqrt(x*x + y*y);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL void MVEC2SINCOS(float angle, float &sina, float &cosa)
{
#ifdef CMATH_VEC2_TABLE_TRIGONOMETRY
    m_tsincosf(angle,sina,cosa);
#else
    msincosf(angle,sina,cosa);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL void MVEC2SINCOS(double angle, double &sina, double &cosa)
{
    msincosd(angle,sina,cosa);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MVEC2COS(float angle)
{
#ifdef CMATH_VEC2_TABLE_TRIGONOMETRY
    return m_tcosf(angle);
#else
    return cosf(angle);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MVEC2COS(double angle)
{
    return cos(angle);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MVEC2ACOS(float x)
{
    return acosf(x);
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MVEC2ACOS(double x)
{
    return acos(x);
}

///////////////////////////////////////////////////////////////////////////////////////
// Vec3 
M_FORCEINL float MVEC3SQRT(float x)
{
#ifdef CMATH_VEC3_TABLE_SQRT
    return m_tsqrt(x);
#elif CMATH_VEC3_FAST_SQRT
    return m_fsqrt(x);
#else
    return sqrtf(x);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MVEC3SQRT(double x)
{
    return sqrt(x);
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MVEC3SQRT(float x, float y, float z)
{
#ifdef CMATH_VEC3_TABLE_SQRT
    return m_tsqrt(x*x + y*y + z*z);
#elif CMATH_VEC3_FAST_SQRT
    return m_fsqrt(x*x + y*y + z*z);
#else 
    return sqrtf(x*x + y*y + z*z);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MVEC3SQRT(double x, double y, double z)
{
    return sqrt(x*x + y*y + z*z);
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MVEC3REVSQRT(float x, float y, float z)
{
    ASSERT((x*x + y*y + z*z) > FLOAT_EPS);

#ifdef CMATH_VEC3_TABLE_SQRT
    return m_rtsqrt(x*x + y*y + z*z);
#elif CMATH_VEC3_FAST_SQRT
    return m_rfsqrt(x*x + y*y + z*z);
#else
    return 1.0f/sqrtf(x*x + y*y + z*z);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MVEC3REVSQRT(double x, double y, double z)
{
    ASSERT((x*x + y*y + z*z) > DOUBLE_EPS);

    return 1.0f/sqrt(x*x + y*y + z*z);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL void MVEC3SINCOS(float angle, float &sina, float &cosa)
{
#ifdef CMATH_VEC3_TABLE_TRIGONOMETRY
    m_tsincosf(angle,sina,cosa);
#else
    msincosf(angle,sina,cosa);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL void MVEC3SINCOS(double angle, double &sina, double &cosa)
{
    msincosd(angle,sina,cosa);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MVEC3COS(float angle)
{
#ifdef CMATH_VEC3_TABLE_TRIGONOMETRY
    return m_tcosf(angle);
#else
    return cosf(angle);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MVEC3COS(double angle)
{
    return cos(angle);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MVEC3ACOS(float x)
{
    return acosf(x);
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MVEC3ACOS(double x)
{
    return acos(x);
}


///////////////////////////////////////////////////////////////////////////////////////
// Vec4 
M_FORCEINL float MVEC4SQRT(float x)
{
#ifdef CMATH_VEC4_TABLE_SQRT
    return m_tsqrt(x);
#elif CMATH_VEC4_FAST_SQRT
    return m_fsqrt(x);
#else
    return sqrtf(x);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MVEC4SQRT(double x)
{
    return sqrt(x);
}

M_FORCEINL float MVEC4SQRT(float x, float y, float z, float w)
{
#ifdef CMATH_VEC4_TABLE_SQRT
    return m_tsqrt(x*x + y*y + z*z + w*w);
#elif CMATH_VEC4_FAST_SQRT
    return m_fsqrt(x*x + y*y + z*z + w*w);
#else 
    return sqrtf(x*x + y*y + z*z + w*w);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MVEC4SQRT(double x, double y, double z, double w)
{
    return sqrt(x*x + y*y + z*z + w*w);
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MVEC4REVSQRT(float x, float y, float z, float w)
{
    ASSERT((x*x + y*y + z*z + w*w) > FLOAT_EPS);

#ifdef CMATH_VEC4_TABLE_SQRT
    return m_rtsqrt(x*x + y*y + z*z + w*w);
#elif CMATH_VEC4_FAST_SQRT
    return m_rfsqrt(x*x + y*y + z*z + w*w);
#else
    return 1.0f/sqrtf(x*x + y*y + z*z + w*w);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MVEC4REVSQRT(double x, double y, double z, double w)
{
    ASSERT((x*x + y*y + z*z + w*w) > DOUBLE_EPS);

    return sqrt(x*x + y*y + z*z + w*w);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL void MVEC4SINCOS(float angle, float &sina, float &cosa)
{
#ifdef CMATH_VEC4_TABLE_TRIGONOMETRY
    m_tsincosf(angle,sina,cosa);
#else
    msincosf(angle,sina,cosa);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL void MVEC4SINCOS(double angle, double &sina, double &cosa)
{
    msincosd(angle,sina,cosa);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MVEC4COS(float angle)
{
#ifdef CMATH_VEC4_TABLE_TRIGONOMETRY
    return m_tcosf(angle);
#else
    return cosf(angle);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MVEC4COS(double angle)
{
    return cos(angle);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MVEC4ACOS(float x)
{
    return acosf(x);
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MVEC4ACOS(double x)
{
    return acos(x);
}

///////////////////////////////////////////////////////////////////////////////////////
// Plane
M_FORCEINL float MPLANESQRT(float a, float b, float c)
{
#ifdef CMATH_PLANE_TABLE_SQRT
    return m_tsqrt(a*a + b*b + c*c);
#elif CMATH_PLANE_FAST_SQRT
    return m_fsqrt(a*a + b*b + c*c);
#else
    return sqrtf(a*a + b*b + c*c);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MPLANESQRT(double a, double b, double c)
{
    return sqrt(a*a + b*b + c*c);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MPLANEREVSQRT(float a, float b, float c)
{
#ifdef CMATH_PLANE_TABLE_SQRT
    return m_rtsqrt(a*a + b*b + c*c);
#elif CMATH_PLANE_FAST_SQRT
    return m_rfsqrt(a*a + b*b + c*c);
#else
    return 1.0f/sqrtf(a*a + b*b + c*c);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MPLANEREVSQRT(double a, double b, double c)
{
    return 1.0/sqrt(a*a + b*b + c*c);
}

///////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////
// Matrix3x3
M_FORCEINL void MMTX33SINCOS(float angle, float &sina, float &cosa)
{
#ifdef CMATH_MTX33_TABLE_TRIGONOMETRY
    m_tsincosf(angle,sina,cosa);
#else
    msincosf(angle,sina,cosa);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL void MMTX33SINCOS(double angle, double &sina, double &cosa)
{
    msincosd(angle,sina,cosa);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MMTX33SQRT(float x, float y, float z)
{
#ifdef CMATH_MTX33_TABLE_SQRT
    return m_tsqrt(x*x + y*y + z*z);
#elif CMATH_MTX33_FAST_SQRT
    return m_fsqrt(x*x + y*y + z*z);
#else
    return sqrtf(x*x + y*y + z*z);
#endif 
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MMTX33SQRT(double x, double y, double z)
{
    return sqrt(x*x + y*y + z*z);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MMTX33ASIN(float x)
{
    return asinf(x);
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MMTX33ASIN(double x)
{
    return asin(x);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MMTX33ATAN2(float y, float x)
{
    return atan2f(y,x);
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MMTX33ATAN2(double y, double x)
{
    return atan2(y,x);
}

///////////////////////////////////////////////////////////////////////////////////////
// Matrix4x4
M_FORCEINL void MMTX44SINCOS(float angle, float &sina, float &cosa)
{
#ifdef CMATH_MTX44_TABLE_TRIGONOMETRY
    m_tsincosf(angle,sina,cosa);
#else
    msincosf(angle,sina,cosa);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL void MMTX44SINCOS(double angle, double &sina, double &cosa)
{
    msincosd(angle,sina,cosa);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MMTX44SQRT(float x, float y, float z)
{
#ifdef CMATH_MTX44_TABLE_SQRT
    return m_tsqrt(x*x + y*y + z*z);
#elif CMATH_MTX44_FAST_SQRT
    return m_fsqrt(x*x + y*y + z*z);
#else
    return sqrtf(x*x + y*y + z*z);
#endif 
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MMTX44SQRT(double x, double y, double z)
{
    return sqrt(x*x + y*y + z*z);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MMTX44ASIN(float x)
{
    return asinf(x);
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MMTX44ASIN(double x)
{
    return asin(x);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MMTX44ATAN2(float y, float x)
{
    return atan2f(y,x);
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MMTX44ATAN2(double y, double x)
{
    return atan2(y,x);
}

///////////////////////////////////////////////////////////////////////////////////////
// Matrix4x4
M_FORCEINL void MQUATSINCOS(float angle, float &sina, float &cosa)
{
#ifdef CMATH_QUAT_TABLE_TRIGONOMETRY
    m_tsincosf(angle,sina,cosa);
#else
    msincosf(angle,sina,cosa);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL void MQUATSINCOS(double angle, double &sina, double &cosa)
{
    msincosd(angle,sina,cosa);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MQUATATAN2(float y, float x)
{
    return atan2f(y,x);
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MQUATATAN2(double y, double x)
{
    return atan2(y,x);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MQUATATAN(float x)
{
    return atanf(x);
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MQUATATAN(double x)
{
    return atan(x);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MQUATSIN(float x)
{
#ifdef CMATH_QUAT_TABLE_TRIGONOMETRY
    return m_tsinf(x);
#else
    return sinf(x);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MQUATSIN(double x)
{
    return sin(x);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MQUATASIN(float x)
{
    return asinf(x);
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MQUATASIN(double x)
{
    return asin(x);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MQUATACOS(float x)
{
    return acosf(x);
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MQUATACOS(double x)
{
    return acos(x);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MQUATSQRT(float x, float y, float z, float w)
{
#ifdef CMATH_QUAT_FAST_SQRT
    return m_fsqrt(x*x + y*y + z*z + w*w);
#elif CMATH_QUAT_TABLE_SQRT
    return m_tsqrt(x*x + y*y + z*z + w*w);
#else
    return sqrtf(x*x + y*y + z*z + w*w);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MQUATSQRT(double x, double y, double z, double w)
{
    return sqrt(x*x + y*y + z*z + w*w);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MQUATSQRT(float x, float y, float z)
{
#ifdef CMATH_QUAT_FAST_SQRT
    return m_fsqrt(x*x + y*y + z*z);
#elif CMATH_QUAT_TABLE_SQRT
    return m_tsqrt(x*x + y*y + z*z);
#else
    return sqrtf(x*x + y*y + z*z);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MQUATSQRT(double x, double y, double z)
{
    return sqrt(x*x + y*y + z*z);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MQUATSQRT(float x)
{
#ifdef CMATH_QUAT_FAST_SQRT
    return m_fsqrt(x);
#elif CMATH_QUAT_TABLE_SQRT
    return m_tsqrt(x);
#else
    return sqrtf(x);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MQUATSQRT(double x)
{
    return sqrt(x);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MQUATRSQRT(float x, float y, float z, float w)
{
#ifdef CMATH_QUAT_FAST_SQRT
    return m_rfsqrt(x*x + y*y + z*z + w*w);
#elif CMATH_QUAT_TABLE_SQRT
    return 1.0f/m_tsqrt(x*x + y*y + z*z + w*w);
#else
    return 1.0f/sqrtf(x*x + y*y + z*z + w*w);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MQUATRSQRT(double x, double y, double z, double w)
{
    return 1.0/sqrt(x*x + y*y + z*z + w*w);
}

///////////////////////////////////////////////////////////////////////////////////////

#endif //_ALGEBRA_FUNCTIONS_SPEC_H_
