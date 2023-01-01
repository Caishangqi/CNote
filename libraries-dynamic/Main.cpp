#include <iostream>
#include "GLFW/glfw3.h"

/* dynamic libaries ���ȱ���� .dll���� exe ͬĿ¼��
 * �������Ҫ�� ������ > ���� > ����������Ŀ ����Ϊ glfw3dll.lib
 * ����ļ�ƥ����header file��dll ������ƥ�䣬��ֹ������λ���ڴ��λ�ȵ�
 */

/*
 * If you use lib + dll��you don't need __declspec(dllimport)
 * because all the functions or variables you wan't to import
 * have defined in lib as pointer;but if you use LoadLibary
 * API to import dll, with   __declspec(dllimport) you can
 * tell the compiler which function or variable you want to
 * import, it will reduce the import time
 */

int main(int argc, char* argv[])
{
	int a = glfwInit();
	std::cout << a << std::endl; //�ɹ��� ��1��
	std::cin.get();

}
