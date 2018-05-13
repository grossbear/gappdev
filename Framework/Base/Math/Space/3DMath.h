///////////////////////////////////////////////////////////////////////////////////////
//  3DMath.h
//
//  Functions That Operates In 3D Space
//  
//
///////////////////////////////////////////////////////////////////////////////////////

#ifndef _3DMATH_H_
#define _3DMATH_H_

///////////////////////////////////////////////////////////////////////////////////////
// Line Triangle Intersection Functions

///////////////////////////////////////////////////////////////////////////////////////
template <class T>
bool CMIsLineIntersectTriangle(const CMVector3D<T> &vertex1, const CMVector3D<T> &vertex2, 
                              const CMVector3D<T> &vertex3, const CMVector3D<T> &point, const CMVector3D<T> &dir);
///////////////////////////////////////////////////////////////////////////////////////
template <class T>
bool CMLineTriangleIntersectPt(CMVector3D<T> &vOut, const CMVector3D<T> &vertex1, const CMVector3D<T> &vertex2, 
                              const CMVector3D<T> &vertex3, const CMVector3D<T> &point, const CMVector3D<T> &dir);

///////////////////////////////////////////////////////////////////////////////////////
template <class T>
bool CMRayTriangleIntersectPt(CMVector3D<T> &vOut, const CMVector3D<T> &vertex1, const CMVector3D<T> &vertex2,
                             const CMVector3D<T> &vertex3, const CMVector3D<T> &orig, const CMVector3D<T> &dir, 
                             bool twoSided = false);
///////////////////////////////////////////////////////////////////////////////////////
template <class T>
bool CMIsRayIntersectTriangle(const CMVector3D<T> &vertex1, const CMVector3D<T> &vertex2,
                             const CMVector3D<T> &vertex3, const CMVector3D<T> &orig, const CMVector3D<T> &dir, 
                             bool twoSided = false);

///////////////////////////////////////////////////////////////////////////////////////
template <class T>
bool CMSegmentTriangleIntersectPt(CMVector3D<T> &vOut, const CMVector3D<T> &vertex1, const CMVector3D<T> &vertex2,
                                 const CMVector3D<T> &vertex3, const CMVector3D<T> &segPoint1, 
                                 const CMVector3D<T> &segPoint2);

///////////////////////////////////////////////////////////////////////////////////////
template <class T>
bool CMIsSegmentIntersectTriangle(const CMVector3D<T> &vertex1, const CMVector3D<T> &vertex2,
                                 const CMVector3D<T> &vertex3, const CMVector3D<T> &segPoint1, 
                                 const CMVector3D<T> &segPoint2);

///////////////////////////////////////////////////////////////////////////////////////
template <class T>
bool CMIsPointInsideTriangle(const CMVector3D<T> &point, const CMVector3D<T> &vertex1,
                              const CMVector3D<T> &vertex2, const CMVector3D<T> &vertex3);

///////////////////////////////////////////////////////////////////////////////////////
template <class T>
void CMTriangleNormal(CMVector3D<T> &norm, const CMVector3D<T> &p1, const CMVector3D<T> &p2,
                      const CMVector3D<T> &p3, bool bNormalize = true);

///////////////////////////////////////////////////////////////////////////////////////
template <class T>
void CMClosestPointOnLine(CMVector3D<T> &vOut, const CMVector3D<T> &A, const CMVector3D<T> &B,
                             const CMVector3D<T> &point, bool SegmentClamp = true);
///////////////////////////////////////////////////////////////////////////////////////


#endif //_3DMATH_H_
