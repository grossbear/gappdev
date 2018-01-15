// Perlin Noise Tables Generator

#include <iostream>
#include <string>
#include "prng.h"

//Two Operations Must Be Equal (Value % NOISE_WRAP_INDEX) == (Value & NOISE_MOD_MASK)
//So NOISE_WRAP_INDEX Must Be A Power Of Two And NOISE_MOD_MASK Must Be A Power Of 2-1
//If We Implement Indeces As Unsigned Chars, So NOISE_WRAP_INDEX Should Be Less Than Or 
//Equal To 256. There's No Good Reason To Change It From 256.

#define NOISE_WRAP_INDEX	256
#define NOISE_MOD_MASK		255

// A Large Power Of Two 2, We'll Go For 4096, to Add To Negative Numbers
// In Order To Make Them Positive
#define NOISE_LARGE_PWR2 4096



int main()
{
    std::cout << "Perlin Noise Tables Gen Programme\n";
    
    int x = 568;
    float genval = mprng(x);
     
    std::cout << "generated value: " << genval << std::endl;
    
    std::string strval = std::to_string(genval);
    std::cout << "gen value string: " << strval << std::endl;

    return 0;
}


/*
CPerlinNoiseMap::CPerlinNoiseMap()
{
	ImgSize = 64;
	UsePalette = true;
	GradientTable1D = new float[2*NOISE_WRAP_INDEX+2];
	GradientTable2D = new Vector2D[2*NOISE_WRAP_INDEX+2];
	GradientTable3D = new Vector3D[2*NOISE_WRAP_INDEX+2];
	Reseed();
	//Creating Image
	NoiseImage = new CImage();
	NoiseImage->Create(FORMAT_RGB8,ImgSize,ImgSize,1);
	//Setting Default Color Values To Black And White
	//memset(&Color1,0,sizeof(float)*3);
	Color1[0] = 0.0f; Color1[1] = 0.0f; Color1[2] = 0.5f;
	Color2[0] = 0.0f; Color2[1] = 0.8f; Color2[2] = 1.0f;

	fdata = new float[ImgSize*ImgSize];

	//Noise Parameters
	Iterations = 1;
	Amplitude = 1.0f;
	Persistence = 0.5f;
	Frequency = 4.0f;
	//Marble1 Params: SinSumAbsNoise, Freq=1,Scale=5,SinScale=1,SinValScale=1
	//Marble2 Params: Freq=1,Scale=3,Iter=4,SinScale=4,SinValScale=2,SinSumNoise
	//Marble3 Params: Iter=1-4,Freq=1-4,Scale=3,SinScale=9,SinValScale=1,SinSumAbsNoise
	//Energy Params: Freq=4,Iter=1,Scale=1-3,SinScale=6-9,SinValScale=3,SinSumNoise
	xScale=yScale=zScale=1.0f;
	
	xSinOffset = 0.0f;
	SinScale = 1.0f;
	SinValScale = 1.0f;

	RingFreq = 4.0f;

	//Creating Greyscale Palette
	Palette = new ubyte[1024];
	ubyte *ptr = Palette;
	for(int i=0; i<256; i++)
	{
		*ptr++ = i;
		*ptr++ = i;
		*ptr++ = i;
		*ptr++ = i;
	}

	//Set Function Pointer To Default Noise Gen Method
	pfNoise = & CPerlinNoiseMap::fabsNoise;
}

CPerlinNoiseMap::~CPerlinNoiseMap()
{
	delete [] GradientTable1D;
	delete [] GradientTable2D;
	delete [] GradientTable3D;

	delete [] Palette;
	delete (NoiseImage);

	delete [] fdata;
}

// Setup Some Values For Noise Generation
inline void CPerlinNoiseMap::SetupValues(float &t,int axis,int &b0,int &b1,float &r0,float &r1,float *vec)
{
	t = vec[axis] + NOISE_LARGE_PWR2;
	b0 = ((int)t) & NOISE_MOD_MASK;
	b1 = (b0+1) & NOISE_MOD_MASK;
	r0 = t - (int)t;
	r1 = r0 - 1.0f;
}

// Return A Random Float In [-1,1]
inline float CPerlinNoiseMap::RandFloat()
{
	return (float)(( rand() % (NOISE_WRAP_INDEX + NOISE_WRAP_INDEX)) 
			- NOISE_WRAP_INDEX) / NOISE_WRAP_INDEX;
}

//Reseed Random Generator And Generate Gradient Table
void CPerlinNoiseMap::Reseed()
{
	srand(351);
	GenerateLookupTables();
}

//Same But With Specified Seed
void CPerlinNoiseMap::Reseed(unsigned int Seed) 
{
	srand(Seed);
	GenerateLookupTables();
}

// Fill Up Gradient And Permutation Tables
void CPerlinNoiseMap::GenerateLookupTables()
{
	int i,j,k;
	
	for(i=0; i<NOISE_WRAP_INDEX; i++)
	{
		//Put Index Into Permutation Table
		PermutationTable[i]=i;

		GradientTable1D[i] = RandFloat();

		//Generate A Random 2D Gradient Vector
		GradientTable2D[i].x = RandFloat();
		GradientTable2D[i].y = RandFloat();
		GradientTable2D[i].Normalize();

		//Generate A Random 3D Gradient Vector
		GradientTable3D[i].x = RandFloat();
		GradientTable3D[i].y = RandFloat();
		GradientTable3D[i].z = RandFloat();
		GradientTable3D[i].Normalize();
	}

	//Shuffle Permutation Table Up To NOISE_WRAP_INDEX
	while(--i)
	{
		k = PermutationTable[i];
		PermutationTable[i] = PermutationTable[ j = rand() & NOISE_MOD_MASK ];
		PermutationTable[j] = k;
	}

	//Add The Rest Of The Tables Entries In. 
	//Duplicating Indices And Entries So They Can Effectively Be Indexed
	//By Unsigned Chars
	for(i=0; i<NOISE_WRAP_INDEX+2; i++)
	{
		PermutationTable[NOISE_WRAP_INDEX + i] = PermutationTable[i];

		GradientTable1D[NOISE_WRAP_INDEX + i] = GradientTable1D[i];

		GradientTable2D[NOISE_WRAP_INDEX + i].x = GradientTable2D[i].x;
		GradientTable2D[NOISE_WRAP_INDEX + i].y = GradientTable2D[i].y;

		GradientTable3D[NOISE_WRAP_INDEX + i].x = GradientTable3D[i].x;
		GradientTable3D[NOISE_WRAP_INDEX + i].y = GradientTable3D[i].y;
		GradientTable3D[NOISE_WRAP_INDEX + i].z = GradientTable3D[i].z;
	}
}

// Variables Used In Noise Functions
// bx0 - Left Grid Point In X Coord
// bx1 - Right Grid Point In X Coord
// rx0 - Distance From Left Grid Point
// rx1 - Distance From Right Grid Point
// Same With Y And Z Coords

//Method Creates 1-Dimensional Coherent Noise
float CPerlinNoiseMap::noise1(float Val)
{
	int bx0, bx1;
	float rx0,rx1,sX,t,u,v;

	//Find Out Neighboring Grid Points To Position Vector
	//And Signed Distances From Position To Them
	SetupValues(t, 0, bx0, bx1, rx0, rx1, &Val);

	sX = s_curve(rx0);

	//u and v Are The Vectors From The Grid Points Times The Random
	//Gradients For The Grid Points. They Are Actually Dot Products,
	//But This Looks Like Scalar Multiplication
	u = rx0*GradientTable1D[PermutationTable[bx0]];
	v = rx1*GradientTable1D[PermutationTable[bx1]];

	//Return The Linear Interpolation Between u And v At sX
	return lerp(u,v,sX);
}

//Create 2D Coherent Noise
float CPerlinNoiseMap::noise2(float vec[2])
{
	int bx0,bx1,by0,by1,b00,b10,b01,b11;
	float rx0,rx1,ry0,ry1,sX,sY,a,b,t,u,v;
	register int IndexL,IndexR;

	//Find Out Neighboring Grid Points To Position Vector
	//And Signed Distances From Position To Them
	SetupValues(t, 0, bx0, bx1, rx0, rx1, vec);
	SetupValues(t, 1, by0, by1, ry0, ry1, vec);

	//Generate Some Temporary Indices Associated With The Left And Right Grid Values
	IndexL = PermutationTable[bx0];
	IndexR = PermutationTable[bx1];
	
	//Generate Indices In The Permutation Table For All 4 Corners
	b00 = PermutationTable[IndexL + by0];
	b10 = PermutationTable[IndexR + by0];
	b01 = PermutationTable[IndexL + by1];
	b11 = PermutationTable[IndexR + by1];

	//Get S Curves At The Proper Values
	sX = s_curve(rx0);
	sY = s_curve(ry0);

	//Do The Dor Product For The Left And Lower Right Corners.
	//Interpolate Between Those Dot Products Value sX To Get a.
	u = DotProduct(Vector2D(rx0,ry0), GradientTable2D[b00]);
	v = DotProduct(Vector2D(rx1,ry0), GradientTable2D[b10]);
	a = lerp(u,v,sX);
	
	//Do The Dot Product For The Upper Left And Upper Right Corners
	//Interpolate Between Those Dot Products Value sX To Get b.
	u = DotProduct(Vector2D(rx0,ry1), GradientTable2D[b01]);
	v = DotProduct(Vector2D(rx1,ry1), GradientTable2D[b11]);
	b = lerp(u,v,sX);

	//Interpolate Between a And b At Value sY To Get The Noise Return Value
	return lerp(a,b,sY);
}

//Create 3D Coherent Noise
float CPerlinNoiseMap::noise3(float vec[3])
{
	int bx0,bx1,by0,by1,bz0,bz1,b00,b10,b01,b11;
	float rx0,rx1,ry0,ry1,rz0,rz1,sX,sY,sZ,a,b,c,d,t,u,v;
	register int IndexL,IndexR;

	//Find Out Neighboring Grid Points To Position And Signed Distances From Position To Them
	SetupValues(t, 0, bx0, bx1, rx0, rx1, vec);
	SetupValues(t, 1, by0, by1, ry0, ry1, vec);
	SetupValues(t, 2, bz0, bz1, rz0, rz1, vec);

	IndexL = PermutationTable[bx0];
	IndexR = PermutationTable[bx1];

	b00 = PermutationTable[IndexL + by0];
	b10 = PermutationTable[IndexR + by0];
	b01 = PermutationTable[IndexL + by1];
	b11 = PermutationTable[IndexR + by1];

	sX = s_curve(rx0);
	sY = s_curve(ry0);
	sZ = s_curve(rz0);

	u = DotProduct(Vector3D(rx0,ry0,rz0), GradientTable3D[b00+bz0]);
	v = DotProduct(Vector3D(rx1,ry0,rz0), GradientTable3D[b10+bz0]);
	a = lerp(u,v,sX);

	u = DotProduct(Vector3D(rx0,ry1,rz0), GradientTable3D[b01+bz0]);
	v = DotProduct(Vector3D(rx1,ry1,rz0), GradientTable3D[b11+bz0]);
	b = lerp(u,v,sX);

	c = lerp(a,b,sY);

	u = DotProduct(Vector3D(rx0,ry0,rz1), GradientTable3D[b00+bz1]);
	v = DotProduct(Vector3D(rx1,ry0,rz1), GradientTable3D[b10+bz1]);
	a = lerp(u,v,sX);

	u = DotProduct(Vector3D(rx0,ry1,rz1), GradientTable3D[b01+bz1]);
	v = DotProduct(Vector3D(rx1,ry1,rz1), GradientTable3D[b11+bz1]);
	b = lerp(u,v,sX);

	d = lerp(a,b,sY);

	return lerp(c,d,sZ);
}
*/


