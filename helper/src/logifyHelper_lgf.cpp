#include "logifyHelper_lgf.h"
#include "levelUtils_lgf.h"
#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_set>
#include <sys/stat.h>

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
	std::unordered_set<std::string> configs = { "LEVEL", "PRECISION" , "TIMEFORMAT", "COLOR" };
	auto it = gConfig.begin();
	while (it != gConfig.end())
	{
		auto findConfig = configs.find(it->first);
		(findConfig != configs.end()) ? (++it) : (it = gConfig.erase(it));
	}
	return gConfig;
}

/*
	Left-Right String Trimmer.
*/
std::string LgfHelper::stringTrim(std::string str)
{
	auto lSpace = str.find_first_not_of(WHITESPACES);
	str = (lSpace == std::string::npos) ? "" : str.substr(lSpace);
	auto rSpace = str.find_last_not_of(WHITESPACES);
	return (rSpace == std::string::npos) ? "" : str.substr(0, rSpace + 1);
}

std::string LgfHelper::toUpperCase(std::string& str) const
{
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
	return str;
}

std::string LgfHelper::toLowerCase(std::string& str) const
{
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}
bool LgfHelper::doesFileExist(const std::string& fileName) const
{
	struct stat buffer;
	return (stat(fileName.c_str(), &buffer) == 0);
}

}
