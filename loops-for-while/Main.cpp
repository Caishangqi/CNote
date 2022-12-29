#include <iostream>

int main()
{

	//for
	for (int i = 0; i < 5; i++)
	{
		if (i % 2 == 0)
			continue; //如果是偶数直接跳过该次循环
		std::cout << "Hi " << i << std::endl;
		//执行完方法体进行递增
	} 

	//while
	int a = 0;
	while (a < 5)
	{
		std::cout << "Hi with while" << std::endl;
		a++;
	}

	// do while
	int k = 0;
	do
	{
		//这里面的东西一定会执行最少一次
		std::cout << "Hi with do while" << std::endl;
		k++;
	} while (k<5);


	std::cin.get();

}