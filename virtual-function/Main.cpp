#include <iostream>
#include <string>

//缺少× 类指针 相关知识点
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
	/*没有方法体但是还是虚函数， = 0 让他成为一个纯虚函数
	 * 这意味着如果你想实例化那个类必须在子类中实现这个方法
	 */
	//virtual std::string getName() = 0;

	virtual std::string getName()
	{
		return "Entity";
	};

	std::string getClassName() override //每一个继承 Printable 接口的类必须实现内部的接口否则不能实例化
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

	/*第二种方法是使用复写关键词 override*/
	std::string getName() override { return p_Name; }

	std::string getClassName() override //每一个继承 Printable 接口的类必须实现内部的接口否则不能实例化
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
	 * 我们需要一种类型，该类型保证类有getClassName这个函数
	 * 我们需要有这种类能提供getClassName这个函数也就是接口
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
