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

std::vector<std::tuple<STRING_VIEW, STRING_VIEW>> ConfigReader::getLoggerConfiguration() const
{
	std::ifstream configFile(m_configFilePath.data());
	std::string configVar;
	std::string configVal;
	std::vector<std::tuple<STRING_VIEW, STRING_VIEW>> globalConfigs;
	if (configFile.is_open())
	{
		std::string configLine;
		while (std::getline(configFile, configLine))
		{
			auto configDelimiter = configLine.find("=");
			if (configDelimiter != std::string::npos)
			{
				configVar = configLine.substr(0, configDelimiter);
				configVal = configLine.substr(configDelimiter + 1);
				fmt::memory_buffer bufVar;
				fmt::memory_buffer bufVal;
				std::cout << "\nconfig name is: " << covertToStringView(bufVar, configVar) << " config val is: " << covertToStringView(bufVal, configVal) << std::endl;
				globalConfigs.push_back({ covertToStringView(bufVar, configVar), covertToStringView(bufVal, configVal) });
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
