#include <iostream>
#include "GLFW/glfw3.h"
/* ͨ�������һ���ⲿ������Ϊ��������
 * - include: ���ͷ�ļ� ������C++ ���棬����������ַ: $(ProjectDir)Dependencies\GLFW\include
 * - lib-vc20xx: ��ŷ������ ������C++ ������������������ַ: $(ProjectDir)Dependencies\GLFW\lib-vc2022 (������ʹ�õ� .lib��Ŀ¼)
 * �����㻹��Ҫ�� ������C++ ������ ���� > ������Ҫʹ���ĸ� .lib ����ʹ�� glfw3.lib
 */

/* Chernol ���� : �����������Ŀ���� vs �� "" ��֮�� <>*/

/* �ڶ���������Ҫ���� header file����ĺ��������������ĺ�����
 * ����linker�Ż�����������������������ᱨ�� reference error
 */
int main(int argc, char* argv[])
{
	int a = glfwInit();
	std::cout << a << std::endl; //�ɹ��� ��1��
	std::cin.get();

}
