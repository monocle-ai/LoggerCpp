#pragma once
#include "logCore.h"

FASTLOG_BEGIN

constexpr auto DEF_MODE		= MODE::DEFAULT;
constexpr auto ARG_MODE		= MODE::ARG;
constexpr auto FILE_MODE	= MODE::FILE;
constexpr auto MANUAL_MODE	= MODE::MANUAL;

enum class MODE : uint32_t
{
	DEFAULT = 0, // pre made
	ARG = 1, // command line
	FILE = 2, // from file
	MANUAL = 3, // set in code
	LASTMODE = MANUAL,
};

FASTLOG_END
