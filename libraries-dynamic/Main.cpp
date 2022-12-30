#include <iostream>
#include "GLFW/glfw3.h"

/* dynamic libaries 首先必须把 .dll放在 exe 同目录下
 * 其次你需要在 连接器 > 输入 > 附加依赖项目 设置为 glfw3dll.lib
 * 这个文件匹配了header file和dll 方法的匹配，防止方法错位，内存错位等等
 */

/*
 * If you use lib + dll，you don't need __declspec(dllimport)
 * because all the functions or variables you wan't to import
 * have defined in lib as pointer;but if you use LoadLibary
 * API to import dll, with   __declspec(dllimport) you can
 * tell the compiler which function or variable you want to
 * import, it will reduce the import time
 */

int main(int argc, char* argv[])
{
	int a = glfwInit();
	std::cout << a << std::endl; //成功捏 “1”
	std::cin.get();

}
