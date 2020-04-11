/*
MIT License

Copyright(c) 2020 Dipanjan Das

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright noticeand this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

If you contribute to this file please add your name to the contributors list below.

Author		 : Dipanjan Das
Contributors :
*/
#pragma once
#ifndef LGF_CONFIGREADER_H
#define LGF_CONFIGREADER_H

#include<memory.h>
#include "core_lgf.h"
#include "levelUtils_lgf.h"
#include <string>
#include <fstream>
#include <algorithm>
#include "logifyHelper_lgf.h"
#include "interface/iConfigReader_lgf.h"

LGF_BEGIN

typedef std::shared_ptr<Lgfypp::IConfigReader> IConfigReaderSharedPtr;

class ConfigReader sealed : public IConfigReader
{
private:
	const std::string m_configFilePath;
	ConfigReader(const ConfigReader&) = delete;
	ConfigReader& operator=(const ConfigReader&) = delete;
public:
	explicit ConfigReader(const std::string& configFilePath) : m_configFilePath(configFilePath) //TODO: Move to private when Factroy is working.
	{}
	//static Lgfypp::IConfigReaderSharedPtr& configReaderFactory(const std::string& configFilePath); //TODO: //DO NOT DELETE 
	virtual std::unordered_map<std::string, std::string> getLoggerConfiguration() const override
	{
		static auto lgfHelper = Lgfypp::LgfHelper::getHelperInstance();
		if (!lgfHelper.doesFileExist(m_configFilePath))
		{
			std::ostringstream error_msg;
			error_msg << "The configuration file " << m_configFilePath << " does not exist. Please create a config file." << std::endl;
			throw std::runtime_error(error_msg.str());
		}
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
					globalConfigs.emplace(lgfHelper.toUpperCase(lgfHelper.stringTrim(key)),
						lgfHelper.toUpperCase(lgfHelper.stringTrim(val)));
				}
			}
		}
		return lgfHelper.discardInvalidConfig(globalConfigs);
	}
};

LGF_END

#endif