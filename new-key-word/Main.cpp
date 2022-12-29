#include <iostream>
#include <string>

using String = std::string;
/*
 * new �ؼ��ʵ���ҪĿ�ľ�����heap�Ϸ����ڴ� new + DataType
 * - ��������������ͣ��������Ҫ������ڴ��С�ռ䣬int Ϊ 4 byte
 * - ����ô�С�󣬻���C ��׼��ȥ��ϵͳ��Ҫ 4 byte �ռ�
 * - ��������ҪѰ�����ڴ��� ���� ��4 byte�Ŀɷ���ռ�
 * - 4 byte��һ���Ƚ�С�Ŀռ������������ҷ��䲻��Ҫ�ܶ�ʱ��
 * - ����ϵͳ������Ҫȥ��ʱ��ȥ�ҵ��Ǹ���ַ��������4�� byte�յ��ڴ�
 * - һ�����ҵ��ĸ��ռ䣬���ͻ᷵��һ��ָ����ڴ��ָ��
 * - ��������Ϳ����������ָ��(��ַ)ȥ������
 */

class Entity
{
public:
	Entity() : m_Name("Unknown")
	{
	}

	Entity(const String& name) : m_Name(name)
	{
	}

	const String& getName() const { return m_Name; }

private:
	String m_Name;
};


int main(int argc, char* argv[])
{
	//new return a pointer
	int* b = new int; // 4 byte
	int* c = new int[50]; // 200 byte

	//�������������ڴ棬new �������˹�����
	Entity* e = new Entity(); //���з����С����ָ�벢�ҵ����˹�����
	//������� malloc() ��ͬ��
	Entity* e2 = (Entity*)malloc(sizeof(Entity)); //���д������ָ����С���ڴ淵�ض�Ӧָ��

	/*�����ȷ��ʹ��delete*/
	free(e);
	delete(e); //deleteҲ���ù�����

	/*���������ڴ�ʱʹ���� [] ��ôɾ��ʱҲ��Ҫ���� []*/
	delete[] c;

	std::cin.get();
}
