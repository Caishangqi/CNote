#include <iostream>
#include <variant>
/* allow us not worry about the exact data type but value, and
deal with the type later*/

enum class ErrorCode
{
	None = 0,
	NotFound = 1,
	NoAccess = 2
};

/* we can return variant based on what we expect
 * if read success, we return string, else we could
 * return Error Code
 */
std::variant<std::string, ErrorCode> ReadFileAsString()
{
	return {};
}

int main()
{
	/* first list all possible type*/
	std::variant<std::string, int> data;
	data = "Caizii";
	/* access the data*/
	std::cout << std::get<std::string>(data) << std::endl;

	data = 2;
	/* tell us which type in sequence of index we store*/
	data.index(); // 1 because int is in index 1 and we assign a int

	data = "Caizii"; // 0 because string is in index 0, and we assign a string

	/* or we can use get_if() to get the pointer*/
	auto* value = std::get_if<std::string>(&data);
	/* we can check the pointer is null or not, if is not that
	 * type it would gives us the null pointer, if it is that
	 * type it would give us the pointer to that string
	 */

	if (auto value = std::get_if<std::string>(&data))
	{
		/* dereference of value*/
		std::string& v = *value;
	}
	else
	{
		//...
	}

	/* access the data*/
	std::cout << std::get<int>(data) << std::endl;
}
