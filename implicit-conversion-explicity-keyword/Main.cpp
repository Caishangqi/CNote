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

	/*���˹ؼ��� explicit �Ժ���������ص��ù����� ������C++��������ת��*/
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
	/*��������*/
	Entity a = Entity("Caizii");
	/*���߿�����ô����*/
	Entity b = "Daizii";
	/*��Ϊ������ֱ��int�Ĺ����� C++�������������ת��������*/
	Entity c = 21; //21 ���Զ�����Entity���еĹ����� (int) �����ɶ���
	/*��˿���ֱ����ô����*/
	Function(22);
	Function(std::string("Abba")); //ת��ֻ����һ�Σ�"Abba"��char���顣������ת���� std::string

	std::cin.get();
}
