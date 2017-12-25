///////////////////////////////////////////////////////////////////////////////////////
//  PlaneInst.cpp
//
//  Plane Class And Methods Instantiation
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

#include "Plane.h"
#include "Plane.cpp"


///////////////////////////////////////////////////////////////////////////////////////
// Builds Plane From Three Points
template void CMPlaneSet(CMPlane<float> &plane, const CMVector3D<float> &p1, const CMVector3D<float> &p2,
                                    const CMVector3D<float> &p3);

///////////////////////////////////////////////////////////////////////////////////////
// Builds Plane From Normal And Offset Point
template void CMPlaneSet(CMPlane<float> &plane, const CMVector3D<float> &normal, const CMVector3D<float> &point);

///////////////////////////////////////////////////////////////////////////////////////
// Distance From Plane To Point Located In Space
template float CMPlaneDistance(const CMPlane<float> &plane, const CMVector3D<float> &vec);

///////////////////////////////////////////////////////////////////////////////////////
// Normalizes The Plane Coefficients So That The Plane Normal Has Unit Length
template void CMPlaneNormalize(CMPlane<float> &out, const CMPlane<float> &in);

///////////////////////////////////////////////////////////////////////////////////////
// Angle Of Intersection Of The Two Planes
template float CMPlaneIntersectionAngle(const CMPlane<float> &plane1, const CMPlane<float> &plane2);

///////////////////////////////////////////////////////////////////////////////////////
template bool CMPlaneLineIntersect(CMVector3D<float> &vOut, const CMPlane<float> &plane, const CMVector3D<float> &point, 
                        const CMVector3D<float> &dir);

///////////////////////////////////////////////////////////////////////////////////////
template bool CMPlaneLineIntersectByPoints(CMVector3D<float> &vOut, const CMPlane<float> &plane, 
                                            const CMVector3D<float> &point1, const CMVector3D<float> &point2);

///////////////////////////////////////////////////////////////////////////////////////
template 
bool CMPlaneRayIntersectPt(CMVector3D<float> &vOut, const CMPlane<float> &plane, const CMVector3D<float> &orig,
                             const CMVector3D<float> &dir, bool checkTwoSide);
///////////////////////////////////////////////////////////////////////////////////////
template 
bool CMIsRayIntersectPlane(const CMPlane<float> &plane, const CMVector3D<float> &orig,
                             const CMVector3D<float> &dir, bool checkTwoSide);

///////////////////////////////////////////////////////////////////////////////////////
template bool CMPlaneIntersect(CMVector3D<float> &vOut, const CMPlane<float> &plane1, const CMPlane<float> &plane2,
                       const CMPlane<float> &plane3);

///////////////////////////////////////////////////////////////////////////////////////
template bool CMPlaneSegmentIntersect(CMVector3D<float> &vOut, const CMPlane<float> &plane, const CMVector3D<float> &p1,
                                        const CMVector3D<float> &p2);

///////////////////////////////////////////////////////////////////////////////////////
// Orthogonal Projection 3D Vector On The Plane
template void CMPlaneOrthoProject(CMVector3D<float> &vOut, const CMPlane<float> &plane, const CMVector3D<float> &point);


///////////////////////////////////////////////////////////////////////////////////////
template class CMPlane<float>;
///////////////////////////////////////////////////////////////////////////////////////

// CMPlane Double Type Instantiation
#ifdef MATH_DOUBLE_INST
///////////////////////////////////////////////////////////////////////////////////////
template void CMPlaneSet(CMPlane<double> &plane, const CMVector3D<double> &p1, const CMVector3D<double> &p2,
                                    const CMVector3D<double> &p3);
///////////////////////////////////////////////////////////////////////////////////////
template void CMPlaneSet(CMPlane<double> &plane, const CMVector3D<double> &normal, const CMVector3D<double> &point);
///////////////////////////////////////////////////////////////////////////////////////
template double CMPlaneDistance(const CMPlane<double> &plane, const CMVector3D<double> &vec);
///////////////////////////////////////////////////////////////////////////////////////
template void CMPlaneNormalize(CMPlane<double> &out, const CMPlane<double> &in);
///////////////////////////////////////////////////////////////////////////////////////
template double CMPlaneIntersectionAngle(const CMPlane<double> &plane1, const CMPlane<double> &plane2);
///////////////////////////////////////////////////////////////////////////////////////
template bool CMPlaneLineIntersect(CMVector3D<double> &vOut, const CMPlane<double> &plane, const CMVector3D<double> &point, 
                        const CMVector3D<double> &dir);
///////////////////////////////////////////////////////////////////////////////////////
template bool CMPlaneLineIntersectByPoints(CMVector3D<double> &vOut, const CMPlane<double> &plane, 
                                            const CMVector3D<double> &point1, const CMVector3D<double> &point2);
///////////////////////////////////////////////////////////////////////////////////////
template 
bool CMPlaneRayIntersectPt(CMVector3D<double> &vOut, const CMPlane<double> &plane, const CMVector3D<double> &orig,
                             const CMVector3D<double> &dir, bool checkTwoSide);
///////////////////////////////////////////////////////////////////////////////////////
template 
bool CMIsRayIntersectPlane(const CMPlane<double> &plane, const CMVector3D<double> &orig,
                             const CMVector3D<double> &dir, bool checkTwoSide);
///////////////////////////////////////////////////////////////////////////////////////
template bool CMPlaneIntersect(CMVector3D<double> &vOut, const CMPlane<double> &plane1, const CMPlane<double> &plane2,
                       const CMPlane<double> &plane3);
///////////////////////////////////////////////////////////////////////////////////////
template bool CMPlaneSegmentIntersect(CMVector3D<double> &vOut, const CMPlane<double> &plane, const CMVector3D<double> &p1,
                                        const CMVector3D<double> &p2);
///////////////////////////////////////////////////////////////////////////////////////
template void CMPlaneOrthoProject(CMVector3D<double> &vOut, const CMPlane<double> &plane, const CMVector3D<double> &point);

///////////////////////////////////////////////////////////////////////////////////////
template class CMPlane<double>;
///////////////////////////////////////////////////////////////////////////////////////
#endif // MATH_DOUBLE_INST

