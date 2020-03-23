#include "lgfLockable.h"

void Lgfypp::LgfLockable::lock()
{
	this->m_mutex.lock();
}

void Lgfypp::LgfLockable::unlock()
{
	this->m_mutex.unlock();
}

bool Lgfypp::LgfLockable::try_lock()
{
	return this->m_mutex.try_lock();
}
