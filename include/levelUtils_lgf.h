/*
MIT License

Copyright(c) 2020 Sayantan Roy

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NON INFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

If you contribute to this file please add your name to the contributors list below.

Author		 : Sayantan Roy
Contributors :
*/
#pragma once
#ifndef LGF_LEVEL_UTILS_H
#define LGF_LEVEL_UTILS_H
#include "color_lgf.h"
#include "core_lgf.h"
#include <string>

LGF_BEGIN

enum class Level : uint32_t {
	none  = 0,
	all   = 1,
	trace = 2,
	debug = 3,
	info  = 4,
	warn  = 5,
	fatal = 6,
	error = 7,
	lastLevel = error,
};

LGF_CONSTEXPR MIN_LEVEL = Level::all;
LGF_CONSTEXPR MAX_LEVEL = Level::error;
LGF_CONSTEXPR DEF_LEVEL = Level::all;

inline const std::tuple<const char*, const char*, const char*> getLevelDetails(Level level) {
	switch (level) {
	case Level::all:   return { "A", "ALL",   Color::LIGHT_BLUE };
	case Level::debug: return { "D", "DEBUG", Color::GREEN };
	case Level::info:  return { "I", "INFO",  Color::CYAN };
	case Level::warn:  return { "W", "WARN",  Color::YELLOW };
	case Level::error: return { "E", "ERROR", Color::RED };
	case Level::fatal: return { "F", "FATAL", Color::RED };
	case Level::trace: return { "T", "TRACE", Color::LIGHT_CYAN };
	}
};
inline Level convertToLevel(int levelInt)
{
	switch (levelInt) {
	case 0: return Level::none;
	case 1: return Level::all;
	case 2: return Level::trace;
	case 3: return Level::debug;
	case 4: return Level::info;
	case 5: return Level::warn;
	case 6: return Level::fatal;
	case 7: return Level::error;
	default:return Level::lastLevel;
	}
}

inline int convertToInt(const Level level)
{
	return static_cast<int>(level);
}

LGF_END

#endif
