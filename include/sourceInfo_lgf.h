#pragma once
#include "stringView_lgf.h"
class SourceInfo
{
private:
	const char* mFunction;
	int mLineNumber = 0;
	const char* mFileName;

public:
	SourceInfo(const char* function,int line , const char* file);
	void getFormattedSourceInfo(fmt::memory_buffer& buf);
};

