#include <iostream>
#include <string>

class Entity
{ //Ĭ�Ͽɼ�����˽�е�
protected: //����Ҳ���Է��ʴ�����
	int X, Y;
	void echo() {}
private: //˽�е�,ֻ�б�����Է���
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
