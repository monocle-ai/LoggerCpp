#pragma once
#include "lgfcore.h"

LGF_BEGIN

class ForbiddenCopy
{
	protected:
		ForbiddenCopy(void) {}

	private:
		ForbiddenCopy(const ForbiddenCopy&);
		ForbiddenCopy& operator=(const ForbiddenCopy&) = delete;
};

LGF_END