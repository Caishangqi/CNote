#include <iostream>

class String
{
public:
	String() = default;

	String(const char* string)
	{
		printf("Created!\n");
		m_Size = strlen(string);
		m_Data = new char[m_Size];
		memcpy(m_Data, string, m_Size);
	}

	/* need a copy constructor*/
	String(const String& other)
	{
		printf("Copied!\n");
		m_Size = other.m_Size;
		m_Data = new char[m_Size];
		memcpy(m_Data, other.m_Data, m_Size);
	}

	/* R value reference move!*/
	String(String&& other) noexcept
	{
		printf("Moved!\n");
		m_Size = other.m_Size;
		/* we assigning the pointer to m_Data
		 * the old one and the new one is share
		 * the same data.
		 */
		m_Data = other.m_Data;

		other.m_Size = 0;
		other.m_Data = nullptr;
	}

	String& operator=(String&& other) noexcept
	{
		printf("Moved!\n");

		if (this != &other)
		{
			delete[] m_Data;

			m_Size = other.m_Size;
			/* we assigning the pointer to m_Data
			 * the old one and the new one is share
			 * the same data.
			 */
			m_Data = other.m_Data;

			other.m_Size = 0;
			other.m_Data = nullptr;
		}
		return *this;
	}

	~String()
	{
		/* the delete will delete the null pointer of old data*/
		delete m_Data;
	}

	void Print()
	{
		for (uint32_t i = 0; i < m_Size; i++)
			printf("%c", m_Data[i]);
		printf("\n");
	}

private:
	char* m_Data;
	uint32_t m_Size;
};

class Entity
{
public:
	Entity(const String& name): m_Name(name)
	{
	}

	/* constructor that receive parameter as R value
	 * temporary value
	 */
	Entity(const String&& name) : m_Name(std::move(name))
	{
		/* it would move the R reference, temporary value into
		 * m_Name
		 */
	}

	void PrintName()
	{
		m_Name.Print();
	}

private:
	String m_Name;
};

int main(int argc, char* argv[])
{
	/* right now "Caizii" become R value*/
	Entity entity("Caizii");
	entity.PrintName();

	String string = "Hello";
	/* it is actually copying the string*/
	String dest = string;
	/* we want to let this string use the R reference constructor*/
	String destR = (String&&)string; // move the string to destR
	/* or we use std::move*/
	String destS = std::move(string);

	/* example*/
	printf("======example======");
	String apple = "Apple";
	String destA;

	std::cout << "Apple: ";
	apple.Print();
	std::cout << "DestA: ";
	destA.Print();

	/* transfer the ownership*/
	dest = std::move(apple);

	std::cout << "Apple: ";
	apple.Print();
	std::cout << "DestA: ";
	destA.Print();

	std::cin.get();
}
