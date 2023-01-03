#include <iostream>

class Base
{
public:
	Base()
	{
		std::cout << " Base Created\n";
	}

	virtual ~Base()
	{
		std::cout << " Base Destroyed\n";
	}
};

class Derived : public Base
{
public:
	Derived()
	{
		std::cout << " Derived Created\n";
	}

	~Derived()
	{
		std::cout << " Derived Destroyed\n";
	}
};


int main(int argc, char* argv[])
{
	Base* base = new Base();
	delete base;

	std::cout << "----------------\n";

	Derived* derived = new Derived();
	delete derived;

	std::cout << "----------------\n";
	/* we create a Derived but assign to Base type*/
	Base* poly = new Derived();
	delete poly; // we are missing Derived destructor called, which cause memory leak

	/* C++ do not know we have a override destructor of Derived class
	 * which means if you treat Derived class as Base class, it would only use the Base
	 * class destructor, C++ do not know the relationship between 2 classes, you need
	 * add virtual to ~Base() let C++ know there is a overwriting destructor
	 */

	std::cin.get();
}
