/*
MIT License

Copyright(c) 2020 Sayantan Roy and Dipanjan Das

Permission is hereby granted, free of charge, to any person obtaining a copy
of this softwareand associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright noticeand this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#pragma once
#if defined(__GNUC__) && __GNUC__ < 7
# include <experimental/string_view>
# define STRING_VIEW std::experimental::string_view
#else
# include <string_view>
#define STRING_VIEW std::string_view
#endif

#include <fmt/format.h>
#include "core_lgf.h"

LGF_BEGIN

inline STRING_VIEW toStringView(const fmt::memory_buffer& buf)
{
	return STRING_VIEW{ buf.data(), buf.size() };
}

inline void append(STRING_VIEW s, fmt::memory_buffer& buf) {
	fmt::format_to(buf, s);
}

template<typename T>
inline void appendDigits(T digit, fmt::memory_buffer& buf) {
	fmt::format_int digits(digit);
	buf.append(digits.data(), digits.data() + digits.size());
}

LGF_END
