///////////////////////////////////////////////////////////////////////////////////////
//  AlgebraElemFunc.inl
//
//  Inline Elementary Functions Used In Algebra Classes 
//  
//
///////////////////////////////////////////////////////////////////////////////////////

#ifndef _ALGEBRA_ELEMENTARY_FUNC_INL
#define _ALGEBRA_ELEMENTARY_FUNC_INL

///////////////////////////////////////////////////////////////////////////////////////
// Vec2 
M_FORCEINL float MVEC2SQRT(float x)
{
#ifdef CMATH_VEC2_TABLE_SQRT
    return m_tsqrt(x);
#elif defined(CMATH_VEC2_FAST_SQRT)
    return m_fsqrt(x);
#elif defined(CMATH_VEC2_HIGH_PREC_FLOAT_SQRT)
    return (float)msqrt((double)x);
#else
    return msqrt(x);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MVEC2SQRT(double x)
{
    return msqrt(x);
}

M_FORCEINL float MVEC2SQRT(float x, float y)
{
#ifdef CMATH_VEC2_TABLE_SQRT
    return m_tsqrt(x*x + y*y);
#elif defined(CMATH_VEC2_FAST_SQRT)
    return m_fsqrt(x*x + y*y);
#elif defined(CMATH_VEC2_HIGH_PREC_FLOAT_SQRT)
    return (float)msqrt(double(x)*double(x) + double(y)*double(y));
#else 
    return msqrt(x*x + y*y);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MVEC2SQRT(double x, double y)
{
    return msqrt(x*x + y*y);
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MVEC2REVSQRT(float x, float y)
{
    ASSERT((x*x + y*y) > FLOAT_EPS);

#ifdef CMATH_VEC2_TABLE_SQRT
    return m_rtsqrt(x*x + y*y);
#elif defined(CMATH_VEC2_FAST_SQRT)
    return m_rfsqrt(x*x + y*y);
#elif defined(CMATH_VEC2_HIGH_PREC_FLOAT_SQRT)
    return (float)(1.0/msqrt(double(x)*double(x) + double(y)*double(y)));
#else
    return 1.0f/msqrt(x*x + y*y);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MVEC2REVSQRT(double x, double y)
{
    ASSERT((x*x + y*y) > DOUBLE_EPS);

    return msqrt(x*x + y*y);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL void MVEC2SINCOS(float angle, float &sina, float &cosa)
{
#ifdef CMATH_VEC2_TABLE_TRIGONOMETRY
    m_tsincosf(angle,sina,cosa);
#else
    msincos(angle,sina,cosa);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL void MVEC2SINCOS(double angle, double &sina, double &cosa)
{
    msincos(angle,sina,cosa);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MVEC2COS(float angle)
{
#ifdef CMATH_VEC2_TABLE_TRIGONOMETRY
    return m_tcosf(angle);
#else
    return mcos(angle);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MVEC2COS(double angle)
{
    return mcos(angle);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MVEC2ACOS(float x)
{
    return macos(x);
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MVEC2ACOS(double x)
{
    return macos(x);
}

///////////////////////////////////////////////////////////////////////////////////////
// Vec3 
M_FORCEINL float MVEC3SQRT(float x)
{
#ifdef CMATH_VEC3_TABLE_SQRT
    return m_tsqrt(x);
#elif defined(CMATH_VEC3_FAST_SQRT)
    return m_fsqrt(x);
#elif defined(CMATH_VEC3_HIGH_PREC_FLOAT_SQRT)
    return (float)msqrt((double)x);
#else
    return msqrt(x);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MVEC3SQRT(double x)
{
    return msqrt(x);
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MVEC3SQRT(float x, float y, float z)
{
#ifdef CMATH_VEC3_TABLE_SQRT
    return m_tsqrt(x*x + y*y + z*z);
#elif defined(CMATH_VEC3_FAST_SQRT)
    return m_fsqrt(x*x + y*y + z*z);
#elif defined(CMATH_VEC3_HIGH_PREC_FLOAT_SQRT)
    double xd(x),yd(y),zd(z);
    return (float)msqrt(xd*xd + yd*yd + zd*zd);
#else 
    return msqrt(x*x + y*y + z*z);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MVEC3SQRT(double x, double y, double z)
{
    return msqrt(x*x + y*y + z*z);
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MVEC3REVSQRT(float x, float y, float z)
{
    ASSERT((x*x + y*y + z*z) > FLOAT_EPS);

#ifdef CMATH_VEC3_TABLE_SQRT
    return m_rtsqrt(x*x + y*y + z*z);
#elif defined(CMATH_VEC3_FAST_SQRT)
    return m_rfsqrt(x*x + y*y + z*z);
#elif defined(CMATH_VEC3_HIGH_PREC_FLOAT_SQRT)
    double xd(x),yd(y),zd(z);
    return (float)(1.0/msqrt(xd*xd + yd*yd + zd*zd));
#else
    return 1.0f/msqrt(x*x + y*y + z*z);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MVEC3REVSQRT(double x, double y, double z)
{
    ASSERT((x*x + y*y + z*z) > DOUBLE_EPS);

    return 1.0f/msqrt(x*x + y*y + z*z);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL void MVEC3SINCOS(float angle, float &sina, float &cosa)
{
#ifdef CMATH_VEC3_TABLE_TRIGONOMETRY
    m_tsincosf(angle,sina,cosa);
#else
    msincos(angle,sina,cosa);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL void MVEC3SINCOS(double angle, double &sina, double &cosa)
{
    msincos(angle,sina,cosa);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MVEC3COS(float angle)
{
#ifdef CMATH_VEC3_TABLE_TRIGONOMETRY
    return m_tcosf(angle);
#else
    return mcos(angle);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MVEC3COS(double angle)
{
    return mcos(angle);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MVEC3ACOS(float x)
{
    return macos(x);
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MVEC3ACOS(double x)
{
    return macos(x);
}


///////////////////////////////////////////////////////////////////////////////////////
// Vec4 
M_FORCEINL float MVEC4SQRT(float x)
{
#ifdef CMATH_VEC4_TABLE_SQRT
    return m_tsqrt(x);
#elif defined(CMATH_VEC4_FAST_SQRT)
    return m_fsqrt(x);
#elif defined(CMATH_VEC4_HIGH_PREC_FLOAT_SQRT)
    return (float)msqrt((double)x);
#else
    return msqrt(x);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MVEC4SQRT(double x)
{
    return msqrt(x);
}

M_FORCEINL float MVEC4SQRT(float x, float y, float z, float w)
{
#ifdef CMATH_VEC4_TABLE_SQRT
    return m_tsqrt(x*x + y*y + z*z + w*w);
#elif defined(CMATH_VEC4_FAST_SQRT)
    return m_fsqrt(x*x + y*y + z*z + w*w);
#elif defined(CMATH_VEC4_HIGH_PREC_FLOAT_SQRT)
    double xd(x),yd(y),zd(z),wd(w);
    return (float)msqrt(xd*xd + yd*yd + zd*zd + wd*wd);
#else 
    return msqrt(x*x + y*y + z*z + w*w);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MVEC4SQRT(double x, double y, double z, double w)
{
    return msqrt(x*x + y*y + z*z + w*w);
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MVEC4REVSQRT(float x, float y, float z, float w)
{
    ASSERT((x*x + y*y + z*z + w*w) > FLOAT_EPS);

#ifdef CMATH_VEC4_TABLE_SQRT
    return m_rtsqrt(x*x + y*y + z*z + w*w);
#elif defined(CMATH_VEC4_FAST_SQRT)
    return m_rfsqrt(x*x + y*y + z*z + w*w);
#elif defined(CMATH_VEC4_HIGH_PREC_FLOAT_SQRT)
    double xd(x),yd(y),zd(z),wd(w);
    return (float)(1.0/msqrt(xd*xd + yd*yd + zd*zd + wd*wd));
#else
    return 1.0f/msqrt(x*x + y*y + z*z + w*w);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MVEC4REVSQRT(double x, double y, double z, double w)
{
    ASSERT((x*x + y*y + z*z + w*w) > DOUBLE_EPS);

    return msqrt(x*x + y*y + z*z + w*w);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL void MVEC4SINCOS(float angle, float &sina, float &cosa)
{
#ifdef CMATH_VEC4_TABLE_TRIGONOMETRY
    m_tsincosf(angle,sina,cosa);
#else
    msincos(angle,sina,cosa);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL void MVEC4SINCOS(double angle, double &sina, double &cosa)
{
    msincos(angle,sina,cosa);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MVEC4COS(float angle)
{
#ifdef CMATH_VEC4_TABLE_TRIGONOMETRY
    return m_tcosf(angle);
#else
    return mcos(angle);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MVEC4COS(double angle)
{
    return mcos(angle);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MVEC4ACOS(float x)
{
    return macos(x);
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MVEC4ACOS(double x)
{
    return macos(x);
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
    return msqrt(a*a + b*b + c*c);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MPLANESQRT(double a, double b, double c)
{
    return msqrt(a*a + b*b + c*c);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MPLANEREVSQRT(float a, float b, float c)
{
#ifdef CMATH_PLANE_TABLE_SQRT
    return m_rtsqrt(a*a + b*b + c*c);
#elif defined(CMATH_PLANE_FAST_SQRT)
    return m_rfsqrt(a*a + b*b + c*c);
#else
    return 1.0f/msqrt(a*a + b*b + c*c);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MPLANEREVSQRT(double a, double b, double c)
{
    return 1.0/msqrt(a*a + b*b + c*c);
}

///////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////
// Matrix3x3
M_FORCEINL void MMTX33SINCOS(float angle, float &sina, float &cosa)
{
#ifdef CMATH_MTX33_TABLE_TRIGONOMETRY
    m_tsincosf(angle,sina,cosa);
#else
    msincos(angle,sina,cosa);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL void MMTX33SINCOS(double angle, double &sina, double &cosa)
{
    msincos(angle,sina,cosa);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MMTX33SQRT(float x, float y, float z)
{
#ifdef CMATH_MTX33_TABLE_SQRT
    return m_tsqrt(x*x + y*y + z*z);
#elif defined(CMATH_MTX33_FAST_SQRT)
    return m_fsqrt(x*x + y*y + z*z);
#else
    return msqrt(x*x + y*y + z*z);
#endif 
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MMTX33SQRT(double x, double y, double z)
{
    return msqrt(x*x + y*y + z*z);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MMTX33ASIN(float x)
{
    return masin(x);
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MMTX33ASIN(double x)
{
    return masin(x);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MMTX33ATAN2(float y, float x)
{
    return matan2(y,x);
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MMTX33ATAN2(double y, double x)
{
    return matan2(y,x);
}

///////////////////////////////////////////////////////////////////////////////////////
// Matrix4x4
M_FORCEINL void MMTX44SINCOS(float angle, float &sina, float &cosa)
{
#ifdef CMATH_MTX44_TABLE_TRIGONOMETRY
    m_tsincosf(angle,sina,cosa);
#else
    msincos(angle,sina,cosa);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL void MMTX44SINCOS(double angle, double &sina, double &cosa)
{
    msincos(angle,sina,cosa);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MMTX44SQRT(float x, float y, float z)
{
#ifdef CMATH_MTX44_TABLE_SQRT
    return m_tsqrt(x*x + y*y + z*z);
#elif defined(CMATH_MTX44_FAST_SQRT)
    return m_fsqrt(x*x + y*y + z*z);
#else
    return msqrt(x*x + y*y + z*z);
#endif 
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MMTX44SQRT(double x, double y, double z)
{
    return msqrt(x*x + y*y + z*z);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MMTX44ASIN(float x)
{
    return masin(x);
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MMTX44ASIN(double x)
{
    return masin(x);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MMTX44ATAN2(float y, float x)
{
    return matan2(y,x);
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MMTX44ATAN2(double y, double x)
{
    return matan2(y,x);
}

///////////////////////////////////////////////////////////////////////////////////////
// Quaternion
M_FORCEINL void MQUATSINCOS(float angle, float &sina, float &cosa)
{
#ifdef CMATH_QUAT_TABLE_TRIGONOMETRY
    m_tsincosf(angle,sina,cosa);
#else
    msincos(angle,sina,cosa);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL void MQUATSINCOS(double angle, double &sina, double &cosa)
{
    msincos(angle,sina,cosa);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MQUATATAN2(float y, float x)
{
    return matan2(y,x);
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MQUATATAN2(double y, double x)
{
    return matan2(y,x);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MQUATATAN(float x)
{
    return matan(x);
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MQUATATAN(double x)
{
    return matan(x);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MQUATSIN(float x)
{
#ifdef CMATH_QUAT_TABLE_TRIGONOMETRY
    return m_tsinf(x);
#else
    return msin(x);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MQUATSIN(double x)
{
    return msin(x);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MQUATASIN(float x)
{
    return msin(x);
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MQUATASIN(double x)
{
    return msin(x);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MQUATACOS(float x)
{
    return macos(x);
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MQUATACOS(double x)
{
    return macos(x);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MQUATSQRT(float x, float y, float z, float w)
{
#ifdef CMATH_QUAT_FAST_SQRT
    return m_fsqrt(x*x + y*y + z*z + w*w);
#elif defined(CMATH_QUAT_TABLE_SQRT)
    return m_tsqrt(x*x + y*y + z*z + w*w);
#else
    return msqrt(x*x + y*y + z*z + w*w);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MQUATSQRT(double x, double y, double z, double w)
{
    return msqrt(x*x + y*y + z*z + w*w);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MQUATSQRT(float x, float y, float z)
{
#ifdef CMATH_QUAT_FAST_SQRT
    return m_fsqrt(x*x + y*y + z*z);
#elif defined(CMATH_QUAT_TABLE_SQRT)
    return m_tsqrt(x*x + y*y + z*z);
#else
    return msqrt(x*x + y*y + z*z);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MQUATSQRT(double x, double y, double z)
{
    return msqrt(x*x + y*y + z*z);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MQUATSQRT(float x)
{
#ifdef CMATH_QUAT_FAST_SQRT
    return m_fsqrt(x);
#elif defined(CMATH_QUAT_TABLE_SQRT)
    return m_tsqrt(x);
#else
    return msqrt(x);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MQUATSQRT(double x)
{
    return msqrt(x);
}

///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL float MQUATRSQRT(float x, float y, float z, float w)
{
#ifdef CMATH_QUAT_FAST_SQRT
    return m_rfsqrt(x*x + y*y + z*z + w*w);
#elif defined(CMATH_QUAT_TABLE_SQRT)
    return 1.0f/m_tsqrt(x*x + y*y + z*z + w*w);
#else
    return 1.0f/msqrt(x*x + y*y + z*z + w*w);
#endif
}
///////////////////////////////////////////////////////////////////////////////////////
M_FORCEINL double MQUATRSQRT(double x, double y, double z, double w)
{
    return 1.0/msqrt(x*x + y*y + z*z + w*w);
}
///////////////////////////////////////////////////////////////////////////////////////

#endif //_ALGEBRA_ELEMENTARY_FUNC_INL
