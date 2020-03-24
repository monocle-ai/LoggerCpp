#pragma once
#ifndef LGF_STATIC_BASE_H
#define LGF_STATIC_BASE_H

#include "core_lgf.h"

LGF_BEGIN

class LgfStaticBase
{
private:
	LgfStaticBase(void);
	LgfStaticBase(const LgfStaticBase&);
	LgfStaticBase& operator=(const LgfStaticBase&);
};

LGF_END

#endif