#include "chrono_lgf.h"
#include <logify.h>

void LGF::Chrono::getTimestamp(fmt::memory_buffer& buf)
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

	switch (gTimeFormat) {
	case Timeformat::standard:
		nowSs << std::put_time(&timeinfo, TIME_FORMAT)
			<< '.' << std::setfill('0') << std::setw(mPrecisionPad) << nowMs;
		break;
	case Timeformat::concise:
		nowSs << std::put_time(&timeinfo, TIME_FORMAT_SHORT)
			<< '.' << std::setfill('0') << std::setw(mPrecisionPad) << nowMs;
		break;
	case Timeformat::alternative:
		nowSs << std::put_time(&timeinfo, TIME_FORMAT_ALT)
			<< '.' << std::setfill('0') << std::setw(mPrecisionPad) << nowMs;
		break;
	default:
		nowSs << std::put_time(&timeinfo, TIME_FORMAT)
			<< '.' << std::setfill('0') << std::setw(mPrecisionPad) << nowMs;
	}

	fmt::format_to(buf, " {:<}", nowSs.str());

}

LGF::Chrono::Chrono() {}

LGF::Chrono::~Chrono(){}


template<typename T>
inline long long  LGF::Chrono::getSecondsWithPrecision(std::chrono::system_clock::time_point now)
{
	switch (gPrecision) {
	case Precision::milli: mPrecisionPad = 3;  return (std::chrono::duration_cast<T>(now.time_since_epoch()) % PRECISION_MOD_MILLI).count();
	case Precision::micro: mPrecisionPad = 6;  return (std::chrono::duration_cast<T>(now.time_since_epoch()) % PRECISION_MOD_MICRO).count();
	case Precision::nano: mPrecisionPad = 9;  return (std::chrono::duration_cast<T>(now.time_since_epoch()) % PRECISION_MOD_NANO).count();
	default: return 0;
	}
}