#include <iostream>
#include <vector>
#include <unordered_map>

int main(int argc, char* argv[])
{
	/* collections*/
	std::vector<int> values = {1, 2, 3, 4, 5};

	for (int value : values)
	{
		std::cout << value << std::endl;
	}

	/* begin iterator, end condition, loop manipulation "++"*/
	for (std::vector<int>::iterator it = values.begin(); it != values.end(); it ++)
	{
		std::cout << *it << std::endl;
	}

	/* map*/
	using ScoreMap = std::unordered_map<std::string, int>;

	std::unordered_map<std::string, int> map;
	map["Caizii"] = 5;
	map["Daizii"] = 6;

	for (ScoreMap::const_iterator iterator = map.begin(); iterator != map.end(); iterator++)
	{
		auto& key = iterator->first;
		auto& value = iterator->second;

		std::cout << "key = " << key << " value = " << value << std::endl;
	}

	/* use range based map*/
	for (auto KV : map)
	{
		auto& key = KV.first;
		auto& value = KV.second;

		std::cout << "key = " << key << " value = " << value << std::endl;
	}

	/* or use structure binding like Java, C++ 17 above*/
	for (auto [K,V] : map)
		std::cout << "key = " << K << " value = " << V << std::endl;

	std::cin.get();
}
