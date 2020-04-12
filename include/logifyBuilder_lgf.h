/*
MIT License

Copyright(c) 2020 Sayantan Roy

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

#include "core_lgf.h"

#include "formatter_lgf.h"
#include "staticBase_lgf.h"
#include <iostream>
#include "chrono_lgf.h"
#include "sourceInfo_lgf.h"
#include "levelUtils_lgf.h"
#include "sourceInfo_lgf.h"
#include "color_lgf.h"
#include <fmt/chrono.h>
LGF_BEGIN

class LogBuilder : public StaticBase
{
public:
	static void writePreambleInfo(fmt::memory_buffer& buf, std::tuple<const char*, const char*, int, uint32_t, int>& loc, LGF::Level level) {
		Lgfypp::Chrono clock;
		auto [time, subsec] = clock.getTimestamp();
		auto [file, func, line, threadId, ProcessId] = loc;
		auto [sName, name, scolors] = getLevelDetails(level);
		fmt::format_to(buf, "{:%F %T}.{:0^3} {} {}:{} {} {} {} {}{}|", time, subsec, file, func, line, threadId, ProcessId, scolors, sName, LGF::Color::RESET_COLOR);
	}

	template<typename... arguments>
	static void logWithLevel(std::tuple<const char*, const char*, int, uint32_t, int>& loc, Lgfypp::Level level, const char* format, arguments... args) {
		LGF_TRY
		{
		  fmt::memory_buffer buf;
		  writePreambleInfo(buf, loc,level);
		  fmt::format_to(buf, format, args...);
		  fmt::print("{}\n", toStringView(buf));
		}
		LGF_CATCH()
	}

	template<typename T>
	static void logOnlyMsg(std::tuple<const char*, const char*, int, uint32_t, int>& loc, T msg)
	{
		logWithLevel(loc, LGF::Level::all, "{}", msg);
	}

};

LGF_END