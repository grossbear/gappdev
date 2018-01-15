// Pseudo Random Number Generator

float mprng(int x)
{
    int n = (x << 13) ^ x;
    
    return (1.0f - ((n*(n*n*15731 + 789221) + 1376312589) & 0x7fffffff) / 1073741824.0f);  
}

float mprng(int x, int y)
{
    int n = x + y * 57;
    n = (n << 13) ^ n;
    
    return (1.0f - ((n*(n*n*15731 + 789221) + 1376312589) & 0x7fffffff) / 1073741824.0f);
}

float mprng(int x, int y, int z)
{
    int n = x + y*57 + z*131;
	n = (n<<13) ^ n;

	return (1.0f - ((n*(n*n*15731+789221) + 1376312589) & 0x7fffffff) / 1073741824.0f);
}
