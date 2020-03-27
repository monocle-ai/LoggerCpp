#include "levelUtils_lgf.h"

Lgfypp::LevelUtils::LevelUtils(){}

Lgfypp::LevelUtils::~LevelUtils(){}

std::string Lgfypp::LevelUtils::toShortString(const Level level)
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

std::string Lgfypp::LevelUtils::toString(const Level level)
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

std::string Lgfypp::LevelUtils::toString(int levelInt)
{
	return toString(toLevel(levelInt));
}

Lgfypp::Level Lgfypp::LevelUtils::toLevel(int levelInt)
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

Lgfypp::Level Lgfypp::LevelUtils::toLevel(const STRING_VIEW levelStr)
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

int Lgfypp::LevelUtils::toInt(const Level level)
{
	return static_cast<int>(level);
}