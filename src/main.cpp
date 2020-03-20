// include directory added to visual studio VC++ directory, don't need relative path.
// TODO: remove this comment, later.
#include "levelUtils.h"
#include <iostream>
#include "clock.h"
#include "logCore.h"
#include "version.h"

int main()
{
	std::cout << FastLog::clock::getTimestamp() << std::endl;

	std::cout << FastLog::levelUtils::toColorString(FastLog::LEVEL::FATAL) << "sssssss" << std::endl;
	std::cout << FastLog::levelUtils::toColorString(FastLog::LEVEL::WARN) << "sssssss" << std::endl;
	std::cout << FastLog::levelUtils::toColorString(FastLog::levelUtils::toLevel(5)) << "sssssdddss" << std::endl;
	std::cout << FastLog::levelUtils::toFormattedColorShortString(FastLog::LEVEL::INFO) << "sssssss" << std::endl;
	std::cout << FastLog::levelUtils::toShortString(FastLog::LEVEL::TRACE) << FastLog::getProjectVersion() << std::endl;
	std::cout << FastLog::levelUtils::toColorString(FastLog::LEVEL::ERROR) << FastLog::VERSION << std::endl;
	std::cout << FastLog::clock::getTimestamp() << std::endl;
	FastLog::clock::setTimeFormat(FastLog::TIMEFORMAT::SHORT);
	std::cout << FastLog::clock::getTimestamp() << std::endl;
	FastLog::clock::setTimeFormat(FastLog::TIMEFORMAT::ALTERNATIVE);
	std::cout << FastLog::clock::getTimestamp() << std::endl;
	return 0;
}
