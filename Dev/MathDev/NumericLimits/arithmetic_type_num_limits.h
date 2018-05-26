////////////////////////////////////////////////////////////////////////////////////////////////
// arithmetic types numeric limits printing functions
////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <limits>
#include <string.h>

////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void print_arithmetic_type_info()
{
    printf("Template arithemtic type numeric limits:\n");
}
////////////////////////////////////////////////////////////////////////////////////////////////
template <> void print_arithmetic_type_info<int>() { printf("32-bit integer numeric limits:\n"); }
////////////////////////////////////////////////////////////////////////////////////////////////
template <> void print_arithmetic_type_info<float>() { printf("float numeric limits:\n"); }
////////////////////////////////////////////////////////////////////////////////////////////////
template <> void print_arithmetic_type_info<double>() { printf("double numeric limits:\n"); }
////////////////////////////////////////////////////////////////////////////////////////////////
template <> void print_arithmetic_type_info<long double>() { printf("long double numeric limits:\n"); }

////////////////////////////////////////////////////////////////////////////////////////////////
void print_boolean_value(const char *parameter_name, bool value)
{
	printf("%s: %s\n",parameter_name,(value)?("true"):("false"));
}

////////////////////////////////////////////////////////////////////////////////////////////////
void print_integer_value(const char *param_name, int value)
{
	printf("%s: %i\n", param_name, value);
}


////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
struct valueformat
{
	static const char format[];
};
////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
const char valueformat<T>::format[] = "";
////////////////////////////////////////////////////////////////////////////////////////////////
template <> const char valueformat<int>::format[] = "%i";
////////////////////////////////////////////////////////////////////////////////////////////////
template <> const char valueformat<float>::format[] = "%f";
////////////////////////////////////////////////////////////////////////////////////////////////
template <> const char valueformat<double>::format[] = "%f";
////////////////////////////////////////////////////////////////////////////////////////////////
template <> const char valueformat<long double>::format[] = "%Lf";
////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
void print_value(const char *param_name, T value)
{
	char string[128]={0};
	strcpy(string, param_name);
	strcat(string, ": ");
	strcat(string, valueformat<T>::format);
	strcat(string, "\n");
	printf(string, value);
}

////////////////////////////////////////////////////////////////////////////////////////////////
void print_float_denorm_style(std::float_denorm_style denorm_style)
{
	const char interminate_str[] = "denorm_indeterminate";
	const char absent_str[] = "denorm_absent";
	const char present_str[] = "denorm_present";
	
	const char *denorm_style_str = interminate_str;
	if(denorm_style == std::denorm_absent) denorm_style_str = absent_str;
	else if(denorm_style == std::denorm_present) denorm_style_str = present_str;
	
	printf("float_denorm_style: %s\n", denorm_style_str);
}

////////////////////////////////////////////////////////////////////////////////////////////////
void print_round_style(std::float_round_style round_style)
{
	const char indeterminate_str[] = "round_indeterminate";
	const char toward_zero_str[] = "round_toward_zero";
	const char to_nearest_str[] = "round_to_nearest";
	const char toward_infinity_str[] = "round_toward_infinity";
	const char toward_neg_infinity[] = "round_toward_neg_infinity";

	const char *round_style_str = indeterminate_str;
	
	if(round_style == std::round_toward_zero) round_style_str = toward_zero_str;
	else if(round_style == std::round_to_nearest) round_style_str = to_nearest_str;
	else if(round_style == std::round_toward_infinity) round_style_str = toward_infinity_str;
	else if(round_style == std::round_toward_neg_infinity) round_style_str = toward_neg_infinity;

	printf("float_round_style: %s\n",round_style_str);
}

////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void print_arithmetic_type_numeric_limits()
{
    printf("-------------------------------------------------------------\n");
	print_arithmetic_type_info<T>();
	
	print_boolean_value("is_specialiazed", std::numeric_limits<T>::is_specialized);
	
	print_value("min",std::numeric_limits<T>::min());
	print_value("max",std::numeric_limits<T>::max());
	
	print_value("lowest",std::numeric_limits<T>::lowest());
	print_integer_value("digits",std::numeric_limits<T>::digits);
	print_integer_value("digits10",std::numeric_limits<T>::digits10);

	print_boolean_value("is_signed", std::numeric_limits<T>::is_signed);
	print_boolean_value("is_integer", std::numeric_limits<T>::is_integer);
	print_boolean_value("is_exact", std::numeric_limits<T>::is_exact);

	print_integer_value("radix",std::numeric_limits<T>::radix);
	print_value("epsilon",std::numeric_limits<T>::epsilon());
	print_value("round_error",std::numeric_limits<T>::round_error());
	
	print_integer_value("min_exponent",std::numeric_limits<T>::min_exponent);
	print_integer_value("min_exponent10",std::numeric_limits<T>::min_exponent10);
	print_integer_value("max_exponent",std::numeric_limits<T>::max_exponent);
	print_integer_value("max_exponent10",std::numeric_limits<T>::max_exponent10);
	
	print_boolean_value("has_infinity",std::numeric_limits<T>::has_infinity);
	print_boolean_value("has_quiet_NaN",std::numeric_limits<T>::has_quiet_NaN);
	print_boolean_value("has_signaling_NaN",std::numeric_limits<T>::has_signaling_NaN);
	
	print_float_denorm_style(std::numeric_limits<T>::has_denorm);
	print_boolean_value("has_denorm_loss",std::numeric_limits<T>::has_denorm_loss);

  	print_value("infinity", std::numeric_limits<T>::infinity());
	print_value("quiet_NaN", std::numeric_limits<T>::quiet_NaN());
	print_value("signaling_NaN", std::numeric_limits<T>::signaling_NaN());
	print_value("denorm_min", std::numeric_limits<T>::denorm_min());

	print_boolean_value("is_iec559",std::numeric_limits<T>::is_iec559);
	print_boolean_value("is_bounded",std::numeric_limits<T>::is_bounded);
	print_boolean_value("is_modulo",std::numeric_limits<T>::is_modulo);
	
	print_boolean_value("traps",std::numeric_limits<T>::traps);
	print_boolean_value("tinyness_before",std::numeric_limits<T>::tinyness_before);
	
	print_round_style(std::numeric_limits<T>::round_style);
}



////////////////////////////////////////////////////////////////////////////////////////////////

/*
template <class T> class numeric_limits {
public:
  static constexpr bool is_specialized = false;
  static constexpr T min() noexcept { return T(); }
  static constexpr T max() noexcept { return T(); }
  static constexpr T lowest() noexcept { return T(); }
  static constexpr int  digits = 0;
  static constexpr int  digits10 = 0;
  static constexpr bool is_signed = false;
  static constexpr bool is_integer = false;
  static constexpr bool is_exact = false;
  static constexpr int radix = 0;
  static constexpr T epsilon() noexcept { return T(); }
  static constexpr T round_error() noexcept { return T(); }

  static constexpr int  min_exponent = 0;
  static constexpr int  min_exponent10 = 0;
  static constexpr int  max_exponent = 0;
  static constexpr int  max_exponent10 = 0;

  static constexpr bool has_infinity = false;
  static constexpr bool has_quiet_NaN = false;
  static constexpr bool has_signaling_NaN = false;
  static constexpr float_denorm_style has_denorm = denorm_absent;
  static constexpr bool has_denorm_loss = false;
  static constexpr T infinity() noexcept { return T(); }
  static constexpr T quiet_NaN() noexcept { return T(); }
  static constexpr T signaling_NaN() noexcept { return T(); }
  static constexpr T denorm_min() noexcept { return T(); }

  static constexpr bool is_iec559 = false;
  static constexpr bool is_bounded = false;
  static constexpr bool is_modulo = false;

  static constexpr bool traps = false;
  static constexpr bool tinyness_before = false;
  static constexpr float_round_style round_style = round_toward_zero;
};
*/