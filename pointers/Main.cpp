#include <iostream>

#define LOG(x) std::cout << x << std::endl

int main()
{

	//void 指针不关心这个数据类型是什么;
	void* ptr_useless = 0; //给予这个指针内存为0的地址，或者 #define NUll 0, 或者 nullptr
	/*
		0 不是一个有效的地址，我们无法读取或写入地址为0的内存
	*/

	int var = 8;
	int* ptr = &var; //var 的内存地址是多少

	//derefrecing 解引用
	*ptr = 10; //void 指针会报错因为计算机不知道要用几个字节去写进去

	LOG(var);

	//在计算机heap上指定特定大小的内存创建变量

		//1. 让电脑分配一块内存 并且是指定大小
		//char 是一字节的 8长度的char对应8字节 00 00 00 00 00 00 00 00
		//分配8个字节的内存并返回一个指向这块内存开始地址的指针
		char* buffer = new char[8];  

		//1.5 双指针读取buffer这个指针的内存地址
		char** ptrd = &buffer; //这这指针是 8 字节因为运行在64位系统上，64为系统内存地址是8字节
		//因为电脑的little endian 其实是逆序的 搜索到的 &buffer地址应该是倒叙
		 
		//2. 用指定的数据填充一块内存;
		memset(buffer, 0, 8);

		//3. 因为我们用了new这个关键词，所以数据是分配在heap上
		//我们在处理完毕后应该删除这个数据
		//delete[] buffer;

	std::cin.get();
}