#include "lgfLevelUtils.h"


std::string Lgfypp::lgfLevelUtils::toFormattedShortString(Level level)

{
	return "[" + toShortString(level) + "]" ;
}

std::string Lgfypp::lgfLevelUtils::toFormattedColorShortString(Level level)
{
	return "[" + toColorShortString(level) + "]";
}

std::string Lgfypp::lgfLevelUtils::toColorShortString(Level level)
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


std::string Lgfypp::lgfLevelUtils::toShortString(Level level)
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

std::string Lgfypp::lgfLevelUtils::toFormattedString(Level level)
{
	return "[" + toString(level) + "]";
}


std::string Lgfypp::lgfLevelUtils::toFormattedColorString(Level level)
{
	return "[" + toColorString(level) + "]";
}

std::string Lgfypp::lgfLevelUtils::toColorString(Level level)
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

std::string Lgfypp::lgfLevelUtils::toString(Level level)
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

std::string Lgfypp::lgfLevelUtils::toString(int levelInt)
{
	return toString(toLevel(levelInt));
}

Lgfypp::Level Lgfypp::lgfLevelUtils::toLevel(int levelInt)
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


Lgfypp::Level Lgfypp::lgfLevelUtils::toLevel(STRING_VIEW levelStr)
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

int Lgfypp::lgfLevelUtils::toInt(Level level)
{
	return static_cast<int>(level);
}