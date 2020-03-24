#include "LgfStringView.h"

STRING_VIEW Lgfypp::LgfStringView::toStringView(const fmt::memory_buffer& buf)
{
	return STRING_VIEW{ buf.data(), buf.size() };
}

void Lgfypp::LgfStringView::append(STRING_VIEW strView, fmt::memory_buffer& buf)
{
	auto* buf_ptr = strView.data();
	if (buf_ptr != nullptr)
	{
		buf.append(buf_ptr, buf_ptr + buf.size());
	}
}

template<typename T>
inline void Lgfypp::LgfStringView::appendDigits(T digit, fmt::memory_buffer& buf)
{
	fmt::format_int digit(digit);
	some.append(digit.data(), digit.data() + digit.size());
}