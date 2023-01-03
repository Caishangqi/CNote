#include <iostream>
#include <chrono>
#include <thread>

/* using object life time to make it*/
struct Timer
{
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;

	Timer()
	{
		/* constructor start the timer*/
		auto start = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		/* constructor start the timer*/
		auto end = std::chrono::high_resolution_clock::now();
		duration = end - start;

		float ms = duration.count() * 1000;
		std::cout << "Timer took" << ms << "ms" << std::endl;
	}
};

void Function()
{
	Timer timer;
	for (int i = 0; i < 100; i++)
		std::cout << "Hello\n";
}

int main(int argc, char* argv[])
{
	using namespace std::literals::chrono_literals;
	/* gives the current time*/
	auto start = std::chrono::high_resolution_clock::now();

	/* pause execution for 1 second*/
	std::this_thread::sleep_for(1s);

	auto end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<float> duration = end - start;

	std::cout << duration.count() << "s" << std::endl;

	Function();
	std::cin.get();
}
