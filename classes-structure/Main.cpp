#include <iostream>

/**
 * \brief Log
 */
class Log
{
public:
	const int LogLevelWarning = 1;
	const int LogLevelError = 0;
	const int LogLevelInfo = 2;

private:
	int m_LogLevel = LogLevelInfo;

public:
	void setLevel(int level)
	{
		m_LogLevel = level;
	}

	void warn(const char* message)
	{
		if (m_LogLevel >= LogLevelWarning)
			std::cout << "(!)" << message << std::endl;
	}

	void info(const char* message)
	{
		if (m_LogLevel >= LogLevelInfo)
			std::cout << "(+)" << message << std::endl;
	}

	void error(const char* message)
	{
		if (m_LogLevel >= LogLevelError)
			std::cout << "(x) " << message << std::endl;
	}
};

int main()
{
	Log log;
	log.setLevel(log.LogLevelWarning);
	log.warn("Hello");
	std::cin.get();
}
