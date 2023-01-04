/* dynamic casting more like a function, it evaluate in runtime
 * - usually used in inheritance hierarchy
 *
 * For example: if we have an entity instance that is actually an
 * enemy, but we try to cast it in to a player using dynamic cast,
 * that case would fail and return a null pointer (0)
 */

#include <iostream>
#include <string>

class Entity
{
public:
	virtual void PrintName()
	{
	}
};

class Player : public Entity
{
};

class Enemy : public Entity
{
};

int main(int argc, char* argv[])
{
	/* this player already have two types:
	 * Player and Entity (type list)
	 */
	Player* player = new Player();
	Entity* actuallyPlayer = player; //implict cast

	Entity* actuallyEnemy = new Enemy();

	/* this should fail*/
	Player* p0 = dynamic_cast<Player*>(actuallyEnemy);
	/* this should success*/
	Player* p1 = dynamic_cast<Player*>(actuallyPlayer);

	/* if the cast valid, it return the value you want the player
	 * pointer, if not valid, it would give null
	 */

	/* compiler will have runtime type information, storage all type
	 * information in runtime (RTTI), which allows us do dynamic cast, if we
	 * turn off the run time type storage, it would have exceptions.
	 * Also, the dynamic cast is slower than normal cast because it
	 * search from the run time type storage for information.
	 */

	/* you can use dynamic casting like manage language Java
	 * instanceOf()
	 */

	if (dynamic_cast<Player*>(actuallyPlayer))
	{
		std::cout << "actuallyPlayer is instance of Player" << std::endl;
	}
}
