#include "lgfLevelUtils.h"


std::string Lgfypp::LgfLevelUtils::toFormattedShortString(Level level)

{
	return "[" + toShortString(level) + "]" ;
}

std::string Lgfypp::LgfLevelUtils::toFormattedColorShortString(Level level)
{
	return "[" + toColorShortString(level) + "]";
}

std::string Lgfypp::LgfLevelUtils::toColorShortString(Level level)
{
	for (auto& item : colorLevelStringMap)
	{
		if (level == item.level)
		{
			return (item.colorString + item.levelShortString + Color::RESET_COLOR);
		}
	}
	return "";
}


std::string Lgfypp::LgfLevelUtils::toShortString(Level level)
{
	for (auto& item : colorLevelStringMap)
	{
		if (level == item.level)
		{
			return item.levelShortString;
		}
	}
	return "";
}

std::string Lgfypp::LgfLevelUtils::toFormattedString(Level level)
{
	return "[" + toString(level) + "]";
}


std::string Lgfypp::LgfLevelUtils::toFormattedColorString(Level level)
{
	return "[" + toColorString(level) + "]";
}

std::string Lgfypp::LgfLevelUtils::toColorString(Level level)
{
	for (auto& item : colorLevelStringMap)
	{
		if (level == item.level)
		{
			return (item.colorString + item.levelString + Color::RESET_COLOR);
		}
	}
	return "";
}

std::string Lgfypp::LgfLevelUtils::toString(Level level)
{
	for (auto& item : colorLevelStringMap)
	{
		if (level == item.level)
		{
			return item.levelString;
		}
	}
	return "";
}

std::string Lgfypp::LgfLevelUtils::toString(int levelInt)
{
	return toString(toLevel(levelInt));
}

Lgfypp::Level Lgfypp::LgfLevelUtils::toLevel(int levelInt)
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


Lgfypp::Level Lgfypp::LgfLevelUtils::toLevel(STRING_VIEW levelStr)
{

	for (auto& item : colorLevelStringMap)
	{
		if (item.levelString.c_str() == levelStr)
		{
			return item.level;
		}
	}
	return Level::lastLevel;
}

int Lgfypp::LgfLevelUtils::toInt(Level level)
{
	return static_cast<int>(level);
}