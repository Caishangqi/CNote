#include <iostream>
#include <thread>

static bool thread_finished = false;

void doWork()
{
	using namespace std::literals::chrono_literals;
	while (!thread_finished)
	{
		std::cout << "Working...\n";
		std::this_thread::sleep_for(1s);
	}
}

int main(int argc, char* argv[])
{
	/* need a function pointer*/
	std::thread worker(doWork);

	/* this will block the thread until we press enter*/
	std::cin.get();
	/* when we press enter the main thread would not been
	 * blocked and go to next line set thread_finished to
	 * true. As a result, the while loop would end.
	 */
	thread_finished = true;

	/* join() will wait this thread to join
	 * wait on the current thread for this
	 * thread to finish its works. Basically,
	 * it block the current thread until this
	 * other thread complete.
	 */
	worker.join();
	std::cout << "Stoped!" << std::endl;

	std::cin.get();
}
