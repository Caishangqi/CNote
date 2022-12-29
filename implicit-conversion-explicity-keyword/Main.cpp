#include <iostream>
#include <string>

class Entity
{
public:
	Entity(const std::string& name) : m_Name(name), m_Age(-1)
	{
	}

	Entity(int age) : m_Name("Unknown"), m_Age(age)
	{
	}

	/*加了关键字 explicit 以后必须完整地调用构造器 不能让C++进行隐性转换*/
	explicit Entity(const std::string& name, int age, int score): m_Name(name),m_Age(age),m_score(score) {}

private:
	std::string m_Name;
	int m_Age;
	int m_score;
};

void Function(const Entity& entity)
{
	//Printing
}

int main(int argc, char* argv[])
{
	/*创建对象*/
	Entity a = Entity("Caizii");
	/*或者可以这么创建*/
	Entity b = "Daizii";
	/*因为我们有直接int的构造器 C++会帮助我们隐形转换调用它*/
	Entity c = 21; //21 会自动调用Entity期中的构造器 (int) 并生成对象
	/*因此可以直接这么调用*/
	Function(22);
	Function(std::string("Abba")); //转换只能有一次，"Abba"是char数组。必须先转换成 std::string

	std::cin.get();
}
