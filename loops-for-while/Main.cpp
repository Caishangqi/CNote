#include <iostream>

int main()
{

	//for
	for (int i = 0; i < 5; i++)
	{
		if (i % 2 == 0)
			continue; //�����ż��ֱ�������ô�ѭ��
		std::cout << "Hi " << i << std::endl;
		//ִ���귽������е���
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
		//������Ķ���һ����ִ������һ��
		std::cout << "Hi with do while" << std::endl;
		k++;
	} while (k<5);


	std::cin.get();

}