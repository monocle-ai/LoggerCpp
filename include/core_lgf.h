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
#define LGF_SCOPE_ Lgfypp::

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

LGF_CONSTEXPR TIME_FORMAT = "%F %T";
LGF_CONSTEXPR TIME_FORMAT_ALT = "%D %T";
LGF_CONSTEXPR TIME_FORMAT_SHORT = "%T";

LGF_CONSTEXPR MOD_MILLI = 1000;
LGF_CONSTEXPR MOD_MICRO = 1000000;
LGF_CONSTEXPR MOD_NANO = 1000000000;

//File name stripper
#if defined(__linux__)
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#else
#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#endif

#endif