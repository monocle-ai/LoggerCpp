#include "configReader_lgf.h"
#include <string>
#include <fstream>
#include <algorithm>
#include "logifyHelper_lgf.h"
#include "interface/iConfigReader_lgf.h"

namespace Lgfypp
{
Lgfypp::ConfigReader::ConfigReader(
const std::string& configFilePath)
: m_configFilePath(configFilePath){}

/*Lgfypp::IConfigReaderSharedPtr& ConfigReader::configReaderFactory(
	const std::string& configFilePath)
{
	if (configFilePath.empty())
	{
		return Lgfypp::IConfigReaderSharedPtr(nullptr);
	}
	return Lgfypp::IConfigReaderSharedPtr(new ConfigReader(configFilePath));
}*/

std::unordered_map<std::string, std::string> Lgfypp::ConfigReader::getLoggerConfiguration() const
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
				auto key = configLine.substr(0, configDelimiter);
				auto val = configLine.substr(configDelimiter + 1);
				std::transform(key.begin(), key.end(), key.begin(), ::toupper);
				std::transform(val.begin(), val.end(), val.begin(), ::toupper);
				globalConfigs.emplace(key, val);
			}
		}
	}
	static auto lgfHelper = Lgfypp::LgfHelper::getHelperInstance();
	return lgfHelper.discardInvalidConfig(globalConfigs);
}

}