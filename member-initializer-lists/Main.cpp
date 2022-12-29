#include <iostream>
#include <string>

class Equip

{
public:
	int value;

	Equip(int value)
	{
		std::cout << "Equipped with" << value << std::endl;
	}
};

class Entity
{
private:
	std::string m_Name;
	int m_Score;
	Equip equip;

public:
	/*
	 * 如果不使用成员初始表会造成非primitive data 重复导致的性能浪费
	 * 比如说若Entity class里面有另外一个类作为成员变量，那么不使用
	 * 的情况下，会新建立一个默认的成员变量 Equip()删除后,在进行构造器
	 * 内部的初始化
	 *
	Entity()
	{
		m_Name = "Example";
		m_Score = 1;
		equip = Equip(8);
	}
	*/

	Entity()
	/*
	 * 成员初始表必须以成员顺序进行赋值，逗号相隔
	 */
		: m_Name("Unknown"), m_Score(0), equip(8) //成员初始表
	{
	}

	Entity(const std::string& name)
		: m_Name(name), equip(8)
	{
	}

	const std::string& getName() const
	{
		return m_Name;
	}
};

int main(int argc, char* argv[])
{
	std::cin.get();
}
