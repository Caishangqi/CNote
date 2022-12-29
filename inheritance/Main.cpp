#include <iostream>

class Entity
{

public:
	float x, y;

	void move(float xa, float ya)
	{
		x = x + xa;
		y = y + ya;
	}

};

class Player : public Entity //�̳�
{
public:
	const char* Name;

	void showName()
	{
		std::cout << Name << std::endl;
	}
};

int main(int argc, char* argv[])
{
	/*
	 * Entity �Ĵ�С��8�ֽ���Ϊ��2��float���ݣ�һ����4�ֽ�
	 */
	std::cout << sizeof(Entity) << std::endl;
	std::cout << sizeof(Player) << std::endl; //4 + 4 + 8 (ָ����64λϵͳ��СΪ8�ֽ� char*)
	/*
	 * ��Ҳ������������Ҳ��ʵ�壬����ζ���ǿ���ʹ�����
	 * ��������Ҫʹ��ʵ��ĵط� (��̬)���������ʵ����ĳ�
	 * ������Զ����ʵ��������ݡ�
	 */
	Entity e;
	Player p;
	p.showName();
	p.move(1.0f,2.0f);

	

	std::cin.get();
}
