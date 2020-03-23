// include directory added to visual studio VC++ directory, don't need relative path.
// TODO: remove this comment, later.
#include "levelUtils.h"
#include <iostream>
#include "lgftime.h"
#include "lgfcore.h"
#include "version.h"

int main()
{
	std::cout << Lgfypp::lgftime::getTimestamp() << std::endl;

	/*std::cout << FastLog::levelUtils::toColorString(FastLog::Level::fatal) << "sssssss" << std::endl;
	std::cout << FastLog::levelUtils::toColorString(FastLog::Level::warn) << "sssssss" << std::endl;
	std::cout << FastLog::levelUtils::toColorString(FastLog::levelUtils::toLevel(5)) << "sssssdddss" << std::endl;
	std::cout << FastLog::levelUtils::toFormattedColorShortString(FastLog::Level::info) << "sssssss" << std::endl;
	std::cout << FastLog::levelUtils::toShortString(FastLog::Level::trace) << FastLog::getProjectVersion() << std::endl;
	std::cout << FastLog::levelUtils::toColorString(FastLog::Level::error) << FastLog::VERSION << std::endl;*/
	std::cout << Lgfypp::lgftime::getTimestamp() << std::endl;
	Lgfypp::lgftime::setTimeFormat(Lgfypp::TIMEFORMAT::SHORT);
	std::cout << Lgfypp::lgftime::getTimestamp() << std::endl;
	Lgfypp::lgftime::setTimeFormat(Lgfypp::TIMEFORMAT::ALTERNATIVE);
	std::cout << Lgfypp::lgftime::getTimestamp() << std::endl;
	return 0;
}
