#include <iostream>
using namespace std;
void func() {

	//Type 1
	//数据类型 数组名[数组长度]

	int valueArray_1[5];
	valueArray_1[0] = 10;
	valueArray_1[1] = 20;
	valueArray_1[2] = 30;
	valueArray_1[3] = 40;
	valueArray_1[4] = 50;

	//Type 2
	//数据类型 数组名[数组长度] = {value, value}
	int valueArray_2[5] = { 10,20,30,40,50 };

	//Type 3
	//数据类型 数组名[] = {value, value}
	int valueArray_3[] = { 10,20,30,40,50 };
	//int 占 4 字节 总共 20 字节
	cout << "数组占用内存空间 " << sizeof(valueArray_3) << endl;
	cout << "每个元素占用空间为 " << sizeof(valueArray_3[0]) << endl;
	cout << "元素个数为 " << sizeof(valueArray_3) / sizeof(valueArray_3[0]) << endl;

	//查看首地址

	cout << "数组的首地址为 " << (int)valueArray_3 << endl; //强转成10进制 17431292
	cout << "数组第一个元素地址为 " << (int) & valueArray_3[0] << endl; //& 17431292
	cout << "数组第二个元素地址为 " << (int) & valueArray_3[1] << endl; //& 17431296
	//首地址 = 数组第一个元素的地址
	//第一个元素和第二个元素差4



	//数组名不能修改因为已经是常量指向一个地址值

	//二维数组
	int arr[2][3] = { //两行 3列
		{1,2,3},
		{4,5,6}
	};


}