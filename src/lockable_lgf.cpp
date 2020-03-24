#include "lockable_lgf.h"

void Lgfypp::Lockable::lock()
{
	this->m_mutex.lock();
}

void Lgfypp::Lockable::unlock()
{
	this->m_mutex.unlock();
}

bool Lgfypp::Lockable::try_lock()
{
	return this->m_mutex.try_lock();
}
