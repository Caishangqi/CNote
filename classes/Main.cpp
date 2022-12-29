#include <iostream>

#define LOG(x) std::cout << x << std::endl

class Player
{
public:
	int x, y;
	int speed;

	void move(int xa, int ya)
	{
		x = xa * speed;
		y = ya * speed;
	}
};

int main()
{
	Player player; //สตภýปฏ
	player.move(1, -1);

	std::cin.get();
}
