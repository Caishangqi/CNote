/* a class only intend to have a single instance*/
#include <iostream>

class Random
{
public:
	/* we don't want to have a constructor*/
	static Random& getInstance()
	{
		/* call the first time, it will instantiate, and on subsequence times
		 * it was in static memory and just be reference.
		 */
		static Random instance;
		return instance;
	}

	/* delete copy constructor*/
	Random(const Random&) = delete;

	static float Float()
	{
		return getInstance().InternalFloat();
	}

	void Function()
	{
	}

private:
	/* make constructor private*/
	Random()
	{
	}

	float InternalFloat()
	{
		return m_RandomGenerator;
	}

	float m_RandomGenerator = 0.5f;
};


int main(int argc, char* argv[])
{
	auto& instance = Random::getInstance();
	instance.Function();

	/* generate a number without use getInstance()*/
	float number = Random::Float();
}
