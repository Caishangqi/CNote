#include <iostream>
using namespace std;
void func() {

	//Type 1
	//�������� ������[���鳤��]

	int valueArray_1[5];
	valueArray_1[0] = 10;
	valueArray_1[1] = 20;
	valueArray_1[2] = 30;
	valueArray_1[3] = 40;
	valueArray_1[4] = 50;

	//Type 2
	//�������� ������[���鳤��] = {value, value}
	int valueArray_2[5] = { 10,20,30,40,50 };

	//Type 3
	//�������� ������[] = {value, value}
	int valueArray_3[] = { 10,20,30,40,50 };
	//int ռ 4 �ֽ� �ܹ� 20 �ֽ�
	cout << "����ռ���ڴ�ռ� " << sizeof(valueArray_3) << endl;
	cout << "ÿ��Ԫ��ռ�ÿռ�Ϊ " << sizeof(valueArray_3[0]) << endl;
	cout << "Ԫ�ظ���Ϊ " << sizeof(valueArray_3) / sizeof(valueArray_3[0]) << endl;

	//�鿴�׵�ַ

	cout << "������׵�ַΪ " << (int)valueArray_3 << endl; //ǿת��10���� 17431292
	cout << "�����һ��Ԫ�ص�ַΪ " << (int) & valueArray_3[0] << endl; //& 17431292
	cout << "����ڶ���Ԫ�ص�ַΪ " << (int) & valueArray_3[1] << endl; //& 17431296
	//�׵�ַ = �����һ��Ԫ�صĵ�ַ
	//��һ��Ԫ�غ͵ڶ���Ԫ�ز�4



	//�����������޸���Ϊ�Ѿ��ǳ���ָ��һ����ֵַ

	//��ά����
	int arr[2][3] = { //���� 3��
		{1,2,3},
		{4,5,6}
	};


}