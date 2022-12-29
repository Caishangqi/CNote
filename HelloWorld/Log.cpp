#include <iostream> //预处理指令 preprocessor statement (发生在真正编译之前)

void Log(const char* message)
{
	std::cout << message << std::endl;
	// "<<" 看作函数
	// std::cout.print("hello world").print(std::endl);
}