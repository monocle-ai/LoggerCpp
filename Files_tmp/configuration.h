#pragma once
#include "logCore.h"

FASTLOG_BEGIN

constexpr auto DEF_MODE		= Mode::defaultMode;
constexpr auto ARG_MODE		= Mode::arg;
constexpr auto FILE_MODE	= Mode::file;
constexpr auto MANUAL_MODE	= Mode::manual;

enum class Mode : uint32_t
{
	defaultMode = 0, // pre made
	arg = 1, // command line
	file = 2, // from file
	manual = 3, // set in code
	lastMode = manual,
};

FASTLOG_END
