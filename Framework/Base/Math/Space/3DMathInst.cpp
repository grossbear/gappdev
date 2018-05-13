///////////////////////////////////////////////////////////////////////////////////////
//  3DMathInst.cpp
//
//  3DMath Methods Instantiation
//
///////////////////////////////////////////////////////////////////////////////////////

#include <math.h>
#include <memory.h>

#include "Base/Common/PlatformTypes.h"
#include "MathConsts.h"
#include "MathLibDefs.h"

#include "Types/tfixed32.h"
#include "Types/thalf.h"

#include "Elementary/ElemFunc.h"
#include "Elementary/Sqrt.h"
#include "Elementary/Trigonometry.h"

#include "Algebra/AlgebraElemFunc.inl"
#include "Algebra/Vector.h"
#include "Algebra/Plane.h"
#include "Algebra/Matrix.h"
#include "Algebra/Quaternion.h"
#include "Algebra/Algebra.h"

#include "3DMath.h"
#include "3DMath.cpp"


///////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
// Line Triangle Intersection Functions

///////////////////////////////////////////////////////////////////////////////////////
template bool CMIsPointInsideTriangle(const CMVector3D<float> &point, const CMVector3D<float> &vertex1,
                                        const CMVector3D<float> &vertex2, const CMVector3D<float> &vertex3);

///////////////////////////////////////////////////////////////////////////////////////
template bool CMIsLineIntersectTriangle(const CMVector3D<float> &vertex1, 
                                       const CMVector3D<float> &vertex2, const CMVector3D<float> &vertex3,
                                       const CMVector3D<float> &point, const CMVector3D<float> &dir);
///////////////////////////////////////////////////////////////////////////////////////
template bool CMLineTriangleIntersectPt(CMVector3D<float> &vOut, const CMVector3D<float> &vertex1, 
                                       const CMVector3D<float> &vertex2, const CMVector3D<float> &vertex3,
                                       const CMVector3D<float> &point, const CMVector3D<float> &dir);

///////////////////////////////////////////////////////////////////////////////////////
template bool CMRayTriangleIntersectPt(CMVector3D<float> &vOut, const CMVector3D<float> &vertex1, 
                                      const CMVector3D<float> &vertex2, const CMVector3D<float> &vertex3, 
                                      const CMVector3D<float> &origin, const CMVector3D<float> &dir, 
                                        bool twoSided);
///////////////////////////////////////////////////////////////////////////////////////
template bool CMIsRayIntersectTriangle(const CMVector3D<float> &vertex1, 
                                      const CMVector3D<float> &vertex2, const CMVector3D<float> &vertex3, 
                                      const CMVector3D<float> &origin, const CMVector3D<float> &dir, 
                                        bool twoSided);

///////////////////////////////////////////////////////////////////////////////////////
template 
bool CMIsSegmentIntersectTriangle(const CMVector3D<float> &vertex1, const CMVector3D<float> &vertex2,
                                 const CMVector3D<float> &vertex3, const CMVector3D<float> &segPoint1, 
                                 const CMVector3D<float> &segPoint2);

                                 ///////////////////////////////////////////////////////////////////////////////////////
template void CMTriangleNormal(CMVector3D<float> &norm, const CMVector3D<float> &p0, 
                               const CMVector3D<float> &p1, const CMVector3D<float> &p2, bool bNormalize);

///////////////////////////////////////////////////////////////////////////////////////
template void CMClosestPointOnLine(CMVector3D<float> &vOut, const CMVector3D<float> &A, const CMVector3D<float> &B,
                             const CMVector3D<float> &point, bool SegmentClamp);

///////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
// Double Type Functions
#ifdef MATH_DOUBLE_INST
///////////////////////////////////////////////////////////////////////////////////////
template bool CMIsPointInsideTriangle(const CMVector3D<double> &point, const CMVector3D<double> &vertex1,
                                        const CMVector3D<double> &vertex2, const CMVector3D<double> &vertex3);
///////////////////////////////////////////////////////////////////////////////////////
template bool CMIsLineIntersectTriangle(const CMVector3D<double> &vertex1, 
                                       const CMVector3D<double> &vertex2, const CMVector3D<double> &vertex3,
                                       const CMVector3D<double> &point, const CMVector3D<double> &dir);
///////////////////////////////////////////////////////////////////////////////////////
template bool CMLineTriangleIntersectPt(CMVector3D<double> &vOut, const CMVector3D<double> &vertex1, 
                                       const CMVector3D<double> &vertex2, const CMVector3D<double> &vertex3,
                                       const CMVector3D<double> &point, const CMVector3D<double> &dir);
///////////////////////////////////////////////////////////////////////////////////////
template bool CMRayTriangleIntersectPt(CMVector3D<double> &vOut, const CMVector3D<double> &vertex1, 
                                      const CMVector3D<double> &vertex2, const CMVector3D<double> &vertex3, 
                                      const CMVector3D<double> &origin, const CMVector3D<double> &dir, 
                                        bool twoSided);
///////////////////////////////////////////////////////////////////////////////////////
template bool CMIsRayIntersectTriangle(const CMVector3D<double> &vertex1, 
                                      const CMVector3D<double> &vertex2, const CMVector3D<double> &vertex3, 
                                      const CMVector3D<double> &origin, const CMVector3D<double> &dir, 
                                        bool twoSided);
///////////////////////////////////////////////////////////////////////////////////////
template 
bool CMIsSegmentIntersectTriangle(const CMVector3D<double> &vertex1, const CMVector3D<double> &vertex2,
                                 const CMVector3D<double> &vertex3, const CMVector3D<double> &segPoint1, 
                                 const CMVector3D<double> &segPoint2);
///////////////////////////////////////////////////////////////////////////////////////
template void CMTriangleNormal(CMVector3D<double> &norm, const CMVector3D<double> &p0, 
                               const CMVector3D<double> &p1, const CMVector3D<double> &p2, bool bNormalize);
///////////////////////////////////////////////////////////////////////////////////////
template void CMClosestPointOnLine(CMVector3D<double> &vOut, const CMVector3D<double> &A, const CMVector3D<double> &B,
                             const CMVector3D<double> &point, bool SegmentClamp);
///////////////////////////////////////////////////////////////////////////////////////
#endif //MATH_DOUBLE_INST