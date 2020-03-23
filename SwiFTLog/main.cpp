// include directory added to visual studio VC++ directory, don't need relative path.
// TODO: remove this comment, later.
#include "levelUtils.h"
#include <iostream>
#include "clock.h"
#include "logCore.h"
#include "version.h"
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
	std::cout << FastLog::clock::getTimestamp() << std::endl;

	/*std::cout << FastLog::levelUtils::toColorString(FastLog::Level::fatal) << "sssssss" << std::endl;
	std::cout << FastLog::levelUtils::toColorString(FastLog::Level::warn) << "sssssss" << std::endl;
	std::cout << FastLog::levelUtils::toColorString(FastLog::levelUtils::toLevel(5)) << "sssssdddss" << std::endl;
	std::cout << FastLog::levelUtils::toFormattedColorShortString(FastLog::Level::info) << "sssssss" << std::endl;
	std::cout << FastLog::levelUtils::toShortString(FastLog::Level::trace) << FastLog::getProjectVersion() << std::endl;
	std::cout << FastLog::levelUtils::toColorString(FastLog::Level::error) << FastLog::VERSION << std::endl;*/
	std::cout << FastLog::clock::getTimestamp() << std::endl;
	FastLog::clock::setTimeFormat(FastLog::TIMEFORMAT::SHORT);
	std::cout << FastLog::clock::getTimestamp() << std::endl;
	FastLog::clock::setTimeFormat(FastLog::TIMEFORMAT::ALTERNATIVE);
	std::cout << FastLog::clock::getTimestamp() << std::endl;
	return 0;
}
