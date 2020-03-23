#pragma once

#include <stdint.h> // for including different datatype typedefs (e.g. uint32_t)



#define LGF_LITERAL(txt) (txt);
#define LGF_CONSTEXPR constexpr auto 
#define LGF_STATIC_CONSTEXPR static LGF_CONSTEXPR


// NAMESPACE

#define LGF_BEGIN namespace Lgfypp {
#define LGF_END }
#define LGF_SCOPE_ Lgfypp::

#define COLOR_BEGIN namespace Color {
#define COLOR_END }

//PROJECT DETAILS

LGF_CONSTEXPR VER_MAJOR = 0;
LGF_CONSTEXPR VER_MINOR = 0;
LGF_CONSTEXPR VER_PATCH = 0;
LGF_CONSTEXPR PROJECT = "Logify++";

LGF_CONSTEXPR VERSION(VER_MAJOR * 1000 + VER_MINOR * 100 + VER_PATCH);

inline std::string getProjectVersion()
{
	std::stringstream stream;
	stream << PROJECT << ":" << VER_MAJOR * 1000 << "." << VER_MINOR * 100 << "." << VER_PATCH;
	return  stream.str();
};