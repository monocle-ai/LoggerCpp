#pragma once
#if defined(__GNUC__) && __GNUC__ < 7
# include <experimental/string_view>
# define STRING_VIEW std::experimental::string_view
#else
# include <string_view>
#define STRING_VIEW std::string_view
#endif
#include <fmt/format.h>

LGF_BEGIN

inline STRING_VIEW toStringView(const fmt::memory_buffer& buf)
{
	return STRING_VIEW{ buf.data(), buf.size() };
}

inline void append(STRING_VIEW s, fmt::memory_buffer& buf) {
	fmt::format_to(buf, s);
}

template<typename T>
void appendDigits(T digit, fmt::memory_buffer& buf) {
	fmt::format_int digits(digit);
	buf.append(digit.data(), digit.data() + digit.size());
}

LGF_END
