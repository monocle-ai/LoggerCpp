#pragma once
#ifndef LGF_LEVEL_UTILS_H
#define LGF_LEVEL_UTILS_H

#if defined(__GNUC__) && __GNUC__ < 7
# include <experimental/string_view>
# define STRING_VIEW std::experimental::string_view
#else
# include <string_view>
#define STRING_VIEW std::string_view
#endif


#include "lgfColor.h"
#include "lgfStaticBase.h"
#include "lgfcore.h"
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
struct ColorLevelStringItem {
	std::string levelShortString;
	std::string levelString;
	std::string colorString;
	Level level;
};

static struct ColorLevelStringItem colorLevelStringMap[] = {
   { "A", "ALL",  Color::LIGHT_BLUE, Level::all },
   { "D","DEBUG", Color::GREEN, Level::debug },
   { "I","INFO",  Color::CYAN, Level::info },
   { "W","WARN",  Color::YELLOW, Level::warn },
   { "E","ERROR", Color::RED, Level::error },
   { "F","FATAL", Color::RED , Level::fatal },
   { "T","TRACE", Color::LIGHT_CYAN, Level::trace }
};

class lgfLevelUtils : LgfStaticBase {
public:
	static std::string toFormattedShortString(Level level);
	static std::string toFormattedColorShortString(Level level);
	static std::string toColorShortString(Level level);
	static std::string toShortString(Level level);
	static std::string toFormattedString(Level level);
	static std::string toFormattedColorString(Level level);
	static std::string toColorString(Level level);
	static std::string toString(Level level);
	static std::string toString(int level);
	static Level       toLevel(int level);
	static Level       toLevel(STRING_VIEW level);
	static int         toInt(Level level);
};

LGF_END

#endif