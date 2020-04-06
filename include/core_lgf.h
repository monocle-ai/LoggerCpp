/*
MIT License

Copyright(c) 2020 Sayantan Roy

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

If you contribute to this file please add your name to the contributors list below.

Author		 : Sayantan Roy
Contributors :
*/

#pragma once
#ifndef LGF_CORE_H
#define LGF_CORE_H

#include <stdint.h> // for including different datatype typedefs (e.g. uint32_t)
#include <sstream>
#include "fmt/format.h"

#define LGF_LITERAL(txt) (txt);
#define LGF_CONSTEXPR_AUTO constexpr auto
#define LGF_STATIC_CONSTEXPR static LGF_CONSTEXPR_AUTO
#define LGF_INLINE inline
#define LGF_FORCE_INLINE __forceinline

// Attributes
#define LGF_FALLTHROUGH    [[fallthrough]]
#define LGF_NODISCARD      [[nodiscard]]
#define LGF_MAYBE_UNUSED   [[maybe_unused]]
#define LGF_MAYBE_USED     [[maybe_used]]
#define LGF_NORETURN       [[noreturn]]
#define LGF_DEPRECATED     [[deprecated]]


// ------------------ NAMESPACES ----------------------------


#define LGF_BEGIN namespace Lgfypp {
#define LGF_END }
#define LGF Lgfypp

#define COLOR_BEGIN namespace Lgfypp::Color {
#define COLOR_END }

#define INTERNAL_BEGIN namespace Lgfypp::Internal {
#define INTERNAL_END }

#define LGF_TRY try
#define LGF_CATCH()                            \
    catch (const std::exception& ex)           \
    {                                          \
        fmt::print(ex.what());                 \
    }                                          \
    catch (...)                                \
    {                                          \
        fmt::print("Unknown Exception");       \
    }
//File name stripper
#if defined(_WIN32)
static constexpr char delimiter = '\\';
#else
static constexpr char delimiter = '/';
#endif

#define __FILENAME__ (strrchr(__FILE__, delimiter) ? strrchr(__FILE__, delimiter) + 1 : __FILE__)


#if defined(__GNUC__) && __GNUC__ < 7
# include <experimental/string_view>
# define STRING_VIEW std::experimental::string_view
#else
# include <string_view>
#define STRING_VIEW std::string_view
#endif

inline STRING_VIEW toStringView(const fmt::memory_buffer& buf)
{
	return STRING_VIEW{ buf.data(), buf.size() };
}

#endif