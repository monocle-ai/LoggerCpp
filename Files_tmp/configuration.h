#pragma once
#include "logCore.h"

FASTLOG_BEGIN

constexpr auto DEF_MODE = MODE::DEFAULT;
constexpr auto ARG_MODE = MODE::ARG;
constexpr auto MANUAL_MODE = MODE::MANUAL;
constexpr auto FILE_MODE = MODE::FILE;
constexpr auto UNKNOWN_MODE = MODE::UNKNOWN;

enum class MODE {
	ARG = 1, // command line
	FILE = 2, // from file
	MANUAL = 3, // set in code
	DEFAULT = 4, // pre made
	UNKNOWN = 5  // invalid
};

FASTLOG_END
