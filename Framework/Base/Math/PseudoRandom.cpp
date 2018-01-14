///////////////////////////////////////////////////////////////////////////////////////
// PseudoRandom.cpp
//
// Pseudo random number generation functions
// Generates values in range -1,1
//
///////////////////////////////////////////////////////////////////////////////////////

#include <math.h>

#include "Base/Common/PlatformTypes.h"
#include "MathConst.h"
#include "MathLibDefs.h"
#include "PseudoRandom.h"

///////////////////////////////////////////////////////////////////////////////////////
// Pseudo Random Number Generation Function
float mprng(int32t x)
{
    int32t n = (x << 13) ^ x;
    
    return (1.0f - ((n*(n*n*15731 + 789221) + 1376312589) & 0x7fffffff) / 1073741824.0f);
}

///////////////////////////////////////////////////////////////////////////////////////
// Pseudo Random Number Generation Function
float mprng(int32t x, int32t y)
{
    int32t n = x + y * 57;
    n = (n << 13) ^ n;
    
    return (1.0f - ((n*(n*n*15731 + 789221) + 1376312589) & 0x7fffffff) / 1073741824.0f);
}

///////////////////////////////////////////////////////////////////////////////////////
// Pseudo Random Number Generation Function
float mprng(int32t x, int32t y, int32t z)
{
    int32t n = x + y * 57 + z * 131;
    n = (n << 13) ^ n;
    
    return (1.0f - ((n*(n*n*15731+789221) + 1376312589) & 0x7fffffff) / 1073741824.0f);
}

///////////////////////////////////////////////////////////////////////////////////////


/*
inline float SmoothNoise1D(int x)
{
	return Noise1D(x)/2 + Noise1D(x-1)/4 + Noise1D(x+1)/4;
}

inline float SmoothNoise2D(int x, int y)
{
	float corners = (Noise2D(x-1,y-1) + Noise2D(x+1,y-1) + Noise2D(x-1,y+1) + Noise2D(x+1,y+1))/16;
	float sides = (Noise2D(x+1,y) + Noise2D(x-1,y) + Noise2D(x,y+1) + Noise2D(x,y-1))/8;
	float center = Noise2D(x,y)/4;

	return corners + sides + center;
}

inline float SmoothNoise2DIn3D(int x, int y, int z)
{
	float corners = (Noise3D(x-1,y-1,z) + Noise3D(x+1,y-1,z) + Noise3D(x-1,y+1,z) + Noise3D(x+1,y+1,z))/16;
	float sides = (Noise3D(x+1,y,z) + Noise3D(x-1,y,z) + Noise3D(x,y+1,z) + Noise3D(x,y-1,z))/8;
	float center = Noise3D(x,y,z)/4;

	return corners + sides + center;
}

inline float SmoothNoise3D(int x, int y, int z)
{
	float corners = (Noise3D(x-1,y-1,z+1) + Noise3D(x+1,y-1,z+1) + Noise3D(x-1,y+1,z+1) +
						Noise3D(x+1,y+1,z+1) + Noise3D(x+1,y,z+1) + Noise3D(x-1,y,z+1) +
						Noise3D(x,y+1,z+1) + Noise3D(x,y-1,z+1) +
					Noise3D(x-1,y-1,z) + Noise3D(x+1,y-1,z) + Noise3D(x-1,y+1,z) +
						Noise3D(x+1,y+1,z) +
					Noise3D(x-1,y-1,z-1) + Noise3D(x+1,y-1,z-1) + Noise3D(x-1,y+1,z-1) +
						Noise3D(x+1,y+1,z-1) + Noise3D(x+1,y,z-1) + Noise3D(x-1,y,z-1) +
						Noise3D(x,y+1,z-1) + Noise3D(x,y-1,z-1)
						)/32;

	float sides = (Noise3D(x,y,z+1) + Noise3D(x+1,y,z) + Noise3D(x-1,y,z) +
					Noise3D(x,y+1,z) + Noise3D(x,y-1,z) + Noise3D(x,y,z-1))/24;

	float center = Noise3D(x,y,z)/8;
	
	return corners + sides + center;
}

//1D Noise Generation Function
float noise (float x)
{
	int xinteger = int(x);
	float fractionx = x - float(xinteger);
	float v1,v2;
	
	v1 = SmoothNoise1D(xinteger);
	v2 = SmoothNoise1D(xinteger+1);

	return cosp(v1,v2,fractionx);
}

//2D Noise Generation Function
float noise(float x, float y)
{
	int xinterger = int(x);
	float fractionx = x - float(xinterger);
	int yinteger = int(y);
	float fractiony = y - float(yinteger);
	float v1,v2,v3,v4,i1,i2;
	float ret;

	v1 = SmoothNoise2D(xinterger, yinteger);
	v2 = SmoothNoise2D(xinterger + 1, yinteger);
	v3 = SmoothNoise2D(xinterger, yinteger + 1);
	v4 = SmoothNoise2D(xinterger + 1, yinteger + 1);
	i1 = cosp (v1,v2,fractionx);
	i2 = cosp (v3,v4,fractionx);
	ret = cosp (i1,i2,fractiony);

	return ret;
}

//3D Noise Generation Function
float noise(float x, float y, float z, bool Use2DSmooth)
{
	int xinterger = int(x);
	float fractionx = x - float(xinterger);
	int yinteger = int(y);
	float fractiony = y - float(yinteger);
	int zinteger = int(z);
	float fractionz = z - float(zinteger);
	float v1,v2,v3,v4,v5,v6,v7,v8, i1,i2,ires1, i3,i4,ires2;
	float ret;

	float (*fpfun)(int,int,int);
	if(Use2DSmooth)
		fpfun = SmoothNoise2DIn3D;
	else
		fpfun = SmoothNoise3D;

	v1 = fpfun(xinterger, yinteger, zinteger);
	v2 = fpfun(xinterger + 1, yinteger, zinteger);
	v3 = fpfun(xinterger, yinteger + 1, zinteger);
	v4 = fpfun(xinterger + 1, yinteger + 1, zinteger);

	v5 = fpfun(xinterger, yinteger, zinteger + 1);
	v6 = fpfun(xinterger + 1, yinteger, zinteger + 1);
	v7 = fpfun(xinterger, yinteger + 1, zinteger + 1);
	v8 = fpfun(xinterger + 1, yinteger + 1, zinteger + 1);

	i1 = cosp (v1,v2,fractionx);
	i2 = cosp (v3,v4,fractionx);
	ires1 = cosp (i1,i2,fractiony);

	i3 = cosp (v5,v6,fractionx);
	i4 = cosp (v7,v8,fractionx);
	ires2 = cosp (i3,i4,fractiony);

	ret = cosp (ires1,ires2,fractionz);

	return ret;
}

//Fractal Brownian Motion
//FBM Fractal in 2d 
float FBM(float x, float y, int octaves, float amplitude, float frequence, float h)
{
	float ret = 0;
	for(int i=0; i<octaves; i++)
	{
		ret += noise(x*frequence, y*frequence)*amplitude;
		amplitude *= h;
		//frequence /= h;
	}
	return ret;
}

//FBM fractal in 3d
float FBM(float x, float y, float z, int octaves, float amplitude, float frequence, 
		  float h, bool Use2DSmooth)
{
	float ret = 0;
	for(int i=0; i<octaves; i++)
	{
		ret += noise(x*frequence, y*frequence, z*frequence, Use2DSmooth)*amplitude;
		amplitude *= h;
		//frequence /= h;
	}
	return ret;
}

//Multifractal in 2d
float MultiFractal(float x, float y, int octaves, float amplitude, float frequence, float h,
				   float offset)
{
	float ret = 1;
	for(int i=0; i<octaves; i++)
	{
		ret *= offset*(noise(x*frequence,y*frequence)*amplitude);
		amplitude *= h;
	}

	return ret;
}

//Multifractal in 3d
float MultiFractal(float x, float y, float z, int octaves, float amplitude, float frequence,
				   float h, float offset, bool Use2DSmooth)
{
	float ret = 1;
	for(int i=0; i<octaves; i++)
	{
		ret *= offset*(noise(x*frequence,y*frequence,z*frequence,Use2DSmooth)*amplitude);
		amplitude *= h;
	}

	return ret;
}
*/