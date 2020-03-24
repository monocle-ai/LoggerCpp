#pragma once
#ifndef LGF_FORMATTER_H
#define LGF_FORMATTER_H

#if defined(__GNUC__) && __GNUC__ < 7
# include <experimental/string_view>
# define STRING_VIEW std::experimental::string_view
#else
# include <string_view>
#define STRING_VIEW std::string_view
#endif

#include "lgfStaticBase.h"
#include "lgfLevelUtils.h"
#include "LgfStringView.h"

LGF_BEGIN

class LgfFormatter 
{
private:
    Lgfypp::LgfLevelUtils* pLevelUtils = new Lgfypp::LgfLevelUtils();
public:
    void toFormattedString(STRING_VIEW & string, fmt::memory_buffer& buf);
    void toColorFormattedString(STRING_VIEW & string, const char* color, fmt::memory_buffer& buf);
    void toColorString(STRING_VIEW& string, const char* color, fmt::memory_buffer& buf);

};

LGF_END

#endif