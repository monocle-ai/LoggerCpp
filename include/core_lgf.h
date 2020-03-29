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

If you contribute to this file please add your name to the contributors list below.

Author		 : Sayantan Roy
Contributors :
*/

#pragma once
#ifndef LGF_CORE_H
#define LGF_CORE_H

#include <stdint.h> // for including different datatype typedefs (e.g. uint32_t)
#include <sstream>

#define LGF_LITERAL(txt) (txt);
#define LGF_CONSTEXPR constexpr auto
#define LGF_STATIC_CONSTEXPR static LGF_CONSTEXPR

// NAMESPACE

#define LGF_BEGIN namespace Lgfypp {
#define LGF_END }
#define LGF Lgfypp

#define COLOR_BEGIN namespace Color {
#define COLOR_END }

//PROJECT DETAILS

LGF_CONSTEXPR VER_MAJOR = 0;
LGF_CONSTEXPR VER_MINOR = 0;
LGF_CONSTEXPR VER_PATCH = 0;
LGF_CONSTEXPR PROJECT = "Logify++";

LGF_CONSTEXPR VERSION(VER_MAJOR * 1000 + VER_MINOR * 100 + VER_PATCH);

inline std::string getProjectVersion()
{
	std::stringstream stream;
	stream << PROJECT << ":" << VER_MAJOR * 1000 << "." << VER_MINOR * 100 << "." << VER_PATCH;
	return  stream.str();
};

// Chrono Consts

LGF_CONSTEXPR TIME_FORMAT		= "%F %T";
LGF_CONSTEXPR TIME_FORMAT_ALT   = "%D %T";
LGF_CONSTEXPR TIME_FORMAT_SHORT = "%T";

LGF_CONSTEXPR PRECISION_MOD_MILLI = static_cast<int>(1e3);
LGF_CONSTEXPR PRECISION_MOD_MICRO = static_cast<int>(1e6);
LGF_CONSTEXPR PRECISION_MOD_NANO  = static_cast<int>(1e9);

//File name stripper
#if defined(__linux__)
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#else
#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#endif

#if defined(__GNUC__) && __GNUC__ < 7
# include <experimental/string_view>
# define STRING_VIEW std::experimental::string_view
#else
# include <string_view>
#define STRING_VIEW std::string_view
#endif
#include "fmt/format.h"
inline STRING_VIEW toStringView(const fmt::memory_buffer& buf)
{
	return STRING_VIEW{ buf.data(), buf.size() };
}

#endif