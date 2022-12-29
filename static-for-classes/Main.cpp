#include <iostream>

struct Entity
{
	static int x, y;

	void Print()
	{
		std::cout << x << ", " << y << std::endl;
	}

};

/**
 * 如果你使用实例对象访问静态方法就类比于以下代码
 * 不会传入Entity e作为形参，方法体内部的 x , y不知道是谁的
 */

// static void Print()
// {
// 	std::cout << x << ", " << y << std::endl;
// }

int Entity::x;
int Entity::y;


int main() {

	Entity e;
	e.x = 2;
	e.y = 3;

	Entity e1;
	e1.x = 5;
	e1.y = 8;

	//可以写成 - 直接设置类里面的static变量会改变所有 Entity类的x,y值
	Entity::x = 5;
	Entity::y = 8;

	e.Print();
	e1.Print();

	
	std::cin.get();

}