#include "clock.h"

FastLog::TIMEFORMAT FastLog::clock::format;

void FastLog::clock::setTimeFormat(TIMEFORMAT value)
{
	format = value;
}

std::string FastLog::clock::getTimestamp()
{
	return getTimestamp(format);
}

void write_date_time(char* buff, size_t buff_size)
{
	auto now = std::chrono::system_clock::now();
	long long ms_since_epoch = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
	time_t sec_since_epoch = time_t(ms_since_epoch / 1000);
	tm time_info;
#if defined(__GNUC__)
	localtime_r(&sec_since_epoch, &time_inf);
#else
	localtime_s(&time_info, &sec_since_epoch);
#endif

	snprintf(buff, buff_size, "%04d%02d%02d_%02d%02d%02d.%03lld",
		1900 + time_info.tm_year, 1 + time_info.tm_mon, time_info.tm_mday,
		time_info.tm_hour, time_info.tm_min, time_info.tm_sec, ms_since_epoch % 1000);
}

std::string FastLog::clock::getTimestamp(TIMEFORMAT format)
{
	const auto now = std::chrono::system_clock::now();
	const auto nowAsTimeT = std::chrono::system_clock::to_time_t(now);
	const auto nowMs = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000; // change precision
	tm timeinfo;
	
#if defined(__GNUC__)
	localtime_r(&nowAsTimeT, &timeinfo);
#else
	localtime_s(&timeinfo, &nowAsTimeT);	
#endif
	std::stringstream nowSs;
	switch (format) {
	case TIMEFORMAT::STANDARD:
		nowSs << std::put_time(&timeinfo, TIME_FORMAT)
			<< '.' << std::setfill('0') << std::setw(3) << nowMs.count();
		break;
	case TIMEFORMAT::SHORT:
		nowSs << std::put_time(&timeinfo, TIME_FORMAT_SHORT)
			<< '.' << std::setfill('0') << std::setw(3) << nowMs.count();
		break;
	case TIMEFORMAT::ALTERNATIVE:
		nowSs << std::put_time(&timeinfo, TIME_FORMAT_ALT)
			<< '.' << std::setfill('0') << std::setw(3) << nowMs.count();
		break;
	default:
		nowSs << std::put_time(&timeinfo, DEF_TIMEFORMAT)
			<< '.' << std::setfill('0') << std::setw(3) << nowMs.count();
	}

	return nowSs.str();
}
