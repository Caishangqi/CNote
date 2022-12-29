#pragma once
#include <iostream>

class Log
{
public:	enum Level
	{
		Error = 0,
		Warning,
		Info
	};

private:
	Level logLevel = Info;

public:
	void setLevel(Level level)
	{
		logLevel = level;
	}

	void warn(const char* message)
	{
		if (this->logLevel >= Warning)
			std::cout << "[!] " << message << std::endl;
	}

	void error(const char* message)
	{
		if (this->logLevel >= Error)
			std::cout << "[x] " << message << std::endl;
	}

	void info(const char* message)
	{
		if (this->logLevel >= Info)
			std::cout << "[+] " << message << std::endl;
	}
};
