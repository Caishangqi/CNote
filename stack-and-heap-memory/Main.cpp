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

		/* 在汇编中，在stack上分配内存很快
		 * mov DWORD PTR _value$[ebp], 5
		 * 把 5 丢入寄存器
		 */

		int array[5];
		array[0] = 1;
		array[1] = 2;
		array[2] = 3;
		array[3] = 4;
		array[4] = 5;
	}
	/* 在这里能看到 value 和 array的地址相隔一小段 这是debug模式下提供的安全符*/

	/* 12 byte 在这里也可以看到上面的内存地址是 array的*/
	Vector3 vector;

	/* 这说明当我们在stack上分配内存时， stack的指针移动指定数据类型的byte，例如
	 * 如果我分配一个int类型的变量，stack指针就移动 4 byte。stack是往后增长的，也就
	 * 为什么 int value的地址值更高而 vector 更低。
	 *
	 * stack分配内存是极快的，我们只需要移动指针返回指针对应的地址即可: 如果我想分配一个
	 * int，我只需要移动指针4个byte返回对应的地址即可 (one cpu instruction)
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

	/* 在heap上的地址相隔很远*/

	Vector3* hvec = new Vector3();

	/* new 的过程 heap 的原理:
	 * - 调用方法 malloc()
	 * - 你的程序还会使用一部分内存来储存哪些地址是空的 FreeList
	 * - 当你调用 malloc()这个方法会查看FreeList，malloc()会
	 * 找到FreeList连续并且至少在那个大小的内存地址并且返回指向
	 * 那个地址的指针
	 */
	delete hvalue;
	delete[] harray;
	delete hvec;

	std::cin.get();
}
