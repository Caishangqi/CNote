#include <iostream>
#include <string>

class Entity
{ //默认可见度是私有的
protected: //子类也可以访问此属性
	int X, Y;
	void echo() {}
private: //私有的,只有本类可以访问
	int Z;
public:
	Entity()
	{
		X = 0;
	}
};

class Player:Entity
{
public:
	
};

int main(int argc, char* argv[])
{
	Entity entity;
	std::cin.get();
}
