#include <iostream>
#include <any>
#include <string>

int main(int argc, char* argv[])
{
	/* std::any is not type safety, and not performance good
	 * in the implementation, std::any give two option, big
	 * pointer and small pointer, if the byte of any not exceed
	 * 32, it would allocate 32 byte act exactly like union,
	 * or else, it would use NEW key word to dynamically
	 * allocate enough memory on heap.
	 */
	std::any data;
	data = 2;
	data = "Cherno";

	/* retrieve the data use reference for good performance*/
	std::string& result = std::any_cast<std::string&>(data);

	std::cin.get();
}
