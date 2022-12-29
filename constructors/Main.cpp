#include <iostream>

class Entity
{
public:
	float x, y; //ʵ���������ڴ�ʱ���û��ָ��ֵ�����ڴ����������ֵ

	//��������C++��������Զ������ڴ��ʼ��
	Entity()
	{
		x = 0.0f;
		y = 0.0f;
		std::cout << "Created this object" << std::endl;
	}

	//���ι����� (����)
	Entity(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	~Entity() //Destructor
	{
		std::cout << "Destroyed this object" << std::endl;
	}

	void Init()
	{
		x = 0.0f;
		y = 0.0f;
	}

	void echo()
	{
		std::cout << x << ", " << y << std::endl;
	}
};

class Log
{
public:
	static void write()
	{
	}

	Log() = delete; //ɾ��Ĭ�Ϲ�����,���߱�ʾ�������������

private:
	// Log()
	// {
	// }
	// //���԰ѹ���������private�ñ����޷�ʵ������  // NOLINT(clang-diagnostic-invalid-utf8)
};

void Fuction()
{
	Entity e; //�����ڶ�ջ�ϴ����ģ�������Χ�Զ��ݻ�
	e.echo();
} //�������Զ��ݻ� ����ɾ������

int main(int argc, char* argv[])
{
	//Entity e(10.0f, 5.0f);
	//Entity e1;
	//e.echo();
	//Log::write();
	Fuction(); 
	std::cin.get();
}
