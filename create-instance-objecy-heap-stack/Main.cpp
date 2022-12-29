#include <iostream>
#include <string>

using String = std::string;

class Entity
{
public:
	Entity(): m_Name("Unknown")
	{
	}

	Entity(const String& name) : m_Name(name)
	{
	}

	const String& getName() const { return m_Name; }

private:
	String m_Name;
};

void Function() //���øú���ʱstack����������������������������
{
	int a = 2;
	Entity entity = Entity("?");
} //һ��������ײ������entity���ڴ��б��ݻ�

int main(int argc, char* argv[])
{
	/*creating on the stack*/
	Entity entity; //use the default constructor
	Entity entity2 = Entity("Caizii");
	/*if you can create object like this, do like this*/
	std::cout << entity2.getName() << std::endl;

	Entity* e;
	{
		Entity entity3 = Entity("OP");
		e = &entity3;
		std::cout << entity3.getName() << std::endl;
	}
	/*���⼴ʹָ�� e ָ����ͬ�ĵ�ַ���ǵ�ַ�ڲ���Entityֵ�ǿյ�
	 * {m_name = ""} ���󱻴ݻ�
	 */


	/*creating on the heap*/
	Entity* e1;
	{
		//������Entity��ָ��
		//ʹ��new �ؼ��ʾ���heap�Ϸ����ڴ�
		//����һ��Entity��ָ������������entity��heap���ĸ���ַ��
		Entity* entityHeap = new Entity("ABBA");
		e1 = entityHeap; //ָ���������õ�ָ��
		std::cout << (*entityHeap).getName() << std::endl; //������ȡʵ�ʱ���
		std::cout << entityHeap->getName() << std::endl; //����ʹ�ü�ͷ
		/*���������heap����Ŷ����ļ���ԭ��
		 * 1. heap����������Խ�����������ʧ
		 * 2. ������ֶ�ɾ��heap�ϵĶ���
		 */
		
	}
	delete e1; //�������ͷ�Heap�ϵĶ���

	std::cin.get();
}
