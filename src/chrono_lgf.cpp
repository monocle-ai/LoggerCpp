#include "chrono_lgf.h"
#include "fmt/chrono.h"

LGF::Chrono::Chrono() {}
LGF::Chrono::~Chrono() {}

std::tuple<tm, long long> LGF::Chrono::getTimestamp(fmt::memory_buffer& buf)
{
	const auto now = std::chrono::system_clock::now();
	const auto nowAsTimeT = std::chrono::system_clock::to_time_t(now);
	const auto nowMs = getSecondsWithPrecision(now);
	auto timeinfo = fmt::localtime(nowAsTimeT);
	fmt::format_to(buf, "{:%F %T}.{:0^3}", timeinfo, nowMs);
	return { timeinfo, nowMs };

}

std::tuple<tm, long long> LGF::Chrono::getTimestamp()
{
	const auto now = std::chrono::system_clock::now();
	const auto nowAsTimeT = std::chrono::system_clock::to_time_t(now);
	const auto nowMs = getSecondsWithPrecision(now);
	auto timeinfo = fmt::localtime(nowAsTimeT);

	return { timeinfo, nowMs };

}

LGF_INLINE long long  LGF::Chrono::getSecondsWithPrecision(std::chrono::system_clock::time_point const now)
{
	switch (gPrecision) {
	case Precision::milli: return ((std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % PRECISION_MOD_MILLI).count());
	case Precision::micro: return ((std::chrono::duration_cast<std::chrono::microseconds>(now.time_since_epoch()) % PRECISION_MOD_MICRO).count()) ;
	case Precision::nano : return ((std::chrono::duration_cast<std::chrono::nanoseconds> (now.time_since_epoch()) % PRECISION_MOD_NANO ).count()) ;
	default: return 0;
	}
}