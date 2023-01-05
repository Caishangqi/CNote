#include <iostream>
#include <string>

int GetValue()
{
	return 10;
}

/* L value reference*/
int& GetValueL()
{
	static int value = 10;
	return value;
}

void PrintName(const std::string& name)
{
	std::cout << name << std::endl;
}

/* Rvalue reference allows us only accept R value*/
void PrintNameR(std::string&& name)
{
	std::cout << name << std::endl;
}

int main(int argc, char* argv[])
{
	/* we have two part of this expression
	 * L value often on left with memory space
	 */
	int i = 10;

	/* in this case GetValue() return a R value
	 * it return a temporary value, it have no
	 * storage and location
	 */
	int a = GetValue(); // taken the R value storage in to L value
	// GetValue() = 5; you can not assign something to R value

	/* L value reference*/
	GetValueL() = 5;

	/* another example*/
	std::string firstName = "Cai";
	std::string lastName = " Zii";

	/* fullName is L value and
	 * firstName + lastName is R value
	 */
	std::string fullName = firstName + lastName;
	PrintName(fullName);
	/* you need to add const to function parameter to accept
	 * both Rvalue and Lvalue
	 */
	PrintName(firstName + lastName);

	/* Rvalue reference allows us only accept R value*/
	PrintNameR(firstName + lastName);
}
