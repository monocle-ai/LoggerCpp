// include directory added to visual studio VC++ directory, don't need relative path.
// TODO: remove this comment, later.
#include "levelUtils_lgf.h"
#include <iostream>
#include "chrono_lgf.h"
#include "core_lgf.h"
#include <fmt/format.h>	

#include <stringView_lgf.h>
#include "formatter_lgf.h"

int main()
{
	Lgfypp::Chrono sds (Lgfypp::PRECISION::milli, Lgfypp::TIMEFORMAT::standard);

	std::cout << sds.getTimestamp() << std::endl;
	fmt::print("Hello, {}!", "world");  // Python-like format string syntax
	/*std::cout << Lgfypp::LgfLevelUtils::toColorString(Lgfypp::Level::fatal) << "sssssss" << std::endl;
	std::cout << Lgfypp::LgfLevelUtils::toColorString(Lgfypp::Level::warn) << "sssssss" << std::endl;
	std::cout << Lgfypp::LgfLevelUtils::toColorString(Lgfypp::LgfLevelUtils::toLevel(5)) << "sssssdddss" << std::endl;
	std::cout << Lgfypp::LgfLevelUtils::toFormattedColorShortString(Lgfypp::Level::info) << "sssssss" << std::endl;
	std::cout << Lgfypp::LgfLevelUtils::toShortString(Lgfypp::Level::trace) << getProjectVersion() << std::endl;*/
	Lgfypp::Formatter ss;
	STRING_VIEW ssdds("dsdada");
	fmt::memory_buffer out;
	std::cout << "___________________________" << std::endl;
	ss.appendColorFormattedSVToBuf(ssdds, Lgfypp::Color::RED, out);
	std::cout << Lgfypp::toStringView(out)<< std::endl ;
	std::cout << "___________________________" << Lgfypp::toStringView(out) << std::endl;

	return 0;
}
