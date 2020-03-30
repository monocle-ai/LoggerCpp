/*
MIT License

Copyright(c) 2020 Sayantan Roy

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
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
#ifndef LGF_TIME_H
#define LGF_TIME_H

#include "core_lgf.h"
#include <chrono>
#include <fmt/format.h>
#include <iomanip>
#include <sstream>      // std::stringstream

LGF_BEGIN

// Chrono format Consts
LGF_CONSTEXPR TIME_FORMAT       = "%F %T";
LGF_CONSTEXPR TIME_FORMAT_ALT   = "%D %T";
LGF_CONSTEXPR TIME_FORMAT_SHORT = "%T";
// Chrono Precision Consts
LGF_CONSTEXPR PRECISION_MOD_MILLI = static_cast<int>(1e3);
LGF_CONSTEXPR PRECISION_MOD_MICRO = static_cast<int>(1e6);
LGF_CONSTEXPR PRECISION_MOD_NANO  = static_cast<int>(1e9);

enum class Timeformat : uint32_t { standard, concise, alternative, none };
enum class Precision  : uint32_t { milli, micro, nano };

static LGF::Precision  gPrecision  = Precision::milli;
static LGF::Timeformat gTimeFormat = Timeformat::standard;

class Chrono
{
private:
	int mPrecisionPad = 0;
	template<typename T>
	long long getSecondsWithPrecision(std::chrono::system_clock::time_point now);

public:
	Chrono();
	~Chrono();
	void getTimestamp(fmt::memory_buffer& buf);
};

LGF_END

#endif
