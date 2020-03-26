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
#ifndef LGF_LEVEL_UTILS_H
#define LGF_LEVEL_UTILS_H
#include "color_lgf.h"

#include "core_lgf.h"
#include <string>

LGF_BEGIN

enum class Level : uint32_t {
	none = 0,
	all = 1,
	trace = 2,
	debug = 3,
	info = 4,
	warn = 5,
	fatal = 6,
	error = 7,
	lastLevel = error,
};

LGF_CONSTEXPR MIN_LEVEL = Level::all;
LGF_CONSTEXPR MAX_LEVEL = Level::info;
LGF_CONSTEXPR DEF_LEVEL = Level::all;



class LgfLevelUtils  {

public:
	struct ColorLevelStringItem {
		std::string levelShortString;
		std::string levelString;
		std::string colorString;
		Level level;
	};

	LgfLevelUtils();

	struct ColorLevelStringItem colorLevelStringMap[7] = {
	  { "A", "ALL",  Color::LIGHT_BLUE, Level::all },
	  { "D","DEBUG", Color::GREEN, Level::debug },
	  { "I","INFO",  Color::CYAN, Level::info },
	  { "W","WARN",  Color::YELLOW, Level::warn },
	  { "E","ERROR", Color::RED, Level::error },
	  { "F","FATAL", Color::RED , Level::fatal },
	  { "T","TRACE", Color::LIGHT_CYAN, Level::trace }
	};

	std::string toShortString(Level level);
	std::string toString(const Level level);
	std::string toString(int level);
	Level       toLevel(int level);
	Level       toLevel(STRING_VIEW level);
	int         toInt(Level level);
};

LGF_END

#endif
