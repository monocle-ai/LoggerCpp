#pragma once

#if defined(__GNUC__) && __GNUC__ < 7
# include <experimental/string_view>
# define STRING_VIEW std::experimental::string_view
#else
# include <string_view>
#define STRING_VIEW std::string_view
#endif

#include "level.h"
#include "levelColor.h"
#include "staticBase.h"
#include <string>
#include "logCore.h"

FASTLOG_BEGIN

FASTLOG_CONSTEXPR MIN_LEVEL = Level::all;
FASTLOG_CONSTEXPR MAX_LEVEL = Level::info;
FASTLOG_CONSTEXPR DEF_LEVEL = Level::all;

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

class levelUtils : StaticBase {
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

FASTLOG_END
