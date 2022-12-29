#include <iostream>
using namespace std;
void func() {

	//表达式1 ? 表达式2 : 表达式3
	//表达式true，执行表达2， 表达式 false， 执行表达式3

	int a = 1;
	int b = 100;

	int c = 0;

	c = (a > b ? a : b);

	cout << "c = " << c << endl;

	//三目运算符是可以继续赋值的
	(a > b ? a : b) = 1000;
}