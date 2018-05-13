///////////////////////////////////////////////////////////////////////////////////////
// Prng.h
//
// Pseudo random number generation functions
// Generates values in range -1,1
//
///////////////////////////////////////////////////////////////////////////////////////

#ifndef __PSEUDORANDOM_H__
#define __PSEUDORANDOM_H__

///////////////////////////////////////////////////////////////////////////////////////
float mprng(int32t x);
///////////////////////////////////////////////////////////////////////////////////////
float mprng(int32t x, int32t y);
///////////////////////////////////////////////////////////////////////////////////////
float mprng(int32t x, int32t y, int32t z);
///////////////////////////////////////////////////////////////////////////////////////
float mprng(int32t x, int32t y, int32t z, int32t w);
///////////////////////////////////////////////////////////////////////////////////////

/*
//Noise Smooth Functions
float SmoothNoise1D(int x);
float SmoothNoise2D(int x, int y);
float SmoothNoise3D(int x, int y, int z);

//Noise Generation Functions
float noise(float x);
float noise(float x, float y);
float noise(float x, float y, float z, bool Use2DSmooth=false);

//Fractal Brownian Motion Noise
float FBM(float x, float y, int octaves, float amplitude, float frequence, float h);
float FBM(float x, float y, float z, int octaves, float amplitude, float frequence, 
		  float h, bool Use2DSmooth=false);

//Multifractals
float MultiFractal(float x, float y, int octaves, float amplitude, float frequence, float h,
				   float offset);
float MultiFractal(float x, float y, float z, int octaves, float amplitude, float frequence,
				   float h, float offset, bool Use2DSmooth=false);

*/

#endif //__PSEUDORANDOM_H__