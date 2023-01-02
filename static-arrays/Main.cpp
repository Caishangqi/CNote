#include <iostream>
#include <array>

/* implementation of print methods with templates argument*/
template <class T, size_t size>
void PrintArrayWithTemp(const std::array<T, size>& data)
{
	for (auto& i : data)
	{
		std::cout << i << std::endl;
	}
}

int main(int argc, char* argv[])
{
	/* need 2 argument, data type and size
	 * std::array keep track the size, the
	 * size is not storaged, however, it
	 * passed by template argument
	 */
	std::array<int, 5> data;
	data[0] = 2;
	data[1] = 5;
	PrintArrayWithTemp(data);

	/* old array need to maintain size*/
	int dataO[5];
	dataO[0] = 1;

	std::cin.get();
}
