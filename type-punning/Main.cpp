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
	 * - 首先获取e的地址，指针
	 * - 把指针转换成char类型的
	 * - 如果你要访问 y 那么应该是把指针移动至 4 = (char*)&e + 4
	 *		0   1   2   3   4   5   6   7
	 *		|05 |00 |00 |00 |08 |00 |00 |00
	 * - 把指针转换成 int 类型 (4 个 byte)
	 *		|08 |00 |00 |00
	 * - 解引 指针获取内部值
	 */
	std::cout << "y: " << y << std::endl;

	std::cin.get();
}
