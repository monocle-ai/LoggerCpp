#pragma once
#include "lgfcore.h"

LGF_BEGIN

class StaticBase
{
private:
	StaticBase(void);
	StaticBase(const StaticBase&);
	StaticBase& operator=(const StaticBase&);
};

LGF_END