#include <iostream>
using namespace std;
void func() {

	//���ʽ1 ? ���ʽ2 : ���ʽ3
	//���ʽtrue��ִ�б��2�� ���ʽ false�� ִ�б��ʽ3

	int a = 1;
	int b = 100;

	int c = 0;

	c = (a > b ? a : b);

	cout << "c = " << c << endl;

	//��Ŀ������ǿ��Լ�����ֵ��
	(a > b ? a : b) = 1000;
}