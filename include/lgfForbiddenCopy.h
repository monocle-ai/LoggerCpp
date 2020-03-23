#pragma once
#ifndef LGF_FORBIDDEN_COPY_H
#define LGF_FORBIDDEN_COPY_H

#include "lgfcore.h"

LGF_BEGIN

class LgfForbiddenCopy
{
	protected:
		LgfForbiddenCopy(void) {}

	private:
		LgfForbiddenCopy(const LgfForbiddenCopy&);
		LgfForbiddenCopy& operator=(const LgfForbiddenCopy&) = delete;
};

LGF_END

#endif