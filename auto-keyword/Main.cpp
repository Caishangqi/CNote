#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Device
{
public:
};

class DeviceManager
{
public:
	const std::unordered_map<std::string, std::vector<Device*>>& getDevices()
	{
		return m_Devices;
	}

private:
	std::unordered_map<std::string, std::vector<Device*>> m_Devices;
};

int main(int argc, char* argv[])
{
	/* simple example show what is auto*/
	int a = 3;
	auto b = a;

	/* when use auto - example*/
	std::vector<std::string> strings;
	strings.push_back("Caizii");
	strings.push_back("Daizii");

	/* using iterator to iterate deal with massive type*/
	for (std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it ++)
	{
		/* you can see that the type of it is huge, we can replace with auto*/
		std::cout << *it << std::endl;
	}

	/* same with upper example*/
	for (auto it = strings.begin(); it != strings.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	/* using iterator to iterate deal with massive type*/
	DeviceManager dm;
	const std::unordered_map<std::string, std::vector<Device*>>& devices = dm.getDevices();
	/* massive type, 3 way solution*/
	using DeviceMap = std::unordered_map<std::string, std::vector<Device*>>;
	typedef std::unordered_map<std::string, std::vector<Device*>> DeviceMap;

	/* 这里 auto 不用引用会重新复制一份*/
	const auto& devicesA = dm.getDevices();

	/* sb c++*/
	std::cin.get();
}
