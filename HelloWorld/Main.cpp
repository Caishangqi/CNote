#include <iostream> // ������ֻ���ڱ�������include·����������������
//include �����ҵ�һ���ļ���������һ���� iostream���ļ�������ļ��ᱻ���������ͷ�ļ���
#include "Log.h"

int main() { //main is entry point
	
	int a = 8; //00 00 00 00 00 00 00 00
	a++;
	const char* string = "Hello";

	Log("Hello World");
	std::cin.get();
}	//����Ҫ�������򷽷������κ����͵�ֵ 