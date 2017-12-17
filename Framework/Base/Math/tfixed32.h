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
    operator float();
    operator double();
    operator int32t();
    
    // Assignment Operators
    tfixed32<bits>& operator = (const tfixed32<bits>& fx_val);
    tfixed32<bits>& operator += (const tfixed32<bits>& fx_val);
    tfixed32<bits>& operator -= (const tfixed32<bits>& fx_val);
    tfixed32<bits>& operator *= (const tfixed32<bits>& fx_val);
    tfixed32<bits>& operator /= (const tfixed32<bits>& fx_val);
    
    
    // Unary Operators
    tfixed32<bits>& operator + ();
    tfixed32<bits>& operator - ();
    
    // Binary Operators
    tfixed32<bits> operator + (const tfixed32<bits> &fx_val);
    tfixed32<bits> operator - (const tfixed32<bits> &fx_val);
    tfixed32<bits> operator * (const tfixed32<bits> &fx_val);
    tfixed32<bits> operator / (const tfixed32<bits> &fx_val);

    
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
    value = (int32t)(f_val * (float)one);
}
///////////////////////////////////////////////////////////////////////////////////////
template <int32t bits>
tfixed32<bits>::tfixed32(const double d_val) 
{
    value = (int32t)(d_val * (double)one);
}
///////////////////////////////////////////////////////////////////////////////////////
template <int32t bits>
tfixed32<bits>::tfixed32(const int32t i_val) 
{
    value = i_val << bits;
}

///////////////////////////////////////////////////////////////////////////////////////
//Cast To Pointer int32t *
template <int32t bits>
tfixed32<bits>::operator int32t* () const
{
    return (int32t*) this;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int32t bits>
tfixed32<bits>::operator const int32t* () const
{
    return (const int32t*) this;
}

///////////////////////////////////////////////////////////////////////////////////////
//Cast To Primitive Build-in Types
template <int32t bits>
tfixed32<bits>::operator float()
{//return (float)v / (float)one;
    return (float)value / (float)one;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int32t bits>
tfixed32<bits>::operator double()
{
    return (double)value / (double)one;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int32t bits>
tfixed32<bits>::operator int32t()
{
    return value >> bits;
}

///////////////////////////////////////////////////////////////////////////////////////
// Assignment Operators
template <int32t bits>
tfixed32<bits>& tfixed32<bits>::operator = (const tfixed32<bits>& fx_val)
{
    value = fx_val.value;
    return *this;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int32t bits>
tfixed32<bits>& tfixed32<bits>::operator += (const tfixed32<bits>& fx_val)
{
    value += fx_val.value;
    return *this;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int32t bits>
tfixed32<bits>& tfixed32<bits>::operator -= (const tfixed32<bits>& fx_val)
{
    value -= fx_val.value;
    return *this;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int32t bits>
tfixed32<bits>& tfixed32<bits>::operator *= (const tfixed32<bits>& fx_val)
{
    //v = (long)(((long long)v * (long long)f.v + half) >> bits);
    value = (int32t)(((int64t)value * (int64t)fx_val.value + half) >> bits);
    return *this;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int32t bits>
tfixed32<bits>& tfixed32<bits>::operator /= (const tfixed32<bits>& fx_val)
{
    //v = (long)(((long long)v << bits) / (long long)f.v);
    value = (int32t)(((int64t)value << bits) / (int64t)fx_val.value);
    return *this;
}
    
///////////////////////////////////////////////////////////////////////////////////////    
// Unary Operators
template <int32t bits>
tfixed32<bits>& tfixed32<bits>::operator + ()
{
    tfixed32<bits> out;
    out.value = value;
    return out;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int32t bits>
tfixed32<bits>& tfixed32<bits>::operator - ()
{
    tfixed32<bits> out;
	out.value = -value;
	return out;
}
    
///////////////////////////////////////////////////////////////////////////////////////    
// Binary Operators
template <int32t bits>
tfixed32<bits> tfixed32<bits>::operator + (const tfixed32<bits> &fx_val)
{
    tfixed32<bits> out;
    out.value = value + fx_val.value;
    return out;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int32t bits>
tfixed32<bits> tfixed32<bits>::operator - (const tfixed32<bits> &fx_val)
{
    tfixed32<bits> out;
    out.value = value - fx_val.value;
    return out;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int32t bits>
tfixed32<bits> tfixed32<bits>::operator * (const tfixed32<bits> &fx_val)
{
    tfixed32<bits> out;
    out.value = (int32t)(((int64t)value * (int64t)fx_val.value + half) >> bits);
    return out;
}
///////////////////////////////////////////////////////////////////////////////////////
template <int32t bits>
tfixed32<bits> tfixed32<bits>::operator / (const tfixed32<bits> &fx_val)
{
    tfixed32<bits> out;
    out.value = (int32t)(((int64t)value << bits) / (int64t)fx_val.value);
    return out;
}
///////////////////////////////////////////////////////////////////////////////////////

#endif //__TFIXED32_H__