#include <algorithm>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main(int argc, char* argv[])
{
	std::vector<int> values = {3, 5, 1, 4, 2};
	/* sort in decending order
	 * std::greater will sort by great int as order
	 * 5 ,4, 3, 2, 1
	 */
	//std::sort(values.begin(), values.end(), std::greater<int>());
	std::sort(values.begin(), values.end(), [](int a, int b)
	{
		/* if we pass a and b , which one should be first of the list,
		 * if we return true, it means a will at before b
		 */

		return a < b;
	});

	for (int value : values)
		std::cout << value << std::endl;

	std::cin.get();
}
