#include <iostream>
#include  "Complex.h"
#include "ComplexEntity.h"

int main(int argc, char* argv[])
{
	/* 简单对象的拷贝 对象里没有嵌套对象或者指针*/
	Complex c1 = {1, 2};
	Complex c2 = c1;

	/* 指针是否一样*/
	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;

	/* 内容*/
	std::cout << "imag: " << c1.imag << " real: " << c1.real << std::endl;
	std::cout << "imag: " << c2.imag << " real: " << c2.real << std::endl;

	/* 复杂对象的拷贝 对象里包含指针 和嵌套对象*/
	Complex* cc = new Complex(3, 4);
	std::cout << cc << std::endl;
	ComplexEntity ce = ComplexEntity(1, 1, 1, cc);
	ComplexEntity ce2 = ce;
	/* 核查地址，应该不一样*/
	std::cout << ce2.internalData << std::endl;
	/* 核查拷贝数据是否成功 因该是 3*/
	std::cout << ce2.internalData->real << std::endl;

	std::cin.get();
}
