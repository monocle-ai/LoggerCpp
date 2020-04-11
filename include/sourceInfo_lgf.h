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
#ifndef LGF_SOURCE_INFO
#define LGF_SOURCE_INFO

#if defined(_WIN32)
#include <windows.h>
#elif defined(__linux__)
#include <sys/syscall.h>
#include <unistd.h>
#endif
#include "fmt/format.h"
#include "core_lgf.h"
#include <thread>
#include <tuple>

#pragma comment(lib, "user32.lib")
LGF_BEGIN

class SourceInfo
{
private:
	SourceInfo() {}
	LGF_INLINE static uint32_t getThreadId() noexcept {
#if defined(_WIN32)
		return static_cast<uint32_t>(::GetCurrentThreadId());
#elif defined(__linux__)
		return static_cast<uint32_t>(::syscall(SYS_gettid));
#endif
	}
	LGF_INLINE static int getProcessId() noexcept {
#ifdef _WIN32
		return static_cast<int>(::GetCurrentProcessId());
#elif defined(__linux__)
		return static_cast<int>(::getpid());
#endif
	}

public:
	LGF_INLINE static std::tuple<const char*, const char*, int, uint32_t, int> current(const char* file, const char* func, int line, bool threadInfoReq = true) noexcept {
		if (line != 0 && threadInfoReq) {
			return  { file, func, line , getThreadId(), getProcessId() };
		}
		return  { file, func, line, 0, 0 };
	}

	~SourceInfo() {}
};

LGF_END
#endif