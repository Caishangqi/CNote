#include <iostream>
#include <string>

struct Vector3
{
	float x, y, z;

	Vector3(): x(10), y(11), z(12)
	{
	}
};

int main(int argc, char* argv[])
{
	{
		/* allocate memory on stack*/
		int value = 5;

		/* �ڻ���У���stack�Ϸ����ڴ�ܿ�
		 * mov DWORD PTR _value$[ebp], 5
		 * �� 5 ����Ĵ���
		 */

		int array[5];
		array[0] = 1;
		array[1] = 2;
		array[2] = 3;
		array[3] = 4;
		array[4] = 5;
	}
	/* �������ܿ��� value �� array�ĵ�ַ���һС�� ����debugģʽ���ṩ�İ�ȫ��*/

	/* 12 byte ������Ҳ���Կ���������ڴ��ַ�� array��*/
	Vector3 vector;

	/* ��˵����������stack�Ϸ����ڴ�ʱ�� stack��ָ���ƶ�ָ���������͵�byte������
	 * ����ҷ���һ��int���͵ı�����stackָ����ƶ� 4 byte��stack�����������ģ�Ҳ��
	 * Ϊʲô int value�ĵ�ֵַ���߶� vector ���͡�
	 *
	 * stack�����ڴ��Ǽ���ģ�����ֻ��Ҫ�ƶ�ָ�뷵��ָ���Ӧ�ĵ�ַ����: ����������һ��
	 * int����ֻ��Ҫ�ƶ�ָ��4��byte���ض�Ӧ�ĵ�ַ���� (one cpu instruction)
	 */

	/* allocate memory on heap*/
	int* hvalue = new int();
	*hvalue = 5;

	int* harray = new int[5];
	harray[0] = 1;
	harray[1] = 2;
	harray[2] = 3;
	harray[3] = 4;
	harray[4] = 5;

	/* ��heap�ϵĵ�ַ�����Զ*/

	Vector3* hvec = new Vector3();

	/* new �Ĺ��� heap ��ԭ��:
	 * - ���÷��� malloc()
	 * - ��ĳ��򻹻�ʹ��һ�����ڴ���������Щ��ַ�ǿյ� FreeList
	 * - ������� malloc()���������鿴FreeList��malloc()��
	 * �ҵ�FreeList���������������Ǹ���С���ڴ��ַ���ҷ���ָ��
	 * �Ǹ���ַ��ָ��
	 */
	delete hvalue;
	delete[] harray;
	delete hvec;

	std::cin.get();
}
