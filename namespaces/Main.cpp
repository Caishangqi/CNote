/* primary purpose for using namespace is avoid naming conflicts*/

#include  <iostream>
#include <string>
#include <algorithm>

namespace apple
{
	namespace function
	{
		void print(const char* text)
		{
			std::cout << text << std::endl;
		}
	}
}

namespace orange
{
	void print(const char* text)
	{
		std::string temp = text;
		std::reverse(temp.begin(), temp.end());
		std::cout << temp << std::endl;
	}
}

int main(int argc, char* argv[])
{
	/* you can using namespace and do not need write apple
	 * using name space in scope would be restricted only
	 * in the space
	 */
	using namespace apple;

	function::print("use namespace");

	/* without using namespace*/
	apple::function::print("Apple");
	orange::print("Apple");

	/* try to confined the using namespace in to a scope,
	 * DO NOT USE NAMESPACE AT TOP LEVEL AND HEADER FILES!
	 */
	std::cin.get();
}
