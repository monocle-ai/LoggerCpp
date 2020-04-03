/*
MIT License

Copyright(c) 2020 Sayantan Roy

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
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
#include "core_lgf.h"
#include "fmt/format.h"
#include "fmt/color.h"

//PROJECT DETAILS
LGF_CONSTEXPR_AUTO VER_MAJOR = 0;
LGF_CONSTEXPR_AUTO VER_MINOR = 0;
LGF_CONSTEXPR_AUTO VER_PATCH = 0;
LGF_CONSTEXPR_AUTO PROJECT = "Logify++";

LGF_CONSTEXPR_AUTO VERSION(VER_MAJOR * 1000 + VER_MINOR * 100 + VER_PATCH);

inline void getProjectVersion()
{
	fmt::memory_buffer buf;
	fmt::print(fmt::emphasis::bold | fg(fmt::color::aquamarine),"{} : version {}.{}.{}", PROJECT, VER_MAJOR, VER_MINOR , VER_PATCH);
};