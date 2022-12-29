#include <iostream>
#include <string>

//ȱ�١� ��ָ�� ���֪ʶ��
class Printable
{
public:
	virtual std::string getClassName() = 0;

	virtual ~Printable()
	{
		std::cout << "Printable x" << std::endl;
	}
};

class Entity : public Printable //base class
{
public:
	/*û�з����嵫�ǻ����麯���� = 0 ������Ϊһ�����麯��
	 * ����ζ���������ʵ�����Ǹ��������������ʵ���������
	 */
	//virtual std::string getName() = 0;

	virtual std::string getName()
	{
		return "Entity";
	};

	std::string getClassName() override //ÿһ���̳� Printable �ӿڵ������ʵ���ڲ��Ľӿڷ�����ʵ����
	{
		return "Entity";
	}


};

class Player : public Entity
{
private:
	std::string p_Name;

public:
	Player(const std::string& name)
		: p_Name(name)
	{
	}

	/*�ڶ��ַ�����ʹ�ø�д�ؼ��� override*/
	std::string getName() override { return p_Name; }

	std::string getClassName() override //ÿһ���̳� Printable �ӿڵ������ʵ���ڲ��Ľӿڷ�����ʵ����
	{
		return "Player";
	}

	virtual ~Player()
	{
		std::cout << "Player x" << std::endl;
	}
};


void printClassName(Printable* obj)
{
	/*
	 * ������Ҫһ�����ͣ������ͱ�֤����getClassName�������
	 * ������Ҫ�����������ṩgetClassName�������Ҳ���ǽӿ�
	 */
	std::cout << obj->getClassName() << std::endl;
}

int main(int argc, char* argv[])
{
	Entity* p = new Player("Caizii");
	Entity* e = new Entity();
	printClassName(p);
	printClassName(e);
	delete p;
	std::cin.get();
}
