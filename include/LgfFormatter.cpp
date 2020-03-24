#include "LgfFormatter.h"
#include <iostream>

const STRING_VIEW Lgfypp::LgfFormatter::toFormattedString(STRING_VIEW& somstring, fmt::memory_buffer& buf)
{
	
	STRING_VIEW ss(pLevelUtils->toString(Lgfypp::Level::debug));
	std::cout << "____________ss______________: " << ss << std::endl;
	std::cout << "____________ss______________: " << somstring << std::endl;
	append(somstring, buf);
	std::cout << "____________s2s_______________" << buf.size() << std::endl;
	append(ss, buf);
	std::cout << "____________s3s_______________" << buf.size() << std::endl;
	return toStringView(buf);
}
