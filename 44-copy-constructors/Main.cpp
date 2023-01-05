#include <iostream>
#include <string>

class String
{
public:
	String(const char* string)
	{
		m_Size = strlen(string);
		m_Buffer = new char[m_Size + 1]; // +1 for end terminator
		//把string的内容拷贝到buffer里面
		memcpy(m_Buffer, string, m_Size);
		m_Buffer[m_Size] = 0; // add the terminate 0
	}

	/*使用friend意味着这个方法可以直接使用类的私有成员*/
	friend std::ostream& operator<<(std::ostream& stream, const String& string);

	char& operator[](unsigned int index)
	{
		return m_Buffer[index];
	}

	/*need to delete avoid memory leaking*/
	~String()
	{
		delete[] m_Buffer;
	}

	/* copy constructor
	 * you can disable this copy constructor
	 */
	String(const String& other)
	/* do the deep copy*/: m_Size(other.m_Size)
	{
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
	}

private:
	char* m_Buffer;
	unsigned int m_Size;
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
	stream << string.m_Buffer;
	return stream;
}

int mainF(int argc, char* argv[])
{
	String string = "Caizii";
	/* assign to another string
	 * 这会导致错误，因为C++ 进行了浅拷贝，把对象里面的成员变量一起拷贝了
	 * 这导致了char* m_Buffer 会有相同的地址，在这个scope结尾会调用des
	 * tructor导致释放同一个内存空间2次
	 */
	String second = string;

	std::cout << string << std::endl;
	std::cout << second << std::endl;
	std::cin.get();

	return 1;
}
