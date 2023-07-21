#pragma once
#include <iostream>
#include "Complex.h"

/* Ƕ�� + ָ��*/
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

		// �ȷ���complex_entity.internalData�ڴ�ռ䣬ֵδ����
		internalData = (Complex*)new char[Size];
		//��ԭ����complex_entity.internalData�������ݵ��µ�internalDataȷ�����µ�ָ�� + ԭ��������
		memcpy(internalData, complex_entity.internalData, Size);

		//memcpy()
	}
};
