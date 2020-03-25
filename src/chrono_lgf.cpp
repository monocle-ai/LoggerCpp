#include "chrono_lgf.h"

void write_date_time(char* buff, size_t buff_size)
{
	auto now = std::chrono::system_clock::now();
	long long ms_since_epoch = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
	time_t sec_since_epoch = time_t(ms_since_epoch / 1000);
	tm time_info;
#if defined(__GNUC__)
	localtime_r(&sec_since_epoch, &time_info);
#else
	localtime_s(&time_info, &sec_since_epoch);
#endif

	snprintf(buff, buff_size, "%04d%02d%02d_%02d%02d%02d.%03lld",
		1900 + time_info.tm_year, 1 + time_info.tm_mon, time_info.tm_mday,
		time_info.tm_hour, time_info.tm_min, time_info.tm_sec, ms_since_epoch % 1000);
}

std::string Lgfypp::Chrono::getTimestamp()
{
	const auto now = std::chrono::system_clock::now();
	const auto nowAsTimeT = std::chrono::system_clock::to_time_t(now);
	const auto nowMs = getSecondsWithPrecision<std::chrono::milliseconds>(now);

	tm timeinfo;

#if defined(__GNUC__)
	localtime_r(&nowAsTimeT, &timeinfo);
#else
	localtime_s(&timeinfo, &nowAsTimeT);
#endif
	std::stringstream nowSs;
	switch (mFormat) {
	case TIMEFORMAT::standard:
		nowSs << std::put_time(&timeinfo, TIME_FORMAT)
			<< '.' << std::setfill('0') << std::setw(mPrecisionPad) << nowMs;
		break;
	case TIMEFORMAT::concise:
		nowSs << std::put_time(&timeinfo, TIME_FORMAT_SHORT)
			<< '.' << std::setfill('0') << std::setw(mPrecisionPad) << nowMs;
		break;
	case TIMEFORMAT::alternative:
		nowSs << std::put_time(&timeinfo, TIME_FORMAT_ALT)
			<< '.' << std::setfill('0') << std::setw(mPrecisionPad) << nowMs;
		break;
	default:
		nowSs << std::put_time(&timeinfo, DEF_TIMEFORMAT)
			<< '.' << std::setfill('0') << std::setw(mPrecisionPad) << nowMs;
	}
	return nowSs.str();
}

Lgfypp::Chrono::Chrono()
{
	mPrecision = Lgfypp::PRECISION::milli;
	mFormat = Lgfypp::TIMEFORMAT::standard;
}
Lgfypp::Chrono::~Chrono()
{
}
Lgfypp::Chrono::Chrono(PRECISION precision, TIMEFORMAT format)
{
	mPrecision = precision;
	mFormat = format;
}

template<typename T>
inline long long  Lgfypp::Chrono::getSecondsWithPrecision(std::chrono::system_clock::time_point now)
{
	switch (mPrecision) {
	case PRECISION::milli: mPrecisionPad = 3;  return (std::chrono::duration_cast<T>(now.time_since_epoch()) % MOD_MILLI).count();
	case PRECISION::micro: mPrecisionPad = 6;  return (std::chrono::duration_cast<T>(now.time_since_epoch()) % MOD_MICRO).count();
	case PRECISION::nano : mPrecisionPad = 9;  return (std::chrono::duration_cast<T>(now.time_since_epoch()) % MOD_NANO).count();
	}
}