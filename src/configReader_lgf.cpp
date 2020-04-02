#include "configReader_lgf.h"
#include <iostream>
#include <string>
#include <fstream>
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

std::unordered_map<STRING_VIEW, STRING_VIEW> ConfigReader::getLoggerConfiguration() const
{
	std::ifstream configFile(m_configFilePath.data());
	std::unordered_map<STRING_VIEW, STRING_VIEW> globalConfigs;
	if (configFile.is_open())
	{
		std::string configLine;
		while (std::getline(configFile, configLine))
		{
			auto configDelimiter = configLine.find("=");
			if (configDelimiter != std::string::npos)
			{
				fmt::memory_buffer bufVar;
				fmt::memory_buffer bufVal;
				STRING_VIEW configKey = covertToStringView(bufVar, configLine.substr(0, configDelimiter));
				STRING_VIEW configVal = covertToStringView(bufVal, configLine.substr(configDelimiter + 1));
				std::cout << "\nconfig name is: " << configKey << " config val is: " << configVal << std::endl;
				globalConfigs.emplace(configKey, configVal);
			}
		}
	}
	return globalConfigs;
}

STRING_VIEW ConfigReader::covertToStringView(fmt::memory_buffer& buffer, const std::string& config) const
{
	fmt::format_to(buffer, config);
	return toStringView(buffer);
}

}
