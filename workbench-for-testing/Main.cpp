#include "Log.h"

//
class Entity
{
public:
	int x, y;

	Entity(int x, int y): x(x), y(y)
	{
	}

	~Entity()
	{
		std::cout << "Entity x" << std::endl;
	}
};

class Player : Entity
{
public:

	~Player()
	{
		std::cout << "Player x" << std::endl;
	}
};

int main(int argc, char* argv[])
{
	Log log;
	log.setLevel(Log::Error);
	log.warn("Hello");
	log.error("Hello");
	log.info("Hello");

	Player* e = new Player();
	delete e;

	std::cin.get();
}
