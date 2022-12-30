#include <iostream>
#include "GLFW/glfw3.h"
/* 通常情况下一个外部依赖分为两个部分
 * - include: 存放头文件 设置中C++ 常规，额外依赖地址: $(ProjectDir)Dependencies\GLFW\include
 * - lib-vc20xx: 存放方法体等 设置中C++ 链接器，额外依赖地址: $(ProjectDir)Dependencies\GLFW\lib-vc2022 (对于你使用的 .lib的目录)
 * 另外你还需要在 设置中C++ 链接器 输入 > 设置你要使用哪个 .lib 这里使用 glfw3.lib
 */

/* Chernol 建议 : 如果依赖在项目里面 vs 用 "" 反之用 <>*/

/* 第二步我们需要连接 header file里面的函数申明到真正的函数体
 * 这样linker才会正常把这两个串起来否则会报错 reference error
 */
int main(int argc, char* argv[])
{
	int a = glfwInit();
	std::cout << a << std::endl; //成功捏 “1”
	std::cin.get();

}
