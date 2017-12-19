///////////////////////////////////////////////////////////////////////////////////////
//  tfixed64.h
//
//  Math Fixed64 Type Class
//  
//
///////////////////////////////////////////////////////////////////////////////////////

#ifndef __TFIXED64_H__
#define __TFIXED64_H__

///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
class tfixed64
{
protected:
    int64t value;
    static const int64t one = 1 << bits;
    static const int64t half = bits ? (1 << (bits-1)) : 0;

public:
    // Constructor Declarations
    tfixed64();
    tfixed64(const tfixed64<bits>& fx_val);
    tfixed64(const float f_val);
    tfixed64(const double d_val);
    tfixed64(const int64t i_val);

    
    // Cast To Pointer int64t *
    operator int64t* () const;
    operator const int64t* () const;

    // Cast To Primitive Build-in Types
    operator float();
    operator double();
    operator int64t();
    
    // Assignment Operators
    tfixed64<bits>& operator = (const tfixed64<bits>& fx_val);
    tfixed64<bits>& operator += (const tfixed64<bits>& fx_val);
    tfixed64<bits>& operator -= (const tfixed64<bits>& fx_val);
    tfixed64<bits>& operator *= (const tfixed64<bits>& fx_val);
    tfixed64<bits>& operator /= (const tfixed64<bits>& fx_val);
    
    tfixed64<bits>& operator >>= (int64t i);
    tfixed64<bits>& operator <<= (int64t i);
    
    
    // Unary Operators
    tfixed64<bits>& operator + () const;
    tfixed64<bits>& operator - () const; 
    
    // Binary Operators
    tfixed64<bits> operator + (const tfixed64<bits> &fx_val) const;
    tfixed64<bits> operator - (const tfixed64<bits> &fx_val) const;
    tfixed64<bits> operator * (const tfixed64<bits> &fx_val) const;
    tfixed64<bits> operator / (const tfixed64<bits> &fx_val) const;
    
    tfixed64<bits> operator >> (int64t i) const;
    tfixed64<bits> operator << (int64t i) const;
    
    bool operator == (const tfixed64<bits> &fx_val) const;
    bool operator != (const tfixed64<bits> &fx_val) const;
    
    bool operator <  (const tfixed64<bits> &fx_val) const;
    bool operator >  (const tfixed64<bits> &fx_val) const;
    
    bool operator <= (const tfixed64<bits> &fx_val) const;
    bool operator >= (const tfixed64<bits> &fx_val) const;
};
///////////////////////////////////////////////////////////////////////////////////////

template <int bits>
tfixed64<bits>::tfixed64():value(0){}
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed64<bits>::tfixed64(const tfixed64<bits>& fx_val):value(fx_val.value){}
/////////////////////////////////////////////////////////////////////////////////////// 
template <int bits>
tfixed64<bits>::tfixed64(const float f_val) 
{
    value = (int64t)(f_val * (float)one);
}
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed64<bits>::tfixed64(const double d_val) 
{
    value = (int64t)(d_val * (double)one);
}
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed64<bits>::tfixed64(const int64t i_val) 
{
    value = i_val << bits;
}

///////////////////////////////////////////////////////////////////////////////////////
//Cast To Pointer int64t *
template <int bits>
tfixed64<bits>::operator int64t* () const
{
    return (int64t*) this;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed64<bits>::operator const int64t* () const
{
    return (const int64t*) this;
}

///////////////////////////////////////////////////////////////////////////////////////
//Cast To Primitive Build-in Types
template <int bits>
tfixed64<bits>::operator float()
{//return (float)v / (float)one;
    return (float)value / (float)one;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed64<bits>::operator double()
{
    return (double)value / (double)one;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed64<bits>::operator int64t()
{
    return value >> bits;
}

///////////////////////////////////////////////////////////////////////////////////////
// Assignment Operators
template <int bits>
tfixed64<bits>& tfixed64<bits>::operator = (const tfixed64<bits>& fx_val)
{
    value = fx_val.value;
    return *this;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed64<bits>& tfixed64<bits>::operator += (const tfixed64<bits>& fx_val)
{
    value += fx_val.value;
    return *this;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed64<bits>& tfixed64<bits>::operator -= (const tfixed64<bits>& fx_val)
{
    value -= fx_val.value;
    return *this;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed64<bits>& tfixed64<bits>::operator *= (const tfixed64<bits>& fx_val)
{
    //v = (long)(((long long)v * (long long)f.v + half) >> bits);
    value = ((value * fx_val.value + half) >> bits);
    return *this;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed64<bits>& tfixed64<bits>::operator /= (const tfixed64<bits>& fx_val)
{
    //v = (long)(((long long)v << bits) / (long long)f.v);
    value = ((value << bits) / fx_val.value);
    return *this;
}

///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed64<bits>& tfixed64<bits>::operator >>= (int64t i)
{
    value >>= i;
    return *this;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed64<bits>& tfixed64<bits>::operator <<= (int64t i)
{
    value <<= i;
    return *this;
}
    
///////////////////////////////////////////////////////////////////////////////////////    
// Unary Operators
template <int bits>
tfixed64<bits>& tfixed64<bits>::operator + () const
{
    tfixed64<bits> out;
    out.value = value;
    return out;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed64<bits>& tfixed64<bits>::operator - () const
{
    tfixed64<bits> out;
	out.value = -value;
	return out;
}
    
///////////////////////////////////////////////////////////////////////////////////////    
// Binary Operators
template <int bits>
tfixed64<bits> tfixed64<bits>::operator + (const tfixed64<bits> &fx_val) const
{
    tfixed64<bits> out;
    out.value = value + fx_val.value;
    return out;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed64<bits> tfixed64<bits>::operator - (const tfixed64<bits> &fx_val) const
{
    tfixed64<bits> out;
    out.value = value - fx_val.value;
    return out;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed64<bits> tfixed64<bits>::operator * (const tfixed64<bits> &fx_val) const
{
    tfixed64<bits> out;
    out.value = ((value * fx_val.value + half) >> bits);
    return out;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed64<bits> tfixed64<bits>::operator / (const tfixed64<bits> &fx_val) const
{
    tfixed64<bits> out;
    out.value = ((value << bits) / fx_val.value);
    return out;
}

///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
tfixed64<bits> tfixed64<bits>::operator >> (int64t i) const
{
    tfixed64<bits> out;
    out.value = value >> i;
    return out;
}
///////////////////////////////////////////////////////////////////////////////////////    
template <int bits>
tfixed64<bits> tfixed64<bits>::operator << (int64t i) const
{
    tfixed64<bits> out;
    out.value = value << i;
    return out;
}

///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
bool tfixed64<bits>::operator == (const tfixed64<bits> &fx_val) const
{
    return value == fx_val.value;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>   
bool tfixed64<bits>::operator != (const tfixed64<bits> &fx_val) const
{
    return value != fx_val.value;
}

///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
bool tfixed64<bits>::operator <  (const tfixed64<bits> &fx_val) const
{
    return value < fx_val.value;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
bool tfixed64<bits>::operator >  (const tfixed64<bits> &fx_val) const
{
    return value > fx_val.value;
}

///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
bool tfixed64<bits>::operator <= (const tfixed64<bits> &fx_val) const
{
    return value <= fx_val.value;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int bits>
bool tfixed64<bits>::operator >= (const tfixed64<bits> &fx_val) const
{
    return value >= fx_val.value;
}
///////////////////////////////////////////////////////////////////////////////////////

#endif //__TFIXED64_H__