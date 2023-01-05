#include <iostream>
#include  "Complex.h"
#include "ComplexEntity.h"

int main(int argc, char* argv[])
{
	/* �򵥶���Ŀ��� ������û��Ƕ�׶������ָ��*/
	Complex c1 = {1, 2};
	Complex c2 = c1;

	/* ָ���Ƿ�һ��*/
	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;

	/* ����*/
	std::cout << "imag: " << c1.imag << " real: " << c1.real << std::endl;
	std::cout << "imag: " << c2.imag << " real: " << c2.real << std::endl;

	/* ���Ӷ���Ŀ��� ���������ָ�� ��Ƕ�׶���*/
	Complex* cc = new Complex(3, 4);
	std::cout << cc << std::endl;
	ComplexEntity ce = ComplexEntity(1, 1, 1, cc);
	ComplexEntity ce2 = ce;
	/* �˲��ַ��Ӧ�ò�һ��*/
	std::cout << ce2.internalData << std::endl;
	/* �˲鿽�������Ƿ�ɹ� ����� 3*/
	std::cout << ce2.internalData->real << std::endl;

	std::cin.get();
}
