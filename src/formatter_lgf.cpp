#include "formatter_lgf.h"

constexpr auto FORMAT_OPEN = "[";
constexpr auto FORMAT_CLOSE = "]";

void Lgfypp::Formatter::appendFormattedSVToBuf(STRING_VIEW& somstring, fmt::memory_buffer& buf)
{
	append(FORMAT_OPEN, buf);
	append(somstring, buf);
	append(FORMAT_CLOSE, buf);
}

void Lgfypp::Formatter::appendColorFormattedSVToBuf(STRING_VIEW& string, const char* color, fmt::memory_buffer& buf)
{
	append(color, buf);
	appendFormattedSVToBuf(string, buf);
	append(Lgfypp::Color::RESET_COLOR, buf);
}

void Lgfypp::Formatter::appendColorSVToBuf(STRING_VIEW& string, const char* color, fmt::memory_buffer& buf)
{
	append(color, buf);
	append(string, buf);
	append(Lgfypp::Color::RESET_COLOR, buf);
}
template<typename T>
void Lgfypp::Formatter::appendDigitsToBuf(T digit, fmt::memory_buffer& buf)
{
	appendDigitsToBuf(digit, buf);
}