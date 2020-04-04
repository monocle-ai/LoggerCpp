#include "logifyHelper_lgf.h"
#include "levelUtils_lgf.h"
#include<iostream>
#include<unordered_set>

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
	std::unordered_set<std::string> configs = { "Level", "Precision" , "TimeFormat", "Color" };
	auto it = gConfig.begin();
	while (it != gConfig.end())
	{
		auto findConfig = configs.find(it->first);
		(findConfig != configs.end()) ? (++it) : (it = gConfig.erase(it));
	}
	return gConfig;
}
}
