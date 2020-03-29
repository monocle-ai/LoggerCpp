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
#include "staticBase_lgf.h"

class Log : public LGF::StaticBase
{
public:
	// Functions for Warnings level
	static void w(const char* msg);	
	static void warn(const char* msg);
	template<typename... arguments>
	static void w(const char* format, arguments&... args);
	template<typename... arguments>
	static void warn(const char* format, arguments&... args);
};


template<typename... arguments>
inline void Logify(LGF::Level level, const char* format, arguments... args) {
	LGF::LogBuilder::log(level, format, __FUNCTION__, __LINE__, __FILENAME__, args...);
};
template<typename... arguments>
inline void Logify(const char* msg) {
	LGF::LogBuilder::log(msg);
};
template<typename... arguments>
inline void Logify(const char* format, arguments... args) {
	LGF::LogBuilder::log(format, args...);
};

#endif

template<typename ...arguments>
void Log::warn(const char* format, arguments& ...args)
{
	Lgfypp::LogBuilder::log(LGF::Level::warn, format, args...);
}
