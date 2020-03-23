#pragma once
#ifndef  LGF_LOCKABLE_H
#define  LGF_LOCKABLE_H

#include <mutex>
#include "lgfForbiddenCopy.h"

LGF_BEGIN

class LgfLockable : LgfForbiddenCopy
{
private:
	std::mutex m_mutex ;

public:
	virtual void lock();
	virtual void unlock();
	virtual bool try_lock();
};

LGF_END
#endif