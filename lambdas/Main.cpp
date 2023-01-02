#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void ForEach(const std::vector<int>& values, const std::function<void(int)> function)
{
	for (int i : values)
	{
		function(i);
	}
}

int main(int argc, char* argv[])
{
	std::vector<int> values = {1, 2, 3, 4, 5, 6};
	/* return a iteritor of below condition*/
	auto it = std::find_if(values.begin(), values.end(), [](int value)
	{
		return value > 3;
	});
	std::cout << *it << std::endl;

	/* [] means how will us pass the variable , by referecing or else
	 * [=] pass every thing by value
	 * [&] pass every thing by reference
	 * [a] pass individual value by value
	 * [&a] pass individual value by reference
	 */
	int a = 4;
	auto lambda = [=](int value) { std::cout << "Value: " << value << std::endl; };

	ForEach(values, lambda);

	std::cin.get();
}
