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
#include "cpuCycles_lgf.h"
#include <fmt/chrono.h>
LGF_BEGIN

class LogBuilder : public StaticBase
{
public:
	template<typename... arguments>
	static void logWithLevel(std::tuple<const char*, const char*, int, uint32_t, int>& loc, Lgfypp::Level level, const char* format, arguments... args) {
		fmt::memory_buffer buf;
		Lgfypp::Chrono sds;
		auto [time, subsec] = sds.getTimestamp();
		//fmt::format_to(buf, "{:%F %T}.{:0^3}", time, subsec);
		auto [file, func, line, threadId, ProcessId] = loc;
		fmt::format_to(buf, "{} {} {} {} {} ", file, func, line, threadId, ProcessId);
	

		Lgfypp::Formatter ff;
		std::cout << toStringView(buf) << std::endl;
		STRING_VIEW ssdds("ADSAD");

		ff.appendColorFormattedSVToBuf(ssdds, Lgfypp::Color::RED, buf);

		auto [sName, name, color] = Lgfypp::getLevelDetails(level);

		fmt::format_to(buf, name);
		std::cout << "___________________________" << toStringView(buf) << std::endl;
	}

	template<typename... arguments, typename S>
	static void log(std::tuple<const char*, const char*, int, uint32_t, int>& loc, Lgfypp::Level level, const char* format, S msg)
	{
		LGF_TRY
		{
			fmt::memory_buffer buf;
		LGF::Chrono chrono;
		auto [time, subsec] = chrono.getTimestamp();
		//fmt::format_to(buf, "{:%F %T}.{:0^3}", time , subsec);
		auto [file, func, line, threadId, ProcessId] = loc;
		fmt::format_to(buf, " {} {} {} {} {} ", file, func, line, threadId, ProcessId);
			fmt::format_to(buf, format, msg);
			std::cout << toStringView(buf) << std::endl;
		}
			LGF_CATCH()
	}
	template<typename... arguments>
	static void logWithFormat(std::tuple<const char*, const char*, int, uint32_t, int>& loc, const char* format, arguments... message)
	{
		LGF_TRY
		{
			fmt::memory_buffer buf;
		LGF::Chrono chrono;
		auto [time, subsec] = chrono.getTimestamp();
		//fmt::format_to(buf, "{:%F %T}.{:0^3}", time, subsec);
		auto [file, func, line, threadId, ProcessId] = loc;
		fmt::format_to(buf, " {} {} {} {} {} ", file, func, line, threadId, ProcessId);
						fmt::format_to(buf, format, message...);
			std::cout << toStringView(buf) << std::endl;
		}
			LGF_CATCH()
	}
	template<typename... arguments>

	 static void logWithFormat(std::tuple<const char*, const char*, int, uint32_t, int>& loc, LGF::Level level, const char* format, arguments... message)
	{
		LGF_TRY
		{
			fmt::memory_buffer buf;
		LGF::Chrono chrono;

		auto [time, subsec] = chrono.getTimestamp();
		auto t = time;
		const auto now = std::chrono::system_clock::now();
		const auto nowAsTimeT = std::chrono::system_clock::to_time_t(now);
		auto timeinfo = fmt::localtime(nowAsTimeT);
		fmt::format_to(buf, "{:%F %T}.{:0^3}", timeinfo, subsec);

		auto [file, func, line, threadId, ProcessId] = loc;
		fmt::format_to(buf, " {} {} {} {} {} ", file, func, line, threadId, ProcessId);
			fmt::format_to(buf, format, message...);
			std::cout << toStringView(buf) << std::endl;
		}
			LGF_CATCH()
	}


	template<typename... T>
	static std::string_view log(Level level, const char* format, T&... args)
	{
		LGF_TRY
		{
			fmt::memory_buffer buf;
		auto [sName, name, color] = Lgfypp::getLevelDetails(level);

			fmt::format_to(buf, name);
			fmt::format_to(buf, format, args...);

			std::cout << toStringView(buf) << std::endl;
			return toStringView(buf);
		}
			LGF_CATCH()
	}
	template<typename T>
	static void logOnlyMsg(std::tuple<const char*, const char*, int, uint32_t, int>& loc, T msg)
	{
		LGF_TRY
		{
			fmt::memory_buffer buf;
		auto [file, func, line, threadId, ProcessId] = loc;
		fmt::format_to(buf, "{} {} {} {} {} ", file, func, line, threadId, ProcessId);

			fmt::format_to(buf, msg);
			std::cout << toStringView(buf) << std::endl;
		}
			LGF_CATCH()
	}

	template<typename... arguments>
	static void warn(const char* file, int line, const char* function, const arguments&... args) {
		log(Lgfypp::Level::warn, file, line, function, args...);
	}
	template<typename... arguments>
	static void debug(const char* file, int line, const char* function, const arguments&... args) {
		log(Lgfypp::Level::debug, file, line, function, args...);
	}
};

LGF_END