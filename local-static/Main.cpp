#include <iostream>

/* 这是一个全局变量，可以在程序任何地方访问*/
static int var = 0;

/* 单例*/
class Singleton
{
public:
	static Singleton& Get()
	{
		/* 当我们第一次调用Get()方法 会构建一个 对象并且返回
		 * 第二次或者更多次调用会返回相同的
		 */
		static Singleton instance;
		return instance;
	}
	void echo() {}
};

void Function()
{
	/* 这意味着当我们调用这个方法时这个变量就会被创建
	 * 在我们第二次调用这个方法时这个变量不会重新被创建
	 *
	 * 虽然这个变量会一直存在，但是你不能直接访问，你只能
	 * 通过这个方法去访问
	 */
	static int i = 0;
	i++;
	std::cout << i << std::endl;
}

int main(int argc, char* argv[])
{
	/* 调用五次 Function得到 1,2,3,4,5 同时无法再其他地方调用 i*/
	Function();
	Function();
	Function();
	Function();
	Function();

}
