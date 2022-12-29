#include <iostream>

enum Example :  int
{
	//不设置值的话默认从0开始递增
	A = 0,
	B = 1,
	C = 2
};

int a = 0;
int b = 0;
int c = 2;


int main()
{
	Example value = B;

	if (value == 1)
	{
		//TODO
	}

}
