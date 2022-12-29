#include <iostream>
#include <string>

/*
 * 引用，不会被复制，并且const表示我们承诺不会修改它
 */
void PrintString(const std::string& string)
{
	std::cout << string << std::endl;
}

/*
 * 这个是只读函数，传入的参数会被复制一份再打印不会影响原来
 * 传入的数据
 */
void PrintString(std::string string)
{
	
	std::cout << string << std::endl;
}

int main(int argc, char* argv[])
{
	/*一般来说。char类型是const因为字面意思 一段文字是不可修改的
	 * name是一个指针，指向一个字符串常量 "Caizii"
	 */
	const char* name = "Caizii"; //43 61 69 7a 69 69 00
	//末尾的 00 代表字符串结束

	/* 你也可以不使用指针手动分配内存，6个字符必须有8个元素
	 * 因为最后一个元素需要填充 0 null termination character
	 */
	char name2[7] = { 'C','a','i','z','i','i', 0 }; //这里如果不设置末尾结束,null的话编译器会自动填充 cc
	std::cout << name2 << std:: endl;
	//如果你不用new 就不需要delete

	/*使用C++内置string库*/
	std::string cname = "Caizii";

	/*多行*/
	std::string mline = "Caizii\n"
		"Daizii\n"
		"Eaizii\n"
		"Faizii";

	std::cout << mline << std::endl;


	std::cin.get();
}
