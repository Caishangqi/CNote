#include <iostream>

class Base
{
public:
	Base()
	{
	}

	virtual ~Base()
	{
	}
};

class Derived : public Base
{
public:
	Derived()
	{
	}

	~Derived()
	{
	}
};

class AnotherClass : public Base
{
public:
	AnotherClass()
	{
	}

	~AnotherClass()
	{
	}
};

int main(int argc, char* argv[])
{
	int a = 5;
	double value = a; //implicit conversion

	double valueE = (int)a; //explicit conversion

	/* C style cast*/
	double valueF = 5.25;
	double valueD = (int)valueF + 5.3;

	/* C++ style cast
	 * - static cast
	 * - reinterprete cast
	 * - dynamic cast
	 * - const cast
	 */

	double valueS = static_cast<int>(valueF) + 5.3;

	/* dynamic cast example*/

	Derived* derived = new Derived();

	Base* base = derived;

	/* we want to know whether base pointer point derived instance*/
	AnotherClass* ac = dynamic_cast<AnotherClass*>(base);
	/* if ac is null we can conclude that the ac pointer not pointer to instance
	 * of AnotherClass , which is base
	 */

	/* we can see dc have memory address which means it cast successful, it also mean
	 * base is instance of Derived
	 */
	Derived* dc = dynamic_cast<Derived*>(base);


	std::cin.get();
}
