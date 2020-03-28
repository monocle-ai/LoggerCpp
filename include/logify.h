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
#ifndef LGF_LOGIFY_H
#define LGF_LOGIFY_H

#include "levelUtils_lgf.h"
#include "logifyBuilder_lgf.h"

//Log Macros

//#define LOGFY_V(verbosity, ...) Lgfypp::LogBuilder::log(verbosity, __FUNCTION__, __LINE__, __FILENAME__,  __VA_ARGS__)


//#define LOGFY(level, ...) LOGFY_V(Lgfypp::Level::##level, __VA_ARGS__)
//#define LOGFY_S(format , ...) Lgfypp::LogBuilder::log( format, __VA_ARGS__)

template<typename... arguments>
inline void Logify_s(const char* format, arguments... args) {
	Lgfypp::LogBuilder::log(format, args...);
};
template<typename... arguments>
inline void Logify_s(Lgfypp::Level level, const char* format, arguments... args) {
	Lgfypp::LogBuilder::log(level,format, args...);
};
#endif