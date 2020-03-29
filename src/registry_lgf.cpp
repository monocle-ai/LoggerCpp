#include "registry_lgf.h"

template<typename T>
Lgfypp::Registry<T>::~Registry()
{
	//delete default and system loggers and then remove all.
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
	return loggerMap.contains(key);
}

template<typename T>
bool Lgfypp::Registry<T>::checkIfEmpty()
{
	return loggerMap.empty();
}

template<typename T>
int Lgfypp::Registry<T>::size()
{
	return loggerMap.size();
}

template<typename T>
void Lgfypp::Registry<T>::registerLogger(const char* key, T& value)
{
	if (!checkIfExists(key)) {
		loggerMap.insert(std::make_pair(key, value));
	}
}

template<typename T>
T& Lgfypp::Registry<T>::getLogger(const char* key)
{
	return (checkIfExists(key)) ? loggerMap.at(key) : nullptr;
}

template<typename T>
void Lgfypp::Registry<T>::removeLogger(const char* key)
{
	std::lock_guard<std::mutex> gaurd(std::reg_mutex);
	try {
		loggerMap.erase(key);
	}
	catch (std::exception ex) {
	}
}

template<typename T>
void Lgfypp::Registry<T>::cleanRegistry()
{
	std::lock_guard<std::mutex> gaurd(std::reg_mutex);
	for (auto it = loggerMap.begin(); it != loggerMap.end(); ++it) {
		it = loggerMap.erase(it);
	}
}