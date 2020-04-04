#include "configReader_lgf.h"
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include "interface/iConfigReader_lgf.h"

namespace LGF
{
ConfigReader::ConfigReader(
	const STRING_VIEW configFilePath)
	: m_configFilePath(configFilePath) {}

/*Lgfypp::IConfigReaderSharedPtr& Lgfypp::ConfigReader::configReaderFactory(
	const STRING_VIEW configFilePath)
{
	if (!configFilePath.empty())
	{
		return Lgfypp::IConfigReaderSharedPtr(new ConfigReader(configFilePath));
	}
	return Lgfypp::IConfigReaderSharedPtr(new ConfigReader(STRING_VIEW{""}));
}*/

std::unordered_map<std::string, std::string> ConfigReader::getLoggerConfiguration() const
{
	std::ifstream configFile(m_configFilePath.data());
	std::unordered_map<std::string, std::string> globalConfigs;
	if (configFile.is_open())
	{
		std::string configLine;
		while (std::getline(configFile, configLine))
		{
			auto configDelimiter = configLine.find("=");
			if (configDelimiter != std::string::npos)
			{
				globalConfigs.emplace(
					configLine.substr(0, configDelimiter),
					configLine.substr(configDelimiter + 1));
			}
		}
	}
	return discardInvalidConfig(globalConfigs);
}

STRING_VIEW ConfigReader::covertToStringView(fmt::memory_buffer& buffer, const std::string& config) const
{
	fmt::format_to(buffer, config);
	return toStringView(buffer);
}

/*
	Discard Illegal or invalid configs and respective values.
	If the config names are valid but values are not, replace with a default. 
	If the config names are invaild that <Key, value> will be deleted.
*/

std::unordered_map<std::string, std::string> ConfigReader::discardInvalidConfig(std::unordered_map<std::string, std::string>& gConfig) const
{
	auto it = gConfig.begin();
	while(it != gConfig.end())
	{
		(it->first == "Level" || it->first == "Precision"
			|| it->first == "TimeFormat" || it->first == "Color") ? (++it) : (it = gConfig.erase(it));
	}
	return gConfig;
}

}
