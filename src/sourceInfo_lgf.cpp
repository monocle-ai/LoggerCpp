#include "sourceInfo_lgf.h"
#include <thread>


void SourceInfo::addThreadInfo(fmt::memory_buffer& buf)
{
	fmt::format_to(buf, " {}", static_cast<void*>(std::this_thread::get_id));
}

SourceInfo::SourceInfo() : mFileName(nullptr), mFunction(nullptr), mLineNumber(0) {}

SourceInfo::~SourceInfo(){}

SourceInfo::SourceInfo(const char* function, int line, const char* file) : mFileName(file), mFunction(function), mLineNumber(line) {}

void SourceInfo::getFormattedSourceInfoWThread(fmt::memory_buffer& buf)
{
	if (mLineNumber != 0) {
		fmt::format_to(buf, "  <{}>@{}:{} ", mFileName, mFunction, mLineNumber);
		addThreadInfo(buf);
	}
}

void SourceInfo::getFormattedSourceInfo(fmt::memory_buffer& buf)
{
	if (mLineNumber != 0) {
		fmt::format_to(buf, "  <{}>@{}:{} ", mFileName, mFunction, mLineNumber);		
	}
}