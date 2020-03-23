// include directory added to visual studio VC++ directory, don't need relative path.
// TODO: remove this comment, later.
#include "lgfLevelUtils.h"
#include <iostream>

#include "lgfcore.h"
#include "lgfTime.h"

// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#endif

#include "example.h"

int main()
{
	std::cout << Lgfypp::lgfTime::getTimestamp() << std::endl;

	/*std::cout << FastLog::lgfLevelUtils::toColorString(FastLog::Level::fatal) << "sssssss" << std::endl;
	std::cout << FastLog::lgfLevelUtils::toColorString(FastLog::Level::warn) << "sssssss" << std::endl;
	std::cout << FastLog::lgfLevelUtils::toColorString(FastLog::lgfLevelUtils::toLevel(5)) << "sssssdddss" << std::endl;
	std::cout << FastLog::lgfLevelUtils::toFormattedColorShortString(FastLog::Level::info) << "sssssss" << std::endl;
	std::cout << FastLog::lgfLevelUtils::toShortString(FastLog::Level::trace) << FastLog::getProjectVersion() << std::endl;
	std::cout << FastLog::lgfLevelUtils::toColorString(FastLog::Level::error) << FastLog::VERSION << std::endl;*/
	std::cout << Lgfypp::lgfTime::getTimestamp() << std::endl;
	Lgfypp::lgfTime::setTimeFormat(Lgfypp::TIMEFORMAT::SHORT);
	std::cout << Lgfypp::lgfTime::getTimestamp() << std::endl;
	Lgfypp::lgfTime::setTimeFormat(Lgfypp::TIMEFORMAT::ALTERNATIVE);
	std::cout << Lgfypp::lgfTime::getTimestamp() << std::endl;
	return 0;
}
