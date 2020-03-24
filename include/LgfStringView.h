#pragma once
#if defined(__GNUC__) && __GNUC__ < 7
# include <experimental/string_view>
# define STRING_VIEW std::experimental::string_view
#else
# include <string_view>
#define STRING_VIEW std::string_view
#endif
#include <fmt/format.h>
#include "lgfStaticBase.h"

LGF_BEGIN

class LgfStringView : public STRING_VIEW
{
public:
	STRING_VIEW toStringView(const fmt::memory_buffer& buf);
	void append(STRING_VIEW s, fmt::memory_buffer& buf);
	template<typename T>
	void appendDigits(T digit, fmt::memory_buffer& buf);
};

LGF_END

