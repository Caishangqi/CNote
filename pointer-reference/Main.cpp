#include <iostream>

#define LOG(x) std::cout << x << std::endl
//���þ���ָ�룬ֻ����д����һ��

//���ñ�����������һ���Ѿ����ڵı���������������һ���±���


void Increment(int* value) {
	//����������� "*"����ô���ӵľ��ǵ�ַ�����ǵ�ַ��Ӧʵ�ʵ�ֵ
	*value = *value + 1;

}

void Increment(int& value) {
	//Ҳ������ôд
	// int& value = value
	value = value + 1; //�����ñ���ִ�в������Ƕ�ʵ�ʱ������в���

}

int main()
{
	int a = 5;
	//�������У�&�Ǳ�����һ����
	int& ref = a; //������һ������ ref �ı�����ֻ��Դ�����д��ڣ�ʵ��ֻ��a
	ref = 2;



	//��ͼʹ�����ô��뺯����
	int b = 5;
	
	/*
	* ����͵��� int& value = b; ������һ��v��b�����ý���value
	* Ȼ��value������������������������ָ���ֵַһ��ʵ�ʾ��ǰ�b����������
	*/
	Increment(b); //��ָ�봫��ȥ�����ݱ������ڴ��ַ

	LOG(a);
	LOG(b);
	std::cin.get();
}
