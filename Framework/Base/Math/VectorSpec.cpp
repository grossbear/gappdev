///////////////////////////////////////////////////////////////////////////////////////
//  VectorSpec.cpp
//
//  Vector Classes Methods Specialization
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
template void CMVec2Rotate<float>(CMVector2D<float> &vOut, const CMVector2D<float> &vIn, float rad);
///////////////////////////////////////////////////////////////////////////////////////
template float CMVec2Length<float>(const CMVector2D<float> &v);
///////////////////////////////////////////////////////////////////////////////////////
template float CMVec2LengthSq<float>(const CMVector2D<float> &v);
///////////////////////////////////////////////////////////////////////////////////////
template float CMVec2Distance(const CMVector2D<float> &p0, const CMVector2D<float> &p1);
///////////////////////////////////////////////////////////////////////////////////////
template float CMVec2DistanceSq(const CMVector2D<float> &p0, const CMVector2D<float> &p1);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec2Normalize(CMVector2D<float> &vOut, const CMVector2D<float> &vIn);
///////////////////////////////////////////////////////////////////////////////////////
template float CMVec2Angle(const CMVector2D<float> &v1, const CMVector2D<float> &vV2);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec2Reflect(CMVector2D<float> &vR, const CMVector2D<float> &vL, const CMVector2D<float> &vN);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec2Refract(CMVector2D<float> &vR, const CMVector2D<float> &vL, const CMVector2D<float> &vN,
                            float etaRatio);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec2CatmullRom(CMVector2D<float> &vOut, const CMVector2D<float> &v1, const CMVector2D<float> &v2, 
                      const CMVector2D<float> &v3, const CMVector2D<float> &v4,  float weightingFactor);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec2BaryCentric(CMVector2D<float> &vOut, const CMVector2D<float> &v1, const CMVector2D<float> &v2,
                       const CMVector2D<float> &v3, float f, float g);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec2Hermite(CMVector2D<float> &vOut, const CMVector2D<float> &v1, const CMVector2D<float> &vT1, 
                   const CMVector2D<float> &v2, const CMVector2D<float> &vT2, float weight, float tension, float bias);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec2Quadratic(CMVector2D<float> &vOut, const CMVector2D<float> &v1, const CMVector2D<float> &v2,
                     const CMVector2D<float> &v3, float factor);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec2Cubic(CMVector2D<float> &vOut, const CMVector2D<float> &v1, const CMVector2D<float> &v2,
                 const CMVector2D<float> &v3, const CMVector2D<float> &v4, float factor);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec2Sqrp(CMVector2D<float> &vOut, const CMVector2D<float> &v1, const CMVector2D<float> &v2, float factor);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec2Cosrp(CMVector2D<float> &vOut, const CMVector2D<float> &v1, const CMVector2D<float> &v2, float factor);
///////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////
// CMVector3D Functions

///////////////////////////////////////////////////////////////////////////////////////
template void CMVec3RotateX(CMVector3D<float> &vOut, const CMVector3D<float> &vIn, float rad);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec3RotateY(CMVector3D<float> &vOut, const CMVector3D<float> &vIn, float rad);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec3RotateZ(CMVector3D<float> &vOut, const CMVector3D<float> &vIn, float rad);
///////////////////////////////////////////////////////////////////////////////////////
template float CMVec3Length(const CMVector3D<float> &v);
///////////////////////////////////////////////////////////////////////////////////////
template float CMVec3LengthSq(const CMVector3D<float> &v);
///////////////////////////////////////////////////////////////////////////////////////
template float CMVec3Distance(const CMVector3D<float> &p0, const CMVector3D<float> &p1);
///////////////////////////////////////////////////////////////////////////////////////
template float CMVec3DistanceSq(const CMVector3D<float> &p0, const CMVector3D<float> &p1);  
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec3Normalize(CMVector3D<float> &vOut, const CMVector3D<float> &vIn);
///////////////////////////////////////////////////////////////////////////////////////
template float CMVec3Angle(const CMVector3D<float> &v1, const CMVector3D<float> &v2);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec3Reflect(CMVector3D<float> &vR, const CMVector3D<float> &vL, const CMVector3D<float> &vN);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec3Refract(CMVector3D<float> &vR, const CMVector3D<float> &vL, const CMVector3D<float> &vN,
                            float etaRatio);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec3CatmullRom(CMVector3D<float> &vOut, const CMVector3D<float> &v1, const CMVector3D<float> &v2, 
                      const CMVector3D<float> &v3, const CMVector3D<float> &v4,  float weight);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec3BaryCentric(CMVector3D<float> &vOut, const CMVector3D<float> &v1, const CMVector3D<float> &v2,
                       const CMVector3D<float> &v3, float f, float g);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec3Hermite(CMVector3D<float> &vOut, const CMVector3D<float> &v1, const CMVector3D<float> &vT1, 
                   const CMVector3D<float> &v2, const CMVector3D<float> &vT2, float weight, float tension, float bias);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec3Quadratic(CMVector3D<float> &vOut, const CMVector3D<float> &v1, const CMVector3D<float> &v2,
                     const CMVector3D<float> &v3, float factor);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec3Cubic(CMVector3D<float> &vOut, const CMVector3D<float> &v1, const CMVector3D<float> &v2,
                 const CMVector3D<float> &v3, const CMVector3D<float> &v4, float factor);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec3Sqrp(CMVector3D<float> &vOut, const CMVector3D<float> &v1, const CMVector3D<float> &v2, float factor);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec3Cosrp(CMVector3D<float> &vOut, const CMVector3D<float> &v1, const CMVector3D<float> &vV2, float factor);
///////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
// CMVector4D Functions

///////////////////////////////////////////////////////////////////////////////////////
template void CMVec4Cross(CMVector4D<float> &vOut, const CMVector4D<float> &v1, const CMVector4D<float> &v2);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec4RotateX(CMVector4D<float> &vOut, const CMVector4D<float> &vIn, float rad);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec4RotateY(CMVector4D<float> &vOut, const CMVector4D<float> &vIn, float rad);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec4RotateZ(CMVector4D<float> &vOut, const CMVector4D<float> &vIn, float rad);
///////////////////////////////////////////////////////////////////////////////////////
template float CMVec4Length(const CMVector4D<float> &v);
///////////////////////////////////////////////////////////////////////////////////////
template float CMVec4LengthSq(const CMVector4D<float> &v);
///////////////////////////////////////////////////////////////////////////////////////
template float CMVec4Distance(CMVector4D<float> &p0, CMVector4D<float> &p1);
///////////////////////////////////////////////////////////////////////////////////////
template float CMVec4DistanceSq(CMVector4D<float> &p0, CMVector4D<float> &p1);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec4Normalize(CMVector4D<float> &vOut, const CMVector4D<float> &vIn);
///////////////////////////////////////////////////////////////////////////////////////
template float CMVec4Angle(const CMVector4D<float> &v1, const CMVector4D<float> &v2);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec4Reflect(CMVector4D<float> &vR, const CMVector4D<float> &vL, const CMVector4D<float> &vN);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec4Refract(CMVector4D<float> &vR, const CMVector4D<float> &vL, const CMVector4D<float> &vN,
                            float etaRatio);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec4CatmullRom(CMVector4D<float> &vOut, const CMVector4D<float> &v1, const CMVector4D<float> &v2, 
                      const CMVector4D<float> &v3, const CMVector4D<float> &v4,  float f);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec4BaryCentric(CMVector4D<float> &vOut, const CMVector4D<float> &v1, const CMVector4D<float> &v2,
                       const CMVector4D<float> &v3, float f, float g);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec4Hermite(CMVector4D<float> &vOut, const CMVector4D<float> &v1, const CMVector4D<float> &vT1, 
                   const CMVector4D<float> &v2, const CMVector4D<float> &vT2, float weight, float tension, float bias);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec4Quadratic(CMVector4D<float> &vOut, const CMVector4D<float> &v1, const CMVector4D<float> &v2,
                     const CMVector4D<float> &v3, float factor);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec4Cubic(CMVector4D<float> &vOut, const CMVector4D<float> &v1, const CMVector4D<float> &v2,
                 const CMVector4D<float> &v3, const CMVector4D<float> &v4, float factor);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec4Sqrp(CMVector4D<float> &vOut, const CMVector4D<float> &v1, const CMVector4D<float> &v2, float factor);
///////////////////////////////////////////////////////////////////////////////////////
template void CMVec4Cosrp(CMVector4D<float> &vOut, const CMVector4D<float> &v1, const CMVector4D<float> &v2, float factor);
///////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
//--template class CMVector2D<float>;
///////////////////////////////////////////////////////////////////////////////////////
//--template class CMVector3D<float>;
///////////////////////////////////////////////////////////////////////////////////////
//--template class CMVector4D<float>;
///////////////////////////////////////////////////////////////////////////////////////