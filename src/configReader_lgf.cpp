#include "configReader_lgf.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

namespace LGF
{
	ConfigReader::ConfigReader(const std::shared_ptr<STRING_VIEW>& configFilePath) : m_configFilePath(configFilePath)
	{}

	ConfigReader::~ConfigReader(){}

	const std::shared_ptr<LGF::IConfigReader>& ConfigReader::configReaderFactory(const std::shared_ptr<STRING_VIEW>& configFilePath)
	{
		std::shared_ptr<LGF::IConfigReader> configFactory = std::make_shared<LGF::ConfigReader>(configFilePath);
		return configFactory;
	}

	std::tuple<STRING_VIEW, STRING_VIEW> ConfigReader::getLoggerConfiguration() const
	{
		std::ifstream configFile(m_configFilePath->data());
		std::string configVar;
		std::string configVal;
		if (configFile.is_open())
		{
			std::string configLine;
			while(std::getline(configFile, configLine))
			{
				auto configDelimiter = configLine.find("=");
				configVar = configLine.substr(0, configDelimiter);
				configVal = configLine.substr(configDelimiter + 1);
			}
		}
		fmt::memory_buffer bufVar;
		fmt::format_to(bufVar, configVar);
		fmt::memory_buffer bufVal;
		fmt::format_to(bufVal, configVal);
		std::cout << "config name is: " << toStringView(bufVar) << " config val is: " << toStringView(bufVal) << std::endl;
		return { toStringView(bufVar), toStringView(bufVal) };
	}
}