#include <iostream>
#include <string>

class String
{
public:
	String(const char* string)
	{
		m_Size = strlen(string);
		m_Buffer = new char[m_Size + 1]; // +1 for end terminator
		//��string�����ݿ�����buffer����
		memcpy(m_Buffer, string, m_Size);
		m_Buffer[m_Size] = 0; // add the terminate 0
	}

	/*ʹ��friend��ζ�������������ֱ��ʹ�����˽�г�Ա*/
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
	 * ��ᵼ�´�����ΪC++ ������ǳ�������Ѷ�������ĳ�Ա����һ�𿽱���
	 * �⵼����char* m_Buffer ������ͬ�ĵ�ַ�������scope��β�����des
	 * tructor�����ͷ�ͬһ���ڴ�ռ�2��
	 */
	String second = string;

	std::cout << string << std::endl;
	std::cout << second << std::endl;
	std::cin.get();

	return 1;
}
