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

class Player : public Entity //继承
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
	 * Entity 的大小是8字节因为有2个float数据，一个是4字节
	 */
	std::cout << sizeof(Entity) << std::endl;
	std::cout << sizeof(Player) << std::endl; //4 + 4 + 8 (指针在64位系统大小为8字节 char*)
	/*
	 * 玩家不仅仅是玩家他也是实体，这意味我们可以使用玩家
	 * 在我们想要使用实体的地方 (多态)，玩家类是实体类的超
	 * 集，永远包含实体类的内容。
	 */
	Entity e;
	Player p;
	p.showName();
	p.move(1.0f,2.0f);

	

	std::cin.get();
}
