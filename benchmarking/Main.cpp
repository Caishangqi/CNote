#include <iostream>
#include <memory>
#include <chrono>
#include <array>

class Timer
{
public:
	/* constructor start the timer*/
	Timer()
	{
		std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		Stop();
	}

	void Stop()
	{
		auto endTimePoint = std::chrono::high_resolution_clock::now();
		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StratTimePoint).time_since_epoch().
			count();
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().
			count();
		auto duration = end - start;
		double ms = duration * 1000;

		std::cout << duration << "us (" << ms << "ms)\n";
	}

private:
	std::chrono::time_point<std::chrono::high_resolution_clock> m_StratTimePoint;
};

int main(int argc, char* argv[])
{
	int value = 0;
	{
		Timer timer;
		for (int i = 0; i < 1000000; i++)
		{
			value += 2;
		}
	}


	std::cout << value << std::endl;

	/* create many pointers*/
	struct Vector2
	{
		float x, y;
	};

	std::cout << "Make Shared" << std::endl;
	{
		std::array<std::shared_ptr<Vector2>, 1000> sharedPtrs;
		Timer timer;
		for (int i = 0; i < sharedPtrs.size(); i++)
		{
			sharedPtrs[i] = std::make_shared<Vector2>();
		}
	}

	std::cout << "New Shared" << std::endl;
	{
		std::array<std::shared_ptr<Vector2>, 1000> sharedPtrs;
		Timer timer;
		for (int i = 0; i < sharedPtrs.size(); i++)
		{
			sharedPtrs[i] = std::shared_ptr<Vector2>(new Vector2());
		}
	}

	std::cout << "Make Unique" << std::endl;
	{
		std::array<std::unique_ptr<Vector2>, 1000> sharedPtrs;
		Timer timer;
		for (int i = 0; i < sharedPtrs.size(); i++)
		{
			sharedPtrs[i] = std::make_unique<Vector2>();
		}
	}

	/* always check performance on release mode*/

	__debugbreak();
}
