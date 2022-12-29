#include <iostream>
#include <string>
/*
 * Mutable ������˼Ϊ˵�ѵģ����Ըı��
 * immutable Ϊ���ɸı��
 */
class Entity
{
public:
	const std::string& getName() const
	{
		m_DebugCount++; //�� mutable �Ϳ�����const�����и���
		return m_Name;
	}

private:
	std::string m_Name;
	mutable int m_DebugCount = 0;
};

int main(int argc, char* argv[])
{
	const Entity e; //�����Ҫ���� const��Entity���ҵ���getName����ķ���Ҳ����Ҫ��const���η�
	e.getName();

	int x = 8;
	/*mutable Ҳ��������lambdas*/
	auto f = [=]() mutable 
	{
		/*��ʾ����lambdas�ı������Ա��޸�*/
		x++;
		std::cout << x << std::endl;
		
	};

	f(); //����֮��x = 8 ��Ϊʹ�õĲ������ö��� = ���Ḵ��һ�� x ����lambdas���м���

	std::cin.get();
}
