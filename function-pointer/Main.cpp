#include <iostream>
#include <vector>

void EchoWorld(int a)
{
	std::cout << "Hello World with value: " << a << std::endl;
}

/* because this function we only used as a parameter in Foreach()
 * we can declare this function in form of lambdas!
 */
void PrintValue(int value)
{
	std::cout << "Value: " << value << std::endl;
}


void ForEach(const std::vector<int>& values, void (*fuc)(int))
{
	for (int value : values)
	{
		//具体循环里面要执行什么方法，我们把一个方法传入到这个 ForEach方法中
		fuc(value);
	}
}

int main(int argc, char* argv[])
{
	/* get the function pointer, we do not use (), () is call function
	 * every single function get compiles into binary 
	 */
	auto function = EchoWorld; // we get the memory address of function

	/* what is the type?
	 * return Type + (*variable name) (argument)
	 */

	void (*caizii)(int);
	caizii = EchoWorld;

	/* use typedef */
	typedef void (*EchoWorldFunction)(int);
	EchoWorldFunction ef = EchoWorld;

	ef(2);
	function(3);
	function(4);

	/* good usage of function pointer*/
	std::vector<int> values = {1, 5, 4, 2, 3};
	/* create some function to iterate values*/
	ForEach(values, PrintValue);
	/* replace with lambdas*/
	ForEach(values, [](int value)
	{
		std::cout << "Value-lambdas-call: " << value << std::endl;
	});

	/* lets us find the EchoWorld() Function nd get the address*/
	std::cin.get();
}
