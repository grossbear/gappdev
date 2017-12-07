///////////////////////////////////////////////////////////////////////////////////////
//  tfixed32.h
//
//  Math Fixed32 Type Class
//  
//
///////////////////////////////////////////////////////////////////////////////////////

#ifndef __TFIXED32_H__
#define __TFIXED32_H__

///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
class tfixed32
{
protected:
    int32t value;

public:
    tfixed32();
    tfixed32(const tfixed32<bits>& fx_val);
    tfixed32(const float f_val);
    tfixed32(const double d_val);
    tfixed32(const int32t i_val);
    
    int32t get(){return value;}
};
///////////////////////////////////////////////////////////////////////////////////////

template <int32t bits>
tfixed32<bits>::tfixed32():value(0){}
///////////////////////////////////////////////////////////////////////////////////////
template <int32t bits>
tfixed32<bits>::tfixed32(const tfixed32<bits>& fx_val):value(fx_val.value){}
/////////////////////////////////////////////////////////////////////////////////////// 
template <int32t bits>
tfixed32<bits>::tfixed32(const float f_val) 
{
    value = (int32t)f_val;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int32t bits>
tfixed32<bits>::tfixed32(const double d_val) 
{
    value = (int32t)d_val;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int32t bits>
tfixed32<bits>::tfixed32(const int32t i_val) 
{
    value = i_val;
}
///////////////////////////////////////////////////////////////////////////////////////

#endif //__TFIX32_H__

/*
#ifndef __TFIX32_H
#define __TFIX32_H

template<int bits> class TFix32
{
	template<int> friend class TFix32;
protected:
	long v;
	static const long one	= 1 << bits;
	static const long half	= bits ? (1 << (bits-1)) : 0;
public:
	TFix32() {}
	TFix32<bits>(const TFix32<bits>& f) { v = f.v; }
	TFix32<bits>(float f) { *this = f; }
	TFix32<bits>(double d) { *this = d; }
	TFix32<bits>(int i) { *this = i; }
	template<int b>
	TFix32<bits>(const TFix32<b>& f) { *this = f; }
	inline TFix32<bits>& operator=(float f);
	inline TFix32<bits>& operator=(double d);
	inline TFix32<bits>& operator=(int i);

	template<int b>
	inline TFix32<bits>& operator=(const TFix32<b>& f) {
		if(bits > b)				// This branch is
			v = f.v << (bits - b);	// evaluated during
		else if(bits < b)			// compile time only,
			v = f.v >> (b - bits);	// because template
		else						// parameters are known
			v = f.v;
		return *this;
	}
	inline void Raw(long Raw) { v = Raw; }
	inline long Raw() const { return v; }
	static inline long MaxInteger() { return (1 << (31 - bits)) -1; }
	static inline float MinMantissa() { return 1.f / (float)one; }
	inline float ToFloat() const { return (float)v / (float)one; }
	inline double ToDouble() const { return (double)v / (double)one; }
	inline int ToInt() const { return v >> bits; }
// 	inline operator float() const { return ToFloat(); } 
// 	inline operator double() const { return ToDouble(); } 
	inline operator int() const { return ToInt(); }
	inline TFix32<bits> operator-() const;
	inline TFix32<bits> operator~() const;
	inline TFix32<bits>& operator+=(const TFix32<bits>& f);
	inline TFix32<bits>& operator-=(const TFix32<bits>& f);
	inline TFix32<bits>& operator*=(const TFix32<bits>& f);
	inline TFix32<bits>& operator/=(const TFix32<bits>& f);
	inline TFix32<bits> operator>>(int i);
	inline TFix32<bits> operator<<(int i);
	inline TFix32<bits>& operator>>=(int i);
	inline TFix32<bits>& operator<<=(int i);

	template<int b1, int b2>
	static inline TFix32<bits> MUL(const TFix32<b1> f1, const TFix32<b2> f2) {
		TFix32<bits> out;
		if(b2 + b1 - bits > 0)
			out.v = (long)(((long long)f2.v * (long long)f1.v + half) >> (b2 + b1 - bits));
		else
			out.v = (long)(((long long)f2.v * (long long)f1.v + half) << (b2 + b1 - bits));
		return out;
	}


	template<int b1, int b2>
	static inline TFix32<bits> ADD(const TFix32<b1> f1, const TFix32<b2> f2) {
		// This complex branch reduces to a single instruction
		// in compiled code because all the template parameters
		// are known at compile time
		TFix32<bits> out;
		if(b2 > b1)
			if(bits > b2)
				out.v = (long)(((long long)f2.v << (bits - b2)) + ((long long)f1.v << (bits - b1)));
			else if(bits < b2)
				out.v = (long)(((long long)f2.v + ((long long)f1.v << (b2 - b1))) >> (b2 - bits));
			else
				out.v = (long)((long long)f2.v + ((long long)f1.v << (b2 - b1)));
		else if(b1 > b2)
			if(bits > b1)
				out.v = (long)(((long long)f2.v << (bits - b2)) + ((long long)f1.v << (bits - b1)));
			else if(bits < b1)
				out.v = (long)((((long long)f2.v << (b1 - b2)) + (long long)f1.v) >> (b1 - bits));
			else
				out.v = (long)(((long long)f2.v << (b1 - b2)) + (long long)f1.v);
		else // (b2 == b1)
			if(bits > b2)
				out.v = (long)(((long long)f2.v << (bits - b2)) + ((long long)f1.v << (bits - b1)));
			else if(bits < b2)
				out.v = (long)(((long long)f2.v + (long long)f1.v) >> (b2 - bits));
			else
				out.v = (long)(((long long)f2.v) + ((long long)f1.v));
		return out;
	}

	template<int b1, int b2>
	static inline TFix32<bits> SUB(const TFix32<b1> f1, const TFix32<b2> f2) {
		// This complex branch reduces to a single instruction
		// in compiled code because all the template parameters
		// are known at compile time
		TFix32<bits> out;
		if(b1 > b2)
			if(bits > b1)
				out.v = (long)(((long long)f1.v << (bits - b1)) - ((long long)f2.v << (bits - b2)));
			else if(bits < b1)
				out.v = (long)(((long long)f1.v - ((long long)f2.v << (b1 - b2))) >> (b1 - bits));
			else
				out.v = (long)((long long)f1.v - ((long long)f2.v << (b1 - b2)));
		else if(b2 > b1)
			if(bits > b2)
				out.v = (long)(((long long)f1.v << (bits - b1)) - ((long long)f2.v << (bits - b2)));
			else if(bits < b2)
				out.v = (long)((((long long)f1.v << (b2 - b1)) - (long long)f2.v) >> (b2 - bits));
			else
				out.v = (long)(((long long)f1.v << (b2 - b1)) - (long long)f2.v);
		else // (b1 == b2)
			if(bits > b1)
				out.v = (long)(((long long)f1.v << (bits - b1)) - ((long long)f2.v << (bits - b2)));
			else if(bits < b1)
				out.v = (long)(((long long)f1.v - (long long)f2.v) >> (b1 - bits));
			else
				out.v = (long)(((long long)f1.v) - ((long long)f2.v));
		return out;
	}

};


//Implementation of template member functions


template<int bits>
inline TFix32<bits>& TFix32<bits>::operator=(float f) {
	v = (long)(f * (float)one);
	return *this;
}

template<int bits>
inline TFix32<bits>& TFix32<bits>::operator=(double d) {
	v = (long)(d * (double)one);
	return *this;
}

template<int bits>
inline TFix32<bits>& TFix32<bits>::operator=(int i) {
	v = (long)(i * (int)one);
	return *this;
}


template<int bits>
inline TFix32<bits> TFix32<bits>::operator-() const {
	TFix32<bits> out;
	out.v = -v;
	return out;
}

template<int bits>
inline TFix32<bits> TFix32<bits>::operator~() const {
	TFix32<bits> out;
	out.v = ~v;
	return out;
}

template<int bits>
inline TFix32<bits>& TFix32<bits>::operator+=(const TFix32<bits>& f) {
	v += f.v;
	return *this;
}

template<int bits>
inline TFix32<bits>& TFix32<bits>::operator-=(const TFix32<bits>& f) {
	v -= f.v;
	return *this;
}

template<int bits>
inline TFix32<bits>& TFix32<bits>::operator*=(const TFix32<bits>& f) {
	v = (long)(((long long)v * (long long)f.v + half) >> bits);
	return *this;
}

template<int bits>
inline TFix32<bits>& TFix32<bits>::operator/=(const TFix32<bits>& f) {
	v = (long)(((long long)v << bits) / (long long)f.v);
	return *this;
}

template<int bits>
inline TFix32<bits>& TFix32<bits>::operator>>=(int i) {
	v >>= i;
	return *this;
}

template<int bits>
inline TFix32<bits>& TFix32<bits>::operator<<=(int i) {
	v <<= i;
	return *this;
}

template<int bits>
inline TFix32<bits> TFix32<bits>::operator>>(int i) {
	TFix32<bits> out;
	out.v = v >> i;
	return out;
}

template<int bits>
inline TFix32<bits> TFix32<bits>::operator<<(int i) {
	TFix32<bits> out;
	out.v = v << i;
	return out;
}

template<int bits>
inline TFix32<bits> operator+(const TFix32<bits>& a, const TFix32<bits>& b) {
	TFix32<bits> out(a);
	return out += b;
}

template<int bits>
inline TFix32<bits> operator-(const TFix32<bits>& a, const TFix32<bits>& b) {
	TFix32<bits> out(a);
	return out -= b;
}

template<int bits>
inline TFix32<bits> operator*(const TFix32<bits>& a, const TFix32<bits>& b) {
	TFix32<bits> out(a);
	return out *= b;
}

template<int bits>
inline TFix32<bits> operator/(const TFix32<bits>& a, const TFix32<bits>& b) {
	TFix32<bits> out(a);
	return out /= b;
}

template<int b1, int b2>
inline bool operator<(const TFix32<b1>& a, const TFix32<b2>& b) {
	if(b1 > b2)
		return ((long long)a.Raw()) < ((long long)b.Raw() << (b1 - b2));
	else if (b1 < b2)
		return ((long long)a.Raw() << (b2 - b1)) < ((long long)b.Raw());
	else
		return a.Raw() < b.Raw();
}

template<int b1, int b2>
inline bool operator>(const TFix32<b1>& a, const TFix32<b2>& b) {
	if(b1 > b2)
		return ((long long)a.Raw()) > ((long long)b.Raw() << (b1 - b2));
	else if (b1 < b2)
		return ((long long)a.Raw() << (b2 - b1)) > ((long long)b.Raw());
	else
		return a.Raw() > b.Raw();
}

template<int b1, int b2>
inline bool operator<=(const TFix32<b1>& a, const TFix32<b2>& b) {
	if(b1 > b2)
		return ((long long)a.Raw()) <= ((long long)b.Raw() << (b1 - b2));
	else if (b1 < b2)
		return ((long long)a.Raw() << (b2 - b1)) <= ((long long)b.Raw());
	else
		return a.Raw() <= b.Raw();
}

template<int b1, int b2>
inline bool operator>=(const TFix32<b1>& a, const TFix32<b2>& b) {
	if(b1 > b2)
		return ((long long)a.Raw()) >= ((long long)b.Raw() << (b1 - b2));
	else if (b1 < b2)
		return ((long long)a.Raw() << (b2 - b1)) >= ((long long)b.Raw());
	else
		return a.Raw() >= b.Raw();
}

template<int b1, int b2>
inline bool operator==(const TFix32<b1>& a, const TFix32<b2>& b) {
	if(b1 > b2)
		return ((long long)a.Raw()) == ((long long)b.Raw() << (b1 - b2));
	else if (b1 < b2)
		return ((long long)a.Raw() << (b2 - b1)) == ((long long)b.Raw());
	else
		return a.Raw() == b.Raw();
}

template<int b1, int b2>
inline bool operator!=(const TFix32<b1>& a, const TFix32<b2>& b) {
	return !(a == b);
}


*/