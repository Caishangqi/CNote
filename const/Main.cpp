#include <iostream>
#include <string>

class Entity
{
private:
	int m_X, m_Y;
	mutable int var;
public:
	/*����ζ��������������޸ĳ�Ա����*/
	int getX() const
	{
		// read - only
		//m_X = 2;

		/*�������Ҫ��const�������޸����ݣ�����Ҫ����ؼ��� mutable*/
		var = 5;
		return m_X;
	}

	void setX(int x)
	{
		m_X = x;
	}

};

int main(int argc, char* argv[])
{

	const int MAX_AGE = 90;

	int* a = new int; //create int on heap
	*a = 2;
	a = (int*)&MAX_AGE; //reassign the pointer
	std::cout << *a<< std::endl;

	/*ֻ�ܸ�ָ���ܸ����ݵ�const�÷�*/
	const int* b = new int;
	//*b = 3 you can not change the content of the const pointer
	b = (int*)&MAX_AGE; //but you can change the direction

	/*���Ը����ݵ����ܸ�ָ��� const�÷�*/
	int* const c = new int;
	*c = 15; //���Ը�ָ��ָ��ı�������
	//c = (int*)&MAX_AGE; �����޸�ָ��

	/*�Ȳ����޸������ֲ�������ָ��*/
	const int* const d = new int;


	std::cin.get();

}
