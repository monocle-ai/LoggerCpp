#pragma once

#include "logCore.h"
#include <sstream>

FASTLOG_BEGIN

FASTLOG_CONSTEXPR VER_MAJOR = 0;
FASTLOG_CONSTEXPR VER_MINOR = 0;
FASTLOG_CONSTEXPR VER_PATCH = 0;
FASTLOG_CONSTEXPR PROJECT = "SwiFTLog";

FASTLOG_CONSTEXPR VERSION(VER_MAJOR * 1000 + VER_MINOR * 100 + VER_PATCH);

static std::string getProjectVersion()
{
	std::stringstream stream;
	stream << PROJECT << ":" << VER_MAJOR * 1000 << "."  <<VER_MINOR * 100 << "." << VER_PATCH;	
	return  stream.str();
};

FASTLOG_END