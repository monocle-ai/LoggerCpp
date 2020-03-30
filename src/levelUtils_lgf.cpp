#include "levelUtils_lgf.h"

Lgfypp::LevelUtils::LevelUtils(){}

Lgfypp::LevelUtils::~LevelUtils(){}


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

int Lgfypp::LevelUtils::toInt(const Level level)
{
	return static_cast<int>(level);
}