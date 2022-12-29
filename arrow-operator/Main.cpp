#include <iostream>
#include <string>

class Entity
{
public:
	int x;

	void Print() const
	{
		std::cout << "Hello!" << std::endl;
	}
};

class ScopedPtr
{
public:
	ScopedPtr(Entity* entity): m_Obj(entity)
	{
	}

	~ScopedPtr()
	{
		delete m_Obj;
	}

	/* overrides the -> operator and return Entity pointer*/
	Entity* operator->()
	{
		return m_Obj;
	}

private:
	Entity* m_Obj;
};

struct Vector3
{
	/* 因为float为4个字节因此
	 * x 初始offset 为 0
	 * y 初始offset 为 4
	 * z 初始offset 为 8
	 */
	float x, y, z;
};

int main(int argc, char* argv[])
{
	/* on stack*/
	Entity e;
	e.Print();

	/*(Entity is a pointer)*/
	Entity* ptr = &e;
	/* pointer is just a numeric value. you can not use "."
	 * Arrow operator is first dereferecing and print
	 */
	ptr->Print();
	ptr->x;

	/* smart pointer - unique pointer usage of arrow operator*/
	ScopedPtr entity = new Entity();
	/* how to use the print function through ScopedPtr ?*/
	entity->Print();

	/* another way use arrow operator by get offset of memory of a variable*/
	/* find the offset of member y memory offset in Vector3*/
	int offset_x = (int)&((Vector3*)nullptr)->x;
	/*
	 * 1. set a nullptr and cast to Vector3 pointer
	 * 2. use arrow to access x
	 */
	int offset_y = (int)&((Vector3*)nullptr)->y;
	int offset_z = (int)&((Vector3*)nullptr)->z;

	std::cin.get();
}
