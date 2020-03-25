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
#ifndef LGF_TIME_H
#define LGF_TIME_H

#include <chrono>
#include <sstream>      // std::stringstream
#include <iomanip>

#include "staticBase_lgf.h"
#include "core_lgf.h"

LGF_CONSTEXPR TIME_FORMAT       = "%F %T";
LGF_CONSTEXPR TIME_FORMAT_ALT   = "%D %T";
LGF_CONSTEXPR TIME_FORMAT_SHORT = "%T";

LGF_CONSTEXPR MOD_MILLI  = 1000;
LGF_CONSTEXPR MICRO      = 1000000;
LGF_CONSTEXPR MOD_NANO   = 1000000000;

LGF_CONSTEXPR DEF_TIMEFORMAT = TIME_FORMAT;

LGF_BEGIN

enum class TIMEFORMAT { STANDARD, SHORT, ALTERNATIVE };
class Chrono : StaticBase
{
	static TIMEFORMAT format;
	static int precision;
	static std::string getTimestamp(Lgfypp::TIMEFORMAT format);
public:
	static void setTimeFormat(TIMEFORMAT value);
	static std::string getTimestamp();
	static void write_date_time(char* buff, size_t buff_size);
};

LGF_END

#endif