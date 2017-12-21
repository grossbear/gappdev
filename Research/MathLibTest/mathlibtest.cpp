#include <stdio.h>
#include "Base/Math/MathLib.h"

int main()
{
    printf("MathLib test programm\n");
    
    CMVector3D<float> pt1(0.0f, 2.0f, 0.0f);
    CMVector3D<float> pt2(0.0f, 0.0f, 0.0f);
    CMVector3D<float> pt3(2.0f, 0.0f, 0.0f);
    
    CMPlane<float> plane(pt1,pt2,pt3);
    
    printf("plane coeff: a = %.5f, b = %.5f, c= %.5f, d = %.5f\n",plane.a,plane.b,plane.c,plane.d);
    
    CMVector3D<float> interpr;
    cvec3f pt(1.0f, 1.0f, 1.0f);
    cvec3f dir(0.0f, 0.0f, -1.0f);
    bool result = CMPlaneLineIntersect(interpr, plane, pt, dir);
    
    printf("intersection point: x = %.5f, y = %.5f, z = %.5f\n",interpr.x, interpr.y, interpr.z);
    
    return 0;
}
