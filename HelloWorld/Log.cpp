#include <iostream> //Ԥ����ָ�� preprocessor statement (��������������֮ǰ)

void Log(const char* message)
{
	std::cout << message << std::endl;
	// "<<" ��������
	// std::cout.print("hello world").print(std::endl);
}