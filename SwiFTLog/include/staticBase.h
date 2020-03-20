#pragma once
#include "logCore.h"

FASTLOG_BEGIN

class StaticBase 
{
private:
	StaticBase(void);
	StaticBase(const StaticBase&);
	StaticBase& operator=(const StaticBase&);
};

FASTLOG_END