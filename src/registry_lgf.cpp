#include "registry_lgf.h"

template<typename T>
Lgfypp::Registry<T>::~Registry()
{
	if (!checkIfEmpty()) {
		cleanRegistry();
	}
}

template<typename T>
void Lgfypp::Registry<T>::initiateDefaultLogger()
{
	//TODO
}
template<typename T>
 void Lgfypp::Registry<T>::initiateSystemLogger()
{
	//TODO
}

template<typename T>
bool Lgfypp::Registry<T>::checkIfExists(const char* key)
{
	return loggerRegistry.contains(key);
}

template<typename T>
bool Lgfypp::Registry<T>::checkIfEmpty()
{
	return loggerRegistry.empty();
}

template<typename T>
int Lgfypp::Registry<T>::size()
{
	return loggerRegistry.size();
}

template<typename T>
LGF::Registry<T>& Lgfypp::Registry<T>::getInstance()
{
	static Registry sRegistry;
	return sRegistry;
}

template<typename T>
void Lgfypp::Registry<T>::registerLogger(const char* key, std::shared_ptr<T> value)
{
	if (!checkIfExists(key)) {
		loggerRegistry.insert(std::make_pair(key, std::move(value)));
	}
}

template<typename T>
T& Lgfypp::Registry<T>::getLogger(const char* key)
{
	return (checkIfExists(key)) ? loggerRegistry.at(key) : nullptr;
}

template<typename T>
void Lgfypp::Registry<T>::removeLogger(const char* key)
{
	std::lock_guard<std::mutex> gaurd(reg_mutex);

	LGF_TRY
	{
		loggerRegistry.erase(key);
	}
	LGF_CATCH()
}

template<typename T>
void Lgfypp::Registry<T>::cleanRegistry()
{
	std::lock_guard<std::mutex> gaurd(reg_mutex);
	for (auto it = loggerRegistry.begin(); it != loggerRegistry.end(); ++it) {
		it = loggerRegistry.erase(it);
	}
}