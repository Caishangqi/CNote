#pragma once
#include <iostream>
#include "Complex.h"

/* 嵌套 + 指针*/
class ComplexEntity
{
public:
	int x, y, z;
	Complex* internalData;

	ComplexEntity(int x, int y, int z, Complex* internalData): x(x), y(y), z(z), internalData(internalData)
	{
		std::cout << "Object ComplexEntity Created!" << std::endl;
	}

	ComplexEntity(const ComplexEntity& complex_entity)
	{
		x = complex_entity.x;
		y = complex_entity.y;
		z = complex_entity.z;

		int Size = sizeof(complex_entity);

		// 先分配complex_entity.internalData内存空间，值未设置
		internalData = (Complex*)new char[Size];
		//从原来的complex_entity.internalData拷贝数据到新的internalData确保了新的指针 + 原本的数据
		memcpy(internalData, complex_entity.internalData, Size);

		//memcpy()
	}
};
