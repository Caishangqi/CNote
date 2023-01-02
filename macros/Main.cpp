#include <iostream>

#include <string>

/* using macros*/
#define WAIT std::cin.get()

/* using macros in different environment*/
#ifdef DEBUG
/* using macros with parameters*/
#define LOG(X) std::cout << X << std::endl
#else
#define LOG(X) //not put anything, it will replace with nothing
#endif

/* use \ for enter a new line*/
#define MAIN int main() \
{\
std::cin.get();\ // this \ will not trigger cin.get()
}

int main(int argc, char* argv[])
{
	/* during prepressor stage, this was replaced by
	 * std::cin.get()
	 */
	LOG("Hello");

	WAIT;
}
