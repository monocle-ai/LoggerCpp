#include "sourceInfo_lgf.h"


void LGF::SourceInfo::addThreadInfo(fmt::memory_buffer& buf)
{
#if defined(__GNUC__)
	fmt::format_to(buf, " {}", static_cast<size_t>(std::hash<std::thread::id>()(std::this_thread::get_id())););
#else
	fmt::format_to(buf, " {}", static_cast<void*>(std::this_thread::get_id));
#endif
}

LGF::SourceInfo::~SourceInfo() {}
LGF::SourceInfo::SourceInfo() : mFileName(nullptr), mFunction(nullptr), mLineNumber(0), mThreadInfoReq(false) {}
LGF::SourceInfo::SourceInfo(const char* function, int line, const char* file) : mFileName(file), mFunction(function), mLineNumber(line), mThreadInfoReq(false) {}
LGF::SourceInfo::SourceInfo(const char* function, int line, const char* file, bool threadInfoReq) : mFileName(file), mFunction(function), mLineNumber(line), mThreadInfoReq(threadInfoReq) {}

void LGF::SourceInfo::getFormattedSourceInfo(fmt::memory_buffer& buf)
{
	if (mLineNumber != 0) {
		fmt::format_to(buf, "  <{}>@{}:{} ", mFileName, mFunction, mLineNumber);
		if (mThreadInfoReq) {
			addThreadInfo(buf);
		}
	}
}
