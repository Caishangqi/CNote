#include <iostream>
#include <string>
#include <fstream>
#include <optional>

/* use for storage data may not be present*/

std::optional<std::string> ReadFileAsString(const std::string& filepath)
{
	std::ifstream stream(filepath);
	/* read if success or fail*/

	if (stream)
	{
		// read file
		std::string result;
		stream.close();
		return result;
	}

	return {}; // means no value
}

int main(int argc, char* argv[])
{
	std::optional<std::string> data = ReadFileAsString("data.txt");
	/* if data not exist ir will return this fallback value*/
	std::string value = data.value_or("Not present");
	std::cout << value << std::endl;

	if (data.has_value())
	{
		std::cout << "File read successfully! \n";
	}
	else
	{
		std::cout << "File could not be opened! \n";
	}
	std::cin.get();
}
