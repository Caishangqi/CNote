#include <iostream>
#include <string>

class Entity
{
public:
	Entity()
	{
		std::cout << "Created Entity!" << std::endl;
	}

	~Entity()
	{
		std::cout << "Destroyed Entity!" << std::endl;
	}
};

/*����ʾ��*/
int* CreateArrayFail()
{
	int array[50]; //����50 x 4 �ֽڲ��ҷ��ص�ǰ��ַָ��
	/* ����ȷʵ������ָ������ڴ��ָ��
	 * �������Ǵ�����stack��������ݣ�
	 * �����return�������Ӧ��ַ���ڴ�
	 * �ᱻ�ͷ�
	 */
	return array;
}

/*��ȷʾ��*/
int* CreatArraySucc()
{
	int* array = new int[50]; //����200�ֽ���heap�ϲ��ҷ��ص�ַָ��
	return array;
}

/*�ִ��scoped pointer (Unique Pointer)*/
class ScopedPtr
{
public:
	ScopedPtr(Entity* ptr) : m_Ptr(ptr)
	{
	}

	~ScopedPtr()
	{
		delete m_Ptr;
	}

private:
	Entity* m_Ptr;
};

int main(int argc, char* argv[])
{	// begin of scope
	{
		

		Entity e;
	} // end of scope

	{
		Entity* eh = new Entity();
		/*�����Entity�Զ����٣�ʹ�� unique pointer - scoped pointer*/
		ScopedPtr sp = new Entity(); //���ﻹ������ת������ P39
		/*ScopedPtr �Ǵ����� stack�ϵģ�����ζ�ŵ��뿪scope��Χ��sp���Զ�ɾ��
		 * ���ôݻٹ��������ڴݻٹ�������ִ���� delete m_Ptr Ҳ���� Entity��ָ��
		 */
	}

	std::cin.get();
}
