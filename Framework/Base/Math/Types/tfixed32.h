///////////////////////////////////////////////////////////////////////////////////////
//  tfixed32.h
//
//  Math 32-bit Fixed Data Type Class
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
    static const int32t one = 1 << bits;
    static const int32t half = bits ? (1 << (bits-1)) : 0;

public:
    // Constructor Declarations
    tfixed32();
    tfixed32(const tfixed32<bits>& fx_val);
    tfixed32(const float f_val);
    tfixed32(const double d_val);
    tfixed32(const int32t i_val);

    
    // Cast To Pointer int32t *
    operator int32t* () const;
    operator const int32t* () const;

    // Cast To Primitive Build-in Types
    operator float() const;
    operator double() const;
    operator int32t() const;
    operator bool() const;
    
    // Assignment Operators
    tfixed32<bits>& operator = (const tfixed32<bits>& fx_val);
    tfixed32<bits>& operator += (const tfixed32<bits>& fx_val);
    tfixed32<bits>& operator -= (const tfixed32<bits>& fx_val);
    tfixed32<bits>& operator *= (const tfixed32<bits>& fx_val);
    tfixed32<bits>& operator /= (const tfixed32<bits>& fx_val);
    
    tfixed32<bits>& operator >>= (int32t i);
    tfixed32<bits>& operator <<= (int32t i);
    
    tfixed32<bits>& operator &= (int32t mask);
    tfixed32<bits>& operator |= (int32t mask);
    tfixed32<bits>& operator ^= (int32t mask);
    
    
    // Unary Operators
    tfixed32<bits> operator + () const;
    tfixed32<bits> operator - () const; 
    
    // Binary Operators
    tfixed32<bits> operator + (const tfixed32<bits> &fx_val) const;
    tfixed32<bits> operator - (const tfixed32<bits> &fx_val) const;
    tfixed32<bits> operator * (const tfixed32<bits> &fx_val) const;
    tfixed32<bits> operator / (const tfixed32<bits> &fx_val) const;
    
    tfixed32<bits> operator >> (int32t i) const;
    tfixed32<bits> operator << (int32t i) const;
    
    tfixed32<bits> operator & (int32t mask) const;
    tfixed32<bits> operator | (int32t mask) const;
    tfixed32<bits> operator ^ (int32t mask) const;
    
    bool operator == (const tfixed32<bits> &fx_val) const;
    bool operator != (const tfixed32<bits> &fx_val) const;
    
    bool operator <  (const tfixed32<bits> &fx_val) const;
    bool operator >  (const tfixed32<bits> &fx_val) const;
    
    bool operator <= (const tfixed32<bits> &fx_val) const;
    bool operator >= (const tfixed32<bits> &fx_val) const;
    
    bool operator && (const tfixed32<bits> &fx_val) const;
    bool operator || (const tfixed32<bits> &fx_val) const;
};
///////////////////////////////////////////////////////////////////////////////////////

template <int bits>
tfixed32<bits>::tfixed32():value(0){}
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed32<bits>::tfixed32(const tfixed32<bits>& fx_val):value(fx_val.value){}
/////////////////////////////////////////////////////////////////////////////////////// 
template <int bits>
tfixed32<bits>::tfixed32(const float f_val) 
{
    value = (int32t)(f_val * (float)one);
}
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed32<bits>::tfixed32(const double d_val) 
{
    value = (int32t)(d_val * (double)one);
}
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed32<bits>::tfixed32(const int32t i_val) 
{
    value = i_val << bits;
}

///////////////////////////////////////////////////////////////////////////////////////
//Cast To Pointer int32t *
template <int bits>
tfixed32<bits>::operator int32t* () const
{
    return (int32t*) this;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed32<bits>::operator const int32t* () const
{
    return (const int32t*) this;
}

///////////////////////////////////////////////////////////////////////////////////////
//Cast To Primitive Build-in Types
template <int bits>
tfixed32<bits>::operator float() const
{//return (float)v / (float)one;
    return (float)value / (float)one;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed32<bits>::operator double() const
{
    return (double)value / (double)one;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed32<bits>::operator int32t() const
{
    return value >> bits;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed32<bits>::operator bool() const
{
    return value != 0;
}

///////////////////////////////////////////////////////////////////////////////////////
// Assignment Operators
template <int bits>
tfixed32<bits>& tfixed32<bits>::operator = (const tfixed32<bits>& fx_val)
{
    value = fx_val.value;
    return *this;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed32<bits>& tfixed32<bits>::operator += (const tfixed32<bits>& fx_val)
{
    value += fx_val.value;
    return *this;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed32<bits>& tfixed32<bits>::operator -= (const tfixed32<bits>& fx_val)
{
    value -= fx_val.value;
    return *this;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed32<bits>& tfixed32<bits>::operator *= (const tfixed32<bits>& fx_val)
{
    //v = (long)(((long long)v * (long long)f.v + half) >> bits);
    value = (int32t)(((int64t)value * (int64t)fx_val.value + half) >> bits);
    return *this;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed32<bits>& tfixed32<bits>::operator /= (const tfixed32<bits>& fx_val)
{
    //v = (long)(((long long)v << bits) / (long long)f.v);
    value = (int32t)(((int64t)value << bits) / (int64t)fx_val.value);
    return *this;
}

///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed32<bits>& tfixed32<bits>::operator >>= (int32t i)
{
    value >>= i;
    return *this;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed32<bits>& tfixed32<bits>::operator <<= (int32t i)
{
    value <<= i;
    return *this;
}

///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed32<bits>& tfixed32<bits>::operator &= (int32t mask)
{
    value &= mask;
    return *this;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed32<bits>& tfixed32<bits>::operator |= (int32t mask)
{
    value |= mask;
    return *this;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed32<bits>& tfixed32<bits>::operator ^= (int32t mask)
{
    value ^= mask;
    return *this;
}
    
///////////////////////////////////////////////////////////////////////////////////////    
// Unary Operators
template <int bits>
tfixed32<bits> tfixed32<bits>::operator + () const
{
    tfixed32<bits> out;
    out.value = value;
    return out;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed32<bits> tfixed32<bits>::operator - () const
{
    tfixed32<bits> out;
	out.value = -value;
	return out;
}
    
///////////////////////////////////////////////////////////////////////////////////////    
// Binary Operators
template <int bits>
tfixed32<bits> tfixed32<bits>::operator + (const tfixed32<bits> &fx_val) const
{
    tfixed32<bits> out;
    out.value = value + fx_val.value;
    return out;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed32<bits> tfixed32<bits>::operator - (const tfixed32<bits> &fx_val) const
{
    tfixed32<bits> out;
    out.value = value - fx_val.value;
    return out;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed32<bits> tfixed32<bits>::operator * (const tfixed32<bits> &fx_val) const
{
    tfixed32<bits> out;
    out.value = (int32t)(((int64t)value * (int64t)fx_val.value + half) >> bits);
    return out;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed32<bits> tfixed32<bits>::operator / (const tfixed32<bits> &fx_val) const
{
    tfixed32<bits> out;
    out.value = (int32t)(((int64t)value << bits) / (int64t)fx_val.value);
    return out;
}

///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed32<bits> tfixed32<bits>::operator >> (int32t i) const
{
    tfixed32<bits> out;
    out.value = value >> i;
    return out;
}
///////////////////////////////////////////////////////////////////////////////////////    
template <int bits>
tfixed32<bits> tfixed32<bits>::operator << (int32t i) const
{
    tfixed32<bits> out;
    out.value = value << i;
    return out;
}

///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed32<bits> tfixed32<bits>::operator & (int32t mask) const
{
    tfixed32<bits> out;
    out.value = value & mask;
    return out;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed32<bits> tfixed32<bits>::operator | (int32t mask) const
{
    tfixed32<bits> out;
    out.value = value | mask;
    return out;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed32<bits> tfixed32<bits>::operator ^ (int32t mask) const
{
    tfixed32<bits> out;
    out.value = value ^ mask;
    return out;
}

///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
bool tfixed32<bits>::operator == (const tfixed32<bits> &fx_val) const
{
    return value == fx_val.value;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>   
bool tfixed32<bits>::operator != (const tfixed32<bits> &fx_val) const
{
    return value != fx_val.value;
}

///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
bool tfixed32<bits>::operator <  (const tfixed32<bits> &fx_val) const
{
    return value < fx_val.value;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
bool tfixed32<bits>::operator >  (const tfixed32<bits> &fx_val) const
{
    return value > fx_val.value;
}

///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
bool tfixed32<bits>::operator <= (const tfixed32<bits> &fx_val) const
{
    return value <= fx_val.value;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
bool tfixed32<bits>::operator >= (const tfixed32<bits> &fx_val) const
{
    return value >= fx_val.value;
}

///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
bool tfixed32<bits>::operator && (const tfixed32<bits> &fx_val) const
{
    return value && fx_val.value;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
bool tfixed32<bits>::operator || (const tfixed32<bits> &fx_val) const
{
    return value || fx_val.value;
}
///////////////////////////////////////////////////////////////////////////////////////

#endif //__TFIXED32_H__