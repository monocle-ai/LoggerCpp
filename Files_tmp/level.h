#pragma once

#include "logCore.h"

FASTLOG_BEGIN

	enum class LEVEL {
        /// @brief Turn off Logging
        NONE = 0,
        /// @brief Generic level that represents all the levels. Useful when setting global configuration for all levels
        ALL = 1,
        /// @brief Information that can be useful to back-trace certain events - mostly useful than debug logs.
        TRACE = 2,
        /// @brief Informational events most useful for developers to debug application
        DEBUG = 3,
        /// @brief Designates fine-grained informational events that are most useful to debug an application
        INFO = 4,
        /// @brief Useful when application has potentially harmful situtaions
        WARN = 5,
        /// @brief Severe error information that will presumably abort application
        FATAL = 6,
        /// @brief Information representing errors in application but application will keep running
        ERROR = 7,              
        /// @brief Represents unknown level
        UNKNOWN = 8
       
		};

FASTLOG_END