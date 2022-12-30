#include <iostream>
#include <string>

/* template 词意味着这会在编译时进行额外处理
 * Print下方的代码不是真正编译后的
 *
 * 当我们调用这个方法，会基于我们怎么调用，什么
 * 类型来生成源代码
 */
template <typename T>
/* 这里的模板参数是 T
 * 模板参数需要传入一个类型
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
	/* 想让 Array的大小在 编译时决定*/
	T m_Array[N];
};

int main(int argc, char* argv[])
{
	/* 想写一个方法接受不同类型的参数*/

	/* C++ 知道这个Print里面的数字是整数 int，所以它
	 * 自动推断出 T 为 int，你其实不需要 <>
	 */
	Print(5); //这里使用的隐性print

	/* 在我们调用这个 Print(5) 后，就相当于把 int传入
	 * T中，生成了一串Print(int value)的代码 <- 这是
	 * 真正存在的代码
	 */

	Print<int>(6); //这是显性print

	/* 模板不会生成 或者出现知道我们调用它，因此如果你
	 * 不调用模板，模板里的错误是不会报错的也可以正常编译
	 * 但是不会存在你的源代码中 (它不是真代码)
	 */
	Print("Caizii");
	Print(5.9f);

	/* 分配一个存放 int 类型并且大小为 5的Array类
	 * 编译时按照模板生成这段代码并且把 T, N 换成，
	 * 指定的模板参数
	 */
	Array<int, 5> array;
	std::cout << array.getSize() << std::endl;

	/* 什么时候用捏？
	 * - Logging System
	 * 别溜大了
	 */

	std::cin.get();
}
