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
#pragma once
#ifndef LGF_COLOR_H
#define LGF_COLOR_H

#include "core_lgf.h"

#ifdef _WIN32
#define COLOR(ID) ("\x1b[1;" #ID "m")
#else
#define COLOR(ID) ("\x1b[" #ID "m")
#endif

LGF_BEGIN
COLOR_BEGIN

LGF_STATIC_CONSTEXPR RESET_COLOR     = COLOR(0);
LGF_STATIC_CONSTEXPR BLACK			 = COLOR(30);
LGF_STATIC_CONSTEXPR RED			 = COLOR(31);
LGF_STATIC_CONSTEXPR GREEN			 = COLOR(32);
LGF_STATIC_CONSTEXPR YELLOW		     = COLOR(33);
LGF_STATIC_CONSTEXPR BLUE			 = COLOR(34);
LGF_STATIC_CONSTEXPR MAGENTA		 = COLOR(35);
LGF_STATIC_CONSTEXPR CYAN			 = COLOR(36);
LGF_STATIC_CONSTEXPR WHITE			 = COLOR(37);
LGF_STATIC_CONSTEXPR LIGHT_GRAY	     = COLOR(90);
LGF_STATIC_CONSTEXPR LIGHT_RED		 = COLOR(91);
LGF_STATIC_CONSTEXPR LIGHT_GREEN	 = COLOR(92);
LGF_STATIC_CONSTEXPR LIGHT_YELLOW	 = COLOR(93);
LGF_STATIC_CONSTEXPR LIGHT_BLUE	     = COLOR(94);
LGF_STATIC_CONSTEXPR LIGHT_MAGENTA	 = COLOR(95);
LGF_STATIC_CONSTEXPR LIGHT_CYAN	     = COLOR(96);
LGF_STATIC_CONSTEXPR LIGHT_WHITE	 = COLOR(97);

COLOR_END
LGF_END

#endif