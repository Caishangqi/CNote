#include <iostream>

/* ����һ��ȫ�ֱ����������ڳ����κεط�����*/
static int var = 0;

/* ����*/
class Singleton
{
public:
	static Singleton& Get()
	{
		/* �����ǵ�һ�ε���Get()���� �ṹ��һ�� �����ҷ���
		 * �ڶ��λ��߸���ε��û᷵����ͬ��
		 */
		static Singleton instance;
		return instance;
	}
	void echo() {}
};

void Function()
{
	/* ����ζ�ŵ����ǵ����������ʱ��������ͻᱻ����
	 * �����ǵڶ��ε����������ʱ��������������±�����
	 *
	 * ��Ȼ���������һֱ���ڣ������㲻��ֱ�ӷ��ʣ���ֻ��
	 * ͨ���������ȥ����
	 */
	static int i = 0;
	i++;
	std::cout << i << std::endl;
}

int main(int argc, char* argv[])
{
	/* ������� Function�õ� 1,2,3,4,5 ͬʱ�޷��������ط����� i*/
	Function();
	Function();
	Function();
	Function();
	Function();

}
