#pragma once
#ifndef LGF_CONFIGURATION_H
#define LGF_CONFIGURATION_H

#include "core_lgf.h"

LGF_BEGIN

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

// TODO: Add Static Assert when .cpp is created.

LGF_END

#endif
