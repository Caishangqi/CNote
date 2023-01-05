#include <iostream>

void PrintSum(int a, int b)
{
	std::cout << a << "+" << b << "=" << (a + b) << std::endl;
}

int main(int argc, char* argv[])
{
	int value = 0;
	/* different C++ version and different compiler would
	 * give us different result
	 */
	PrintSum(value++, value++); // it is undefined behaviour, unreliable
	std::cin.get();
}
