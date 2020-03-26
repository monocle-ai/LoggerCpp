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

If you contribute to this file please add your name to the contributors list below.

Author		 : Sayantan Roy
Contributors :
*/
#pragma once

#include "core_lgf.h"

#include "formatter_lgf.h"

#include <iostream>
#include "chrono_lgf.h"
#include "sourceInfo_lgf.h"
#include "levelUtils_lgf.h"

LGF_BEGIN

inline void log(Lgfypp::Level level, const char* file, int line, const char* function, ...) {
    fmt::memory_buffer buf;
    Lgfypp::Chrono sds(Lgfypp::PRECISION::milli, Lgfypp::TIMEFORMAT::standard);
    SourceInfo s1s(file, line, function);
    s1s.getFormattedSourceInfo(buf);
    sds.getTimestamp(buf);
    Lgfypp::Formatter ff;
    std::cout << toStringView(buf) << std::endl;
    STRING_VIEW ssdds("ADSAD");
    std::cout << "___________________________" << std::endl;
    ff.appendColorFormattedSVToBuf(ssdds, Lgfypp::Color::RED, buf);

    std::cout << toStringView(buf) << std::endl;
    std::cout << "___________________________" << toStringView(buf) << std::endl;
}

LGF_END