#pragma once
#include "logCore.h"

FASTLOG_BEGIN

class ForbiddenCopy
{
protected:
	ForbiddenCopy(void) {}
private:
	ForbiddenCopy(const ForbiddenCopy&);
	ForbiddenCopy& operator=(const ForbiddenCopy&) = delete;
};

FASTLOG_END