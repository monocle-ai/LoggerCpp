#pragma once
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <chrono>
#include <sstream>      // std::stringstream
#include <iomanip>

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
	static TIMEFORMAT format ;
	static std::string getTimestamp(FastLog::TIMEFORMAT format);
public:
	static void setTimeFormat(TIMEFORMAT value);
	static std::string getTimestamp();
	void write_date_time(char* buff, size_t buff_size);
};

FASTLOG_END