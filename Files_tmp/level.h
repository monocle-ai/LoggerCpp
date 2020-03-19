#pragma once

#include "logCore.h"

FASTLOG_BEGIN

enum class Level : uint32_t
{
	/// @brief Turn off Logging
	none = 0,
	/// @brief Generic level that represents all the levels. Useful when setting global configuration for all levels
	all = 1,
	/// @brief Information that can be useful to back-trace certain events - mostly useful than debug logs.
	trace = 2,
	/// @brief Informational events most useful for developers to debug application
	debug = 3,
	/// @brief Designates fine-grained informational events that are most useful to debug an application
	info = 4,
	/// @brief Useful when application has potentially harmful situtaions
	warn = 5,
	/// @brief Severe error information that will presumably abort application
	fatal = 6,
	/// @brief Information representing errors in application but application will keep running
	error = 7,

	lastLevel = error,
};

FASTLOG_END