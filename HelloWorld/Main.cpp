#include <iostream> // 方括号只用于编译器的include路径，引号用于所有
//include 就是找到一个文件，这里找一个叫 iostream的文件，这个文件会被拷贝到这个头文件中
#include "Log.h"

int main() { //main is entry point
	
	int a = 8; //00 00 00 00 00 00 00 00
	a++;
	const char* string = "Hello";

	Log("Hello World");
	std::cin.get();
}	//不需要在主程序方法返回任何类型的值 