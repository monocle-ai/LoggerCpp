#include "logify.h"



 void Log::warn(const char* msg)
{
	Lgfypp::LogBuilder::log(msg);
}
