#pragma once
#ifndef LGF_FORMATTER_H
#define LGF_FORMATTER_H
/*
MIT License

Copyright(c) 2020 Sayantan Roy and Dipanjan Das

Permission is hereby granted, free of charge, to any person obtaining a copy
of this softwareand associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright noticeand this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#if defined(__GNUC__) && __GNUC__ < 7
# include <experimental/string_view>
# define STRING_VIEW std::experimental::string_view
#else
# include <string_view>
#define STRING_VIEW std::string_view
#endif

#include "staticBase_lgf.h"
#include "levelUtils_lgf.h"
#include "stringView_lgf.h"

LGF_BEGIN

class Formatter 
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