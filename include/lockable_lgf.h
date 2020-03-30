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
#ifndef  LGF_LOCKABLE_H
#define  LGF_LOCKABLE_H

#include <mutex>
#include "forbiddenCopy_lgf.h"

LGF_BEGIN

class Lockable : ForbiddenCopy
{
private:
	std::mutex m_mutex ;

public:
	virtual void lock();
	virtual void unlock();
	virtual bool try_lock();
};

LGF_END
#endif