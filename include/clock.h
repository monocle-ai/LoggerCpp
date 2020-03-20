#pragma once

#include <chrono>
#include <sstream>      // std::stringstream
#include <iomanip>
#include <string_view>
#include "staticBase.h"
#include "logCore.h"

FASTLOG_CONSTEXPR TIME_FORMAT = "%F %T";
FASTLOG_CONSTEXPR TIME_FORMAT_ALT = "%D %T";
FASTLOG_CONSTEXPR TIME_FORMAT_SHORT = "%T";

FASTLOG_CONSTEXPR DEF_TIMEFORMAT = TIME_FORMAT;

FASTLOG_BEGIN

enum class TIMEFORMAT { STANDARD, SHORT, ALTERNATIVE };
class clock : StaticBase
{
	static inline  TIMEFORMAT format = TIMEFORMAT::STANDARD;
	static std::string getTimestamp(FastLog::TIMEFORMAT format);
public:
	static void setTimeFormat(TIMEFORMAT value);
	static std::string getTimestamp();
	void write_date_time(char* buff, size_t buff_size);
};

FASTLOG_END