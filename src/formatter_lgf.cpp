#include "formatter_lgf.h"

inline void Lgfypp::Formatter::append(STRING_VIEW& s, fmt::memory_buffer& buf)
{
	fmt::format_to(buf, s);
}

Lgfypp::Formatter::Formatter()
{
	chrono = std::make_unique<LGF::Chrono>(LGF::Chrono());
	
	buffer.reserve(200);
}

void Lgfypp::Formatter::appendFormattedSVToBuf(STRING_VIEW& somstring, fmt::memory_buffer& buf)
{
	fmt::format_to(buf, "[{}]s", somstring);
}

void Lgfypp::Formatter::appendColorFormattedSVToBuf(STRING_VIEW& string, const char* color, fmt::memory_buffer& buf)
{
	fmt::format_to(buf, "{}[{}]{}", color, string, Lgfypp::Color::RESET_COLOR);
}

void Lgfypp::Formatter::appendColorSVToBuf(STRING_VIEW& string, const char* color, fmt::memory_buffer& buf)
{
	fmt::format_to(buf, "{}{}{}", color, string, Lgfypp::Color::RESET_COLOR);
}
template<typename T>
void Lgfypp::Formatter::appendDigitsToBuf(T digit, fmt::memory_buffer& buf)
{
	fmt::format_int digits(digit);
	buf.append(digits.data(), digits.data() + digits.size());
}