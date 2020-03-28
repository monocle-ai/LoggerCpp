#include "sourceInfo_lgf.h"
#include <thread>

void SourceInfo::addThreadInfo(fmt::memory_buffer& buf)
{
	fmt::format_to(buf, " {}", reinterpret_cast<void*>(std::this_thread::get_id));
}

SourceInfo::~SourceInfo() {}
SourceInfo::SourceInfo() : mFileName(nullptr), mFunction(nullptr), mLineNumber(0), mThreadInfoReq(false) {}
SourceInfo::SourceInfo(const char* function, int line, const char* file) : mFileName(file), mFunction(function), mLineNumber(line), mThreadInfoReq(false) {}
SourceInfo::SourceInfo(const char* function, int line, const char* file, bool threadInfoReq) : mFileName(file), mFunction(function), mLineNumber(line), mThreadInfoReq(threadInfoReq) {}

void SourceInfo::getFormattedSourceInfo(fmt::memory_buffer& buf)
{
	if (mLineNumber != 0) {
		fmt::format_to(buf, "  <{}>@{}:{} ", mFileName, mFunction, mLineNumber);
		if (mThreadInfoReq) {
			addThreadInfo(buf);		}
	}
}