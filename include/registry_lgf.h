/*
MIT License

Copyright(c) 2020 Sayantan Roy and Dipanjan Das

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
#ifndef LGF_REGISTRY_H
#define LGF_REGISTRY_H
#include <unordered_map>
#include <mutex>

#include "core_lgf.h"

LGF_BEGIN
template<typename T>
class Registry
{
private:
	Registry();
	~Registry();
	void initiateDefaultLogger();
	void initiateSystemLogger();
	static std::mutex reg_mutex;
	std::unordered_map<const char* , T > loggerMap;
	bool checkIfExists(const char* key);
	bool checkIfEmpty();
	int size();
public:
	void registerLogger(const char* key, T& value);
	T& getLogger(const char* key);
	void removeLogger(const char* key);
	void cleanRegistry();
};

LGF_END

#endif