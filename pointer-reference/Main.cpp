#include <iostream>

#define LOG(x) std::cout << x << std::endl
//引用就是指针，只不过写法不一样

//引用变量必须引用一个已经存在的变量，它本身并不是一个新变量


void Increment(int* value) {
	//如果不解引用 "*"，那么增加的就是地址而不是地址对应实际的值
	*value = *value + 1;

}

void Increment(int& value) {
	//也可以这么写
	// int& value = value
	value = value + 1; //对引用变量执行操作就是对实际变量进行操作

}

int main()
{
	int a = 5;
	//在引用中，&是变量的一部分
	int& ref = a; //创建了一个别名 ref 的变量，只在源代码中存在，实际只有a
	ref = 2;



	//试图使用引用传入函数中
	int b = 5;
	
	/*
	* 这里就等于 int& value = b; 创建了一个v对b的引用叫做value
	* 然后value进行了自增操作，由于引用指向地址值一样实际就是把b进行了自增
	*/
	Increment(b); //把指针传进去，传递变量的内存地址

	LOG(a);
	LOG(b);
	std::cin.get();
}
