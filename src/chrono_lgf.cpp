#include "chrono_lgf.h"
#include <logify.h>

void Lgfypp::Chrono::getTimestamp(fmt::memory_buffer& buf)
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

	fmt::format_to(buf, " {:<}", nowSs.str());

}

Lgfypp::Chrono::Chrono() : mPrecision(Lgfypp::PRECISION::milli), mFormat(Lgfypp::TIMEFORMAT::standard){}

Lgfypp::Chrono::~Chrono(){}

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
	case PRECISION::nano: mPrecisionPad = 9;  return (std::chrono::duration_cast<T>(now.time_since_epoch()) % MOD_NANO).count();
	default: return 0;
	}
}