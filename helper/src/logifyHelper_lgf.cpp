#include "logifyHelper_lgf.h"

namespace Lgfypp
{
LgfHelper::LgfHelper()
{
}
LgfHelper::~LgfHelper()
{
}
LgfHelper& LgfHelper::getHelperInstance()
{
	static LgfHelper lgfHelper;
	return lgfHelper;
}

/*
	Discard Illegal or invalid configs and respective values.
	If the config names are valid but values are not, replace with a default.
	If the config names are invaild that <Key, value> will be deleted.
*/
std::unordered_map<std::string, std::string> LgfHelper::discardInvalidConfig(std::unordered_map<std::string, std::string>& gConfig) const
{
	auto it = gConfig.begin();
	while (it != gConfig.end())
	{
		(it->first == "Level" || it->first == "Precision"
			|| it->first == "TimeFormat" || it->first == "Color") ? (++it) : (it = gConfig.erase(it));

	}
	return gConfig;
}
}
