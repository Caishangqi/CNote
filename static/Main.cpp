#include <iostream>

int s_Variable; //会在外部寻找变量
void Function() {}
int main() {

	std::cout << s_Variable << std::endl;
	std::cin.get();

}