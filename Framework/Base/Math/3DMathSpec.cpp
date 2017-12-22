///////////////////////////////////////////////////////////////////////////////////////
//  3DMath.cpp
//
//  3DMath Methods Specialization
//
///////////////////////////////////////////////////////////////////////////////////////

#include <math.h>
#include <memory.h>

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
#include "Matrix.h"
#include "Quaternion.h"
#include "Algebra.h"

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