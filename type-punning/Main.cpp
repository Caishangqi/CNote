#include <iostream>

/* whole principle of punning is treat a memory as another type of
 * memory
 */

struct Entity
{
	int x, y;
};

int main(int argc, char* argv[])
{
	int a = 50;
	/* want to treat int a as double
	 * we convert the int pointer to
	 * a double pointer, then we de
	 * reference that (punning)
	 */
	double value = *(double*)&a;
	std::cout << value << std::endl;

	/* it can be treat as a int array with x and y*/
	Entity e = {5, 8};

	int* position = (int*)&e;

	std::cout << position[0] << ", " << position[1] << std::endl;

	/* get some crazy things*/
	int y = *(int*)((char*)&e + 4);
	/*
	 * - ���Ȼ�ȡe�ĵ�ַ��ָ��
	 * - ��ָ��ת����char���͵�
	 * - �����Ҫ���� y ��ôӦ���ǰ�ָ���ƶ��� 4 = (char*)&e + 4
	 *		0   1   2   3   4   5   6   7
	 *		|05 |00 |00 |00 |08 |00 |00 |00
	 * - ��ָ��ת���� int ���� (4 �� byte)
	 *		|08 |00 |00 |00
	 * - ���� ָ���ȡ�ڲ�ֵ
	 */
	std::cout << "y: " << y << std::endl;

	std::cin.get();
}
