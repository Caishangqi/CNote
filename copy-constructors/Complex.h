#pragma once
#include <iostream>

class Complex
{
public:
	double real, imag;

	Complex(double r, double i): real(r), imag(i)
	{
		std::cout << "Object Created!" << std::endl;
	}

	/*如果编写了复制构造函数，则默认复制构造函数就不存在了*/
	Complex(const Complex& complex)
	{
		/* 不一定只执行复制操作*/
		real = complex.real + 1;
		imag = complex.imag + 1;
		std::cout << "Copy Construct!" << std::endl;
	}
};
