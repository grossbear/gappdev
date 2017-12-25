///////////////////////////////////////////////////////////////////////////////////////
//  VectorInst.cpp
//
//  Vector Classes And Methods Instantiation
//
///////////////////////////////////////////////////////////////////////////////////////

#include <math.h>

#include "Base/Common/PlatformTypes.h"
#include "MathConst.h"
#include "MathLibDefs.h"

#include "tfixed32.h"
#include "thalf.h"

#include "MathPrim.h"
#include "Sqrt.h"
#include "Trigonometry.h"
#include "PrimFunc.h"

#include "Vector.h"
#include "Vector.cpp"

///////////////////////////////////////////////////////////////////////////////////////
// CMVector2D Functions

///////////////////////////////////////////////////////////////////////////////////////
// Rotate A 2D Vector, Using The Specified Angle In Radians
template void CMVec2Rotate<float>(CMVector2D<float> &vOut, const CMVector2D<float> &vIn, float rad);

///////////////////////////////////////////////////////////////////////////////////////
// Returns The Length Of A 2D Vector
template float CMVec2Length<float>(const CMVector2D<float> &v);

///////////////////////////////////////////////////////////////////////////////////////
// Returns The Square Of The Length Of A 2D Vector
template float CMVec2LengthSq<float>(const CMVector2D<float> &v);

///////////////////////////////////////////////////////////////////////////////////////
// Calculate Length Between Two 2D Points
template float CMVec2Distance(const CMVector2D<float> &p0, const CMVector2D<float> &p1);

///////////////////////////////////////////////////////////////////////////////////////
// Calculate Square Length Between Two 2D Points
template float CMVec2DistanceSq(const CMVector2D<float> &p0, const CMVector2D<float> &p1);
  
///////////////////////////////////////////////////////////////////////////////////////
// Normalize A 2D Vector
template void CMVec2Normalize(CMVector2D<float> &vOut, const CMVector2D<float> &vIn);

///////////////////////////////////////////////////////////////////////////////////////
// Getting Angle In Radians Between Two 2D Vectors
template float CMVec2Angle(const CMVector2D<float> &v1, const CMVector2D<float> &vV2);

///////////////////////////////////////////////////////////////////////////////////////
// Getting Reflected 2D Vector
template void CMVec2Reflect(CMVector2D<float> &vR, const CMVector2D<float> &vL, const CMVector2D<float> &vN);

///////////////////////////////////////////////////////////////////////////////////////
// Getting Refracted 2D Vector
template void CMVec2Refract(CMVector2D<float> &vR, const CMVector2D<float> &vL, const CMVector2D<float> &vN,
                            float etaRatio);


///////////////////////////////////////////////////////////////////////////////////////
// Performs A Catmull-Rom Interpolation, Using The Specified 2D Vectors
template void CMVec2CatmullRom(CMVector2D<float> &vOut, const CMVector2D<float> &v1, const CMVector2D<float> &v2, 
                      const CMVector2D<float> &v3, const CMVector2D<float> &v4,  float weightingFactor);

///////////////////////////////////////////////////////////////////////////////////////
// Returns A Point In Barycentric Coordinates, Using The Specified 2D Vectors
template void CMVec2BaryCentric(CMVector2D<float> &vOut, const CMVector2D<float> &v1, const CMVector2D<float> &v2,
                       const CMVector2D<float> &v3, float f, float g);

///////////////////////////////////////////////////////////////////////////////////////
// Performs A Hermite Spline Interpolation, Using The Specified 2D Vectors
template void CMVec2Hermite(CMVector2D<float> &vOut, const CMVector2D<float> &v1, const CMVector2D<float> &vT1, 
                   const CMVector2D<float> &v2, const CMVector2D<float> &vT2, float weight, float tension, float bias);

///////////////////////////////////////////////////////////////////////////////////////
// Performs A Quadratic Interpolation, Using The Specified 2D Vectors
template void CMVec2Quadratic(CMVector2D<float> &vOut, const CMVector2D<float> &v1, const CMVector2D<float> &v2,
                     const CMVector2D<float> &v3, float factor);

///////////////////////////////////////////////////////////////////////////////////////
// Performs A Cubic Interpolation, Using The Specified 2D Vectors
template void CMVec2Cubic(CMVector2D<float> &vOut, const CMVector2D<float> &v1, const CMVector2D<float> &v2,
                 const CMVector2D<float> &v3, const CMVector2D<float> &v4, float factor);

///////////////////////////////////////////////////////////////////////////////////////
// Performs A Square Interpolation, Using Two 2D Vectors
template void CMVec2Sqrp(CMVector2D<float> &vOut, const CMVector2D<float> &v1, const CMVector2D<float> &v2, float factor);

///////////////////////////////////////////////////////////////////////////////////////
// Performs A Cosinus Interpolation, Using Two 2D Vectors
template void CMVec2Cosrp(CMVector2D<float> &vOut, const CMVector2D<float> &v1, const CMVector2D<float> &v2, float factor);
///////////////////////////////////////////////////////////////////////////////////////

// CMVector2D Double Type Functions Instantiation
#ifdef MATH_DOUBLE_INST
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec2Rotate<double>(CMVector2D<double> &vOut, const CMVector2D<double> &vIn, double rad);
///////////////////////////////////////////////////////////////////////////////////////
template double CMVec2Length<double>(const CMVector2D<double> &v);
///////////////////////////////////////////////////////////////////////////////////////
template double CMVec2LengthSq<double>(const CMVector2D<double> &v);
///////////////////////////////////////////////////////////////////////////////////////
template double CMVec2Distance(const CMVector2D<double> &p0, const CMVector2D<double> &p1);
///////////////////////////////////////////////////////////////////////////////////////
template double CMVec2DistanceSq(const CMVector2D<double> &p0, const CMVector2D<double> &p1);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec2Normalize(CMVector2D<double> &vOut, const CMVector2D<double> &vIn);
///////////////////////////////////////////////////////////////////////////////////////
template double CMVec2Angle(const CMVector2D<double> &v1, const CMVector2D<double> &vV2);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec2Reflect(CMVector2D<double> &vR, const CMVector2D<double> &vL, const CMVector2D<double> &vN);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec2Refract(CMVector2D<double> &vR, const CMVector2D<double> &vL, const CMVector2D<double> &vN,
                            double etaRatio);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec2CatmullRom(CMVector2D<double> &vOut, const CMVector2D<double> &v1, const CMVector2D<double> &v2, 
                      const CMVector2D<double> &v3, const CMVector2D<double> &v4,  double weightingFactor);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec2BaryCentric(CMVector2D<double> &vOut, const CMVector2D<double> &v1, const CMVector2D<double> &v2,
                       const CMVector2D<double> &v3, double f, double g);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec2Hermite(CMVector2D<double> &vOut, const CMVector2D<double> &v1, const CMVector2D<double> &vT1, 
                   const CMVector2D<double> &v2, const CMVector2D<double> &vT2, double weight, double tension, double bias);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec2Quadratic(CMVector2D<double> &vOut, const CMVector2D<double> &v1, const CMVector2D<double> &v2,
                     const CMVector2D<double> &v3, double factor);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec2Cubic(CMVector2D<double> &vOut, const CMVector2D<double> &v1, const CMVector2D<double> &v2,
                 const CMVector2D<double> &v3, const CMVector2D<double> &v4, double factor);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec2Sqrp(CMVector2D<double> &vOut, const CMVector2D<double> &v1, const CMVector2D<double> &v2, double factor);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec2Cosrp(CMVector2D<double> &vOut, const CMVector2D<double> &v1, const CMVector2D<double> &v2, double factor);
///////////////////////////////////////////////////////////////////////////////////////
#endif //MATH_DOUBLE_INST

///////////////////////////////////////////////////////////////////////////////////////
// CMVector3D Functions

///////////////////////////////////////////////////////////////////////////////////////
// Rotate A 3D Vector In X Axis, Using The Specified Angle In Radians
template void CMVec3RotateX(CMVector3D<float> &vOut, const CMVector3D<float> &vIn, float rad);

///////////////////////////////////////////////////////////////////////////////////////
// Rotate A 3D Vector In Y Axis, Using The Specified Angle In Radians
template void CMVec3RotateY(CMVector3D<float> &vOut, const CMVector3D<float> &vIn, float rad);

///////////////////////////////////////////////////////////////////////////////////////
// Rotate A 3D Vector In Z Axis, Using The Specified Angle In Radians
template void CMVec3RotateZ(CMVector3D<float> &vOut, const CMVector3D<float> &vIn, float rad);

///////////////////////////////////////////////////////////////////////////////////////
// Returns The Length Of A 3D Vector
template float CMVec3Length(const CMVector3D<float> &v);

///////////////////////////////////////////////////////////////////////////////////////
// Returns The Square Of The Length Of A 3D Vector
template float CMVec3LengthSq(const CMVector3D<float> &v);

///////////////////////////////////////////////////////////////////////////////////////
// Calculate Length Between Two 3D Points
template float CMVec3Distance(const CMVector3D<float> &p0, const CMVector3D<float> &p1);

///////////////////////////////////////////////////////////////////////////////////////
// Calculate Square Length Between Two 3D Points
template float CMVec3DistanceSq(const CMVector3D<float> &p0, const CMVector3D<float> &p1);
  
///////////////////////////////////////////////////////////////////////////////////////
// Normalize A 3D Vector
template void CMVec3Normalize(CMVector3D<float> &vOut, const CMVector3D<float> &vIn);

///////////////////////////////////////////////////////////////////////////////////////
// Getting Angle In Radians Between Two 3D Vectors
template float CMVec3Angle(const CMVector3D<float> &v1, const CMVector3D<float> &v2);

///////////////////////////////////////////////////////////////////////////////////////
// Getting Reflected 3D Vector
template void CMVec3Reflect(CMVector3D<float> &vR, const CMVector3D<float> &vL, const CMVector3D<float> &vN);

///////////////////////////////////////////////////////////////////////////////////////
// Getting Refracted 3D Vector
template void CMVec3Refract(CMVector3D<float> &vR, const CMVector3D<float> &vL, const CMVector3D<float> &vN,
                            float etaRatio);

///////////////////////////////////////////////////////////////////////////////////////
// Performs A Catmull-Rom Interpolation, Using The Specified 3D Vectors
template void CMVec3CatmullRom(CMVector3D<float> &vOut, const CMVector3D<float> &v1, const CMVector3D<float> &v2, 
                      const CMVector3D<float> &v3, const CMVector3D<float> &v4,  float weight);

///////////////////////////////////////////////////////////////////////////////////////
// Returns A Point In Barycentric Coordinates, Using The Specified 3D Vectors
template void CMVec3BaryCentric(CMVector3D<float> &vOut, const CMVector3D<float> &v1, const CMVector3D<float> &v2,
                       const CMVector3D<float> &v3, float f, float g);

///////////////////////////////////////////////////////////////////////////////////////
// Performs A Hermite Spline Interpolation, Using The Specified 3D Vectors
template void CMVec3Hermite(CMVector3D<float> &vOut, const CMVector3D<float> &v1, const CMVector3D<float> &vT1, 
                   const CMVector3D<float> &v2, const CMVector3D<float> &vT2, float weight, float tension, float bias);

///////////////////////////////////////////////////////////////////////////////////////
// Performs A Quadratic Interpolation, Using The Specified 3D Vectors
template void CMVec3Quadratic(CMVector3D<float> &vOut, const CMVector3D<float> &v1, const CMVector3D<float> &v2,
                     const CMVector3D<float> &v3, float factor);

///////////////////////////////////////////////////////////////////////////////////////
// Performs A Cubic Interpolation, Using The Specified 3D Vectors
template void CMVec3Cubic(CMVector3D<float> &vOut, const CMVector3D<float> &v1, const CMVector3D<float> &v2,
                 const CMVector3D<float> &v3, const CMVector3D<float> &v4, float factor);

///////////////////////////////////////////////////////////////////////////////////////
// Performs A Square Interpolation, Using Two 3D Vectors
template void CMVec3Sqrp(CMVector3D<float> &vOut, const CMVector3D<float> &v1, const CMVector3D<float> &v2, float factor);

///////////////////////////////////////////////////////////////////////////////////////
// Performs A Cosinus Interpolation, Using Two 3D Vectors
template void CMVec3Cosrp(CMVector3D<float> &vOut, const CMVector3D<float> &v1, const CMVector3D<float> &vV2, float factor);


// CMVector3D Double Type Functions Instantiation
#ifdef MATH_DOUBLE_INST
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec3RotateX(CMVector3D<double> &vOut, const CMVector3D<double> &vIn, double rad);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec3RotateY(CMVector3D<double> &vOut, const CMVector3D<double> &vIn, double rad);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec3RotateZ(CMVector3D<double> &vOut, const CMVector3D<double> &vIn, double rad);
///////////////////////////////////////////////////////////////////////////////////////
template double CMVec3Length(const CMVector3D<double> &v);
///////////////////////////////////////////////////////////////////////////////////////
template double CMVec3LengthSq(const CMVector3D<double> &v);
///////////////////////////////////////////////////////////////////////////////////////
template double CMVec3Distance(const CMVector3D<double> &p0, const CMVector3D<double> &p1);
///////////////////////////////////////////////////////////////////////////////////////
template double CMVec3DistanceSq(const CMVector3D<double> &p0, const CMVector3D<double> &p1);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec3Normalize(CMVector3D<double> &vOut, const CMVector3D<double> &vIn);
///////////////////////////////////////////////////////////////////////////////////////
template double CMVec3Angle(const CMVector3D<double> &v1, const CMVector3D<double> &v2);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec3Reflect(CMVector3D<double> &vR, const CMVector3D<double> &vL, const CMVector3D<double> &vN);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec3Refract(CMVector3D<double> &vR, const CMVector3D<double> &vL, const CMVector3D<double> &vN,
                            double etaRatio);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec3CatmullRom(CMVector3D<double> &vOut, const CMVector3D<double> &v1, const CMVector3D<double> &v2, 
                      const CMVector3D<double> &v3, const CMVector3D<double> &v4,  double weight);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec3BaryCentric(CMVector3D<double> &vOut, const CMVector3D<double> &v1, const CMVector3D<double> &v2,
                       const CMVector3D<double> &v3, double f, double g);

///////////////////////////////////////////////////////////////////////////////////////
template void CMVec3Hermite(CMVector3D<double> &vOut, const CMVector3D<double> &v1, const CMVector3D<double> &vT1, 
                   const CMVector3D<double> &v2, const CMVector3D<double> &vT2, double weight, double tension, double bias);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec3Quadratic(CMVector3D<double> &vOut, const CMVector3D<double> &v1, const CMVector3D<double> &v2,
                     const CMVector3D<double> &v3, double factor);

///////////////////////////////////////////////////////////////////////////////////////
template void CMVec3Cubic(CMVector3D<double> &vOut, const CMVector3D<double> &v1, const CMVector3D<double> &v2,
                 const CMVector3D<double> &v3, const CMVector3D<double> &v4, double factor);

///////////////////////////////////////////////////////////////////////////////////////
template void CMVec3Sqrp(CMVector3D<double> &vOut, const CMVector3D<double> &v1, const CMVector3D<double> &v2, double factor);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec3Cosrp(CMVector3D<double> &vOut, const CMVector3D<double> &v1, const CMVector3D<double> &vV2, double factor);
#endif //MATH_DOUBLE_INST


///////////////////////////////////////////////////////////////////////////////////////
// CMVector4D Functions

///////////////////////////////////////////////////////////////////////////////////////
// Cross Product Of Two 4D Vectors
template void CMVec4Cross(CMVector4D<float> &vOut, const CMVector4D<float> &v1, const CMVector4D<float> &v2);

///////////////////////////////////////////////////////////////////////////////////////
// Rotate A 4D Vector In X Axis, Using The Specified Angle In Radians
template void CMVec4RotateX(CMVector4D<float> &vOut, const CMVector4D<float> &vIn, float rad);

///////////////////////////////////////////////////////////////////////////////////////
// Rotate A 4D Vector In Y Axis, Using The Specified Angle In Radians
template void CMVec4RotateY(CMVector4D<float> &vOut, const CMVector4D<float> &vIn, float rad);

///////////////////////////////////////////////////////////////////////////////////////
// Rotate A 4D Vector In Z Axis, Using The Specified Angle In Radians
template void CMVec4RotateZ(CMVector4D<float> &vOut, const CMVector4D<float> &vIn, float rad);

///////////////////////////////////////////////////////////////////////////////////////
// Returns The Length Of A 4D Vector
template float CMVec4Length(const CMVector4D<float> &v);

///////////////////////////////////////////////////////////////////////////////////////
// Returns The Square Of The Length Of A 4D Vector
template float CMVec4LengthSq(const CMVector4D<float> &v);

///////////////////////////////////////////////////////////////////////////////////////
// Calculate Length Between Two 4D Points
template float CMVec4Distance(CMVector4D<float> &p0, CMVector4D<float> &p1);

///////////////////////////////////////////////////////////////////////////////////////
// Calculate Square Length Between Two 4D Points
template float CMVec4DistanceSq(CMVector4D<float> &p0, CMVector4D<float> &p1);
  
///////////////////////////////////////////////////////////////////////////////////////
// Normalize A 4D Vector
template void CMVec4Normalize(CMVector4D<float> &vOut, const CMVector4D<float> &vIn);

///////////////////////////////////////////////////////////////////////////////////////
// Getting Angle In Radians Between Two 4D Vectors
template float CMVec4Angle(const CMVector4D<float> &v1, const CMVector4D<float> &v2);

///////////////////////////////////////////////////////////////////////////////////////
// Getting Reflected 4D Vector
template void CMVec4Reflect(CMVector4D<float> &vR, const CMVector4D<float> &vL, const CMVector4D<float> &vN);

///////////////////////////////////////////////////////////////////////////////////////
// Getting Refracted 4D Vector
template void CMVec4Refract(CMVector4D<float> &vR, const CMVector4D<float> &vL, const CMVector4D<float> &vN,
                            float etaRatio);

///////////////////////////////////////////////////////////////////////////////////////
// Performs A Catmull-Rom Interpolation, Using The Specified 4D Vectors
template void CMVec4CatmullRom(CMVector4D<float> &vOut, const CMVector4D<float> &v1, const CMVector4D<float> &v2, 
                      const CMVector4D<float> &v3, const CMVector4D<float> &v4,  float f);

///////////////////////////////////////////////////////////////////////////////////////
// Returns A Point In Barycentric Coordinates, Using The Specified 4D Vectors
template void CMVec4BaryCentric(CMVector4D<float> &vOut, const CMVector4D<float> &v1, const CMVector4D<float> &v2,
                       const CMVector4D<float> &v3, float f, float g);

///////////////////////////////////////////////////////////////////////////////////////
// Performs A Hermite Spline Interpolation, Using The Specified 3D Vectors
template void CMVec4Hermite(CMVector4D<float> &vOut, const CMVector4D<float> &v1, const CMVector4D<float> &vT1, 
                   const CMVector4D<float> &v2, const CMVector4D<float> &vT2, float weight, float tension, float bias);

///////////////////////////////////////////////////////////////////////////////////////
// Performs A Quadratic Interpolation, Using The Specified 4D Vectors
template void CMVec4Quadratic(CMVector4D<float> &vOut, const CMVector4D<float> &v1, const CMVector4D<float> &v2,
                     const CMVector4D<float> &v3, float factor);

///////////////////////////////////////////////////////////////////////////////////////
// Performs A Cubic Interpolation, Using The Specified 4D Vectors
template void CMVec4Cubic(CMVector4D<float> &vOut, const CMVector4D<float> &v1, const CMVector4D<float> &v2,
                 const CMVector4D<float> &v3, const CMVector4D<float> &v4, float factor);

///////////////////////////////////////////////////////////////////////////////////////
// Performs A Square Interpolation, Using Two 4D Vectors
template void CMVec4Sqrp(CMVector4D<float> &vOut, const CMVector4D<float> &v1, const CMVector4D<float> &v2, float factor);

///////////////////////////////////////////////////////////////////////////////////////
// Performs A Cosinus Interpolation, Using Two 4D Vectors
template void CMVec4Cosrp(CMVector4D<float> &vOut, const CMVector4D<float> &v1, const CMVector4D<float> &v2, float factor);


// CMVector4D Double Type Functions Instantiation
#ifdef MATH_DOUBLE_INST
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec4Cross(CMVector4D<double> &vOut, const CMVector4D<double> &v1, const CMVector4D<double> &v2);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec4RotateX(CMVector4D<double> &vOut, const CMVector4D<double> &vIn, double rad);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec4RotateY(CMVector4D<double> &vOut, const CMVector4D<double> &vIn, double rad);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec4RotateZ(CMVector4D<double> &vOut, const CMVector4D<double> &vIn, double rad);
///////////////////////////////////////////////////////////////////////////////////////
template double CMVec4Length(const CMVector4D<double> &v);
///////////////////////////////////////////////////////////////////////////////////////
template double CMVec4LengthSq(const CMVector4D<double> &v);
///////////////////////////////////////////////////////////////////////////////////////
template double CMVec4Distance(CMVector4D<double> &p0, CMVector4D<double> &p1);
///////////////////////////////////////////////////////////////////////////////////////
template double CMVec4DistanceSq(CMVector4D<double> &p0, CMVector4D<double> &p1);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec4Normalize(CMVector4D<double> &vOut, const CMVector4D<double> &vIn);
///////////////////////////////////////////////////////////////////////////////////////
template double CMVec4Angle(const CMVector4D<double> &v1, const CMVector4D<double> &v2);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec4Reflect(CMVector4D<double> &vR, const CMVector4D<double> &vL, const CMVector4D<double> &vN);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec4Refract(CMVector4D<double> &vR, const CMVector4D<double> &vL, const CMVector4D<double> &vN,
                            double etaRatio);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec4CatmullRom(CMVector4D<double> &vOut, const CMVector4D<double> &v1, const CMVector4D<double> &v2, 
                      const CMVector4D<double> &v3, const CMVector4D<double> &v4,  double f);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec4BaryCentric(CMVector4D<double> &vOut, const CMVector4D<double> &v1, const CMVector4D<double> &v2,
                       const CMVector4D<double> &v3, double f, double g);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec4Hermite(CMVector4D<double> &vOut, const CMVector4D<double> &v1, const CMVector4D<double> &vT1, 
                   const CMVector4D<double> &v2, const CMVector4D<double> &vT2, double weight, double tension, double bias);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec4Quadratic(CMVector4D<double> &vOut, const CMVector4D<double> &v1, const CMVector4D<double> &v2,
                     const CMVector4D<double> &v3, double factor);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec4Cubic(CMVector4D<double> &vOut, const CMVector4D<double> &v1, const CMVector4D<double> &v2,
                 const CMVector4D<double> &v3, const CMVector4D<double> &v4, double factor);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec4Sqrp(CMVector4D<double> &vOut, const CMVector4D<double> &v1, const CMVector4D<double> &v2, double factor);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec4Cosrp(CMVector4D<double> &vOut, const CMVector4D<double> &v1, const CMVector4D<double> &v2, double factor);
#endif //MATH_DOUBLE_INST

///////////////////////////////////////////////////////////////////////////////////////
template class CMVector2D<float>;
///////////////////////////////////////////////////////////////////////////////////////
template class CMVector3D<float>;
///////////////////////////////////////////////////////////////////////////////////////
template class CMVector4D<float>;
///////////////////////////////////////////////////////////////////////////////////////

// Vectors Classes Instantiation
#ifdef MATH_DOUBLE_INST
///////////////////////////////////////////////////////////////////////////////////////
template class CMVector2D<double>;
///////////////////////////////////////////////////////////////////////////////////////
template class CMVector3D<double>;
///////////////////////////////////////////////////////////////////////////////////////
template class CMVector4D<double>;
///////////////////////////////////////////////////////////////////////////////////////
#endif //MATH_DOUBLE_INST