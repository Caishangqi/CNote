#include <iostream>
#include <string>

/*
 * ���ã����ᱻ���ƣ�����const��ʾ���ǳ�ŵ�����޸���
 */
void PrintString(const std::string& string)
{
	std::cout << string << std::endl;
}

/*
 * �����ֻ������������Ĳ����ᱻ����һ���ٴ�ӡ����Ӱ��ԭ��
 * ���������
 */
void PrintString(std::string string)
{
	
	std::cout << string << std::endl;
}

int main(int argc, char* argv[])
{
	/*һ����˵��char������const��Ϊ������˼ һ�������ǲ����޸ĵ�
	 * name��һ��ָ�룬ָ��һ���ַ������� "Caizii"
	 */
	const char* name = "Caizii"; //43 61 69 7a 69 69 00
	//ĩβ�� 00 �����ַ�������

	/* ��Ҳ���Բ�ʹ��ָ���ֶ������ڴ棬6���ַ�������8��Ԫ��
	 * ��Ϊ���һ��Ԫ����Ҫ��� 0 null termination character
	 */
	char name2[7] = { 'C','a','i','z','i','i', 0 }; //�������������ĩβ����,null�Ļ����������Զ���� cc
	std::cout << name2 << std:: endl;
	//����㲻��new �Ͳ���Ҫdelete

	/*ʹ��C++����string��*/
	std::string cname = "Caizii";

	/*����*/
	std::string mline = "Caizii\n"
		"Daizii\n"
		"Eaizii\n"
		"Faizii";

	std::cout << mline << std::endl;


	std::cin.get();
}
