#include <iostream>
#include <string>

/* template ����ζ������ڱ���ʱ���ж��⴦��
 * Print�·��Ĵ��벻������������
 *
 * �����ǵ�����������������������ô���ã�ʲô
 * ����������Դ����
 */
template <typename T>
/* �����ģ������� T
 * ģ�������Ҫ����һ������
 */
void Print(T value)
{
	std::cout << value << std::endl;
}

template <typename T, int N>
class Array
{
public:
	int getSize() const
	{
		return N;
	}

private:
	/* ���� Array�Ĵ�С�� ����ʱ����*/
	T m_Array[N];
};

int main(int argc, char* argv[])
{
	/* ��дһ���������ܲ�ͬ���͵Ĳ���*/

	/* C++ ֪�����Print��������������� int��������
	 * �Զ��ƶϳ� T Ϊ int������ʵ����Ҫ <>
	 */
	Print(5); //����ʹ�õ�����print

	/* �����ǵ������ Print(5) �󣬾��൱�ڰ� int����
	 * T�У�������һ��Print(int value)�Ĵ��� <- ����
	 * �������ڵĴ���
	 */

	Print<int>(6); //��������print

	/* ģ�岻������ ���߳���֪�����ǵ���������������
	 * ������ģ�壬ģ����Ĵ����ǲ��ᱨ���Ҳ������������
	 * ���ǲ���������Դ������ (�����������)
	 */
	Print("Caizii");
	Print(5.9f);

	/* ����һ����� int ���Ͳ��Ҵ�СΪ 5��Array��
	 * ����ʱ����ģ��������δ��벢�Ұ� T, N ���ɣ�
	 * ָ����ģ�����
	 */
	Array<int, 5> array;
	std::cout << array.getSize() << std::endl;

	/* ʲôʱ������
	 * - Logging System
	 * �������
	 */

	std::cin.get();
}
