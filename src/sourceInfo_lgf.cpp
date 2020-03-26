#include "sourceInfo_lgf.h"

SourceInfo::SourceInfo(const char* function, int line, const char* file) : mFileName(file), mFunction(function), mLineNumber(line){}

void SourceInfo::getFormattedSourceInfo(fmt::memory_buffer& buf)
{	
	fmt::format_to(buf, "[{}]-{}:{}", mFileName,mFunction,mLineNumber);	
}
