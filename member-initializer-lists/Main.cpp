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
	 * �����ʹ�ó�Ա��ʼ�����ɷ�primitive data �ظ����µ������˷�
	 * ����˵��Entity class����������һ������Ϊ��Ա��������ô��ʹ��
	 * ������£����½���һ��Ĭ�ϵĳ�Ա���� Equip()ɾ����,�ڽ��й�����
	 * �ڲ��ĳ�ʼ��
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
	 * ��Ա��ʼ������Գ�Ա˳����и�ֵ���������
	 */
		: m_Name("Unknown"), m_Score(0), equip(8) //��Ա��ʼ��
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
