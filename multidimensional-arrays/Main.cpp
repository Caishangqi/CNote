#include <iostream>

int main(int argc, char* argv[])
{
	/* heap allocate a array*/
	/* we allocate memory and 50 pointers*/
	int** a2d = new int*[50];
	for (int i = 0; i < 50; i++)
		/* initialize actual int array*/
		a2d[i] = new int[50];
	/* it would cause memory fragment allocate int is pure random
	 * so it would slow to iterate through 2d array than in 1d array
	 */


	/* the first element, the first colunm uis pointer, the
	 * second column is actual int
	 */
	a2d[0][0] = 0;
	a2d[0][1] = 0;
	a2d[0][2] = 0;

	/* how to delete*/
	for (int i = 0; i < 50; i++)
		/* delete actual array*/
		delete[] a2d[i];

	/* finally delete the array that storage pointers*/
	delete[] a2d;

	/* using 1d array to act like a 2d array*/
	int* array = new int[5 * 5];
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			array[x + y * 5] = 2; //聪明逼

			/* y乘矩阵大小在加上x可以直接得到1d的index比如第二行的第一个元素
			 * y = 1, x = 0, array[5] 就是1d的第六个元素，折叠成2d就是第
			 * 二行第一个
			 */
		}
	}

	std::cin.get();
}
