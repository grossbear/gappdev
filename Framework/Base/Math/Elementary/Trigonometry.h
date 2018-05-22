///////////////////////////////////////////////////////////////////////////////////////
//  Trigonometry.h
//
//  Trigonometry Functions Declarations
//  
//
///////////////////////////////////////////////////////////////////////////////////////

#ifndef _TRIGONOMETRY_H_
#define _TRIGONOMETRY_H_

///////////////////////////////////////////////////////////////////////////////////////
float   msin(float x);
double  msin(double x);

///////////////////////////////////////////////////////////////////////////////////////
float   mcos(float x);
double  mcos(double x);

///////////////////////////////////////////////////////////////////////////////////////
float   mtan(float x);
double  mtan(double x);

///////////////////////////////////////////////////////////////////////////////////////
float   macos(float x);
double  macos(double x);

///////////////////////////////////////////////////////////////////////////////////////
float   masin(float x);
double  masin(double x);

///////////////////////////////////////////////////////////////////////////////////////
float   matan(float x);
double  matan(double x);

///////////////////////////////////////////////////////////////////////////////////////
float   matan2(float x, float y);
double  matan2(double x, double y);

///////////////////////////////////////////////////////////////////////////////////////
float   msinh(float x);
double  msinh(double x);

///////////////////////////////////////////////////////////////////////////////////////
float   mcosh(float x);
double  mcosh(double x);

///////////////////////////////////////////////////////////////////////////////////////
float   mtanh(float x);
double  mtanh(double x);

///////////////////////////////////////////////////////////////////////////////////////
void    msincos(float angle, float &sin_val, float &cos_val);
void    msincos(double angle, double &sin_val, double &cos_val);

///////////////////////////////////////////////////////////////////////////////////////
float   m_tsinf(float x);
///////////////////////////////////////////////////////////////////////////////////////
float   m_tcosf(float x);
///////////////////////////////////////////////////////////////////////////////////////
void    m_tsincosf(float angle, float &sin_val, float &cos_val);
///////////////////////////////////////////////////////////////////////////////////////

#ifdef MATH_FIXED_INST
///////////////////////////////////////////////////////////////////////////////////////
tfixed32<16> m_tsinx(const tfixed32<16> &x);
///////////////////////////////////////////////////////////////////////////////////////
tfixed32<16> m_tcosx(const tfixed32<16> &x);
///////////////////////////////////////////////////////////////////////////////////////
tfixed32<16> m_tacosx(const tfixed32<16> &x);
///////////////////////////////////////////////////////////////////////////////////////
void    m_tsincosx(const tfixed32<16> &angle, tfixed32<16> &sin_val, tfixed32<16> &cos_val);
///////////////////////////////////////////////////////////////////////////////////////
#endif //MATH_FIXED_INST

///////////////////////////////////////////////////////////////////////////////////////
int32t  m_tacosdeg(float f);
///////////////////////////////////////////////////////////////////////////////////////
int32t  m_tacosdeg(const tfixed32<16> &x);


#include "Trigonometry.inl"

#endif //_TRIGONOMETRY_H_