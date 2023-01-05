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

	/*�����д�˸��ƹ��캯������Ĭ�ϸ��ƹ��캯���Ͳ�������*/
	Complex(const Complex& complex)
	{
		/* ��һ��ִֻ�и��Ʋ���*/
		real = complex.real + 1;
		imag = complex.imag + 1;
		std::cout << "Copy Construct!" << std::endl;
	}
};
