#include "formatter_lgf.h"

constexpr auto FORMAT_OPEN = "[";
constexpr auto FORMAT_CLOSE = "]";

void Lgfypp::Formatter::toFormattedString(STRING_VIEW& somstring, fmt::memory_buffer& buf)
{
	append(FORMAT_OPEN, buf);
	append(somstring, buf);
	append(FORMAT_CLOSE, buf);
}

void Lgfypp::Formatter::toColorFormattedString(STRING_VIEW& string, const char* color, fmt::memory_buffer& buf)
{
	append(color, buf);
	toFormattedString(string, buf);
	append(Lgfypp::Color::RESET_COLOR, buf);
}

void Lgfypp::Formatter::toColorString(STRING_VIEW& string,const char* color, fmt::memory_buffer& buf)
{
	append(color,buf);
	append(string, buf);
	append(Lgfypp::Color::RESET_COLOR,buf);
}
