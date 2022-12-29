#include <iostream>
#include <string>
/*
 * Mutable 中文意思为说谎的，可以改变的
 * immutable 为不可改变的
 */
class Entity
{
public:
	const std::string& getName() const
	{
		m_DebugCount++; //有 mutable 就可以在const方法中更改
		return m_Name;
	}

private:
	std::string m_Name;
	mutable int m_DebugCount = 0;
};

int main(int argc, char* argv[])
{
	const Entity e; //如果你要建立 const的Entity并且调用getName，你的方法也必须要又const修饰符
	e.getName();

	int x = 8;
	/*mutable 也可以用于lambdas*/
	auto f = [=]() mutable 
	{
		/*表示传入lambdas的变量可以被修改*/
		x++;
		std::cout << x << std::endl;
		
	};

	f(); //在这之后x = 8 因为使用的不是引用而是 = ，会复制一份 x 进入lambdas进行计算

	std::cin.get();
}
