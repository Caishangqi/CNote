#include <iostream>
#include <tuple>
#include <string>
/* deal with multiple return value C++ 17 */

/* old way with using tuple*/
std::tuple<std::string, int> CreatePerson()
{
	return {"caizii", 21};
}


int main(int argc, char* argv[])
{
	/* using tuple*/
	auto person = CreatePerson();
	std::string& name = std::get<0>(person);
	int age = std::get<1>(person);

	/* new way in C++ 17*/
	auto [nameP, ageP] = CreatePerson();
	std::cout << nameP;

	std::cin.get();
}
