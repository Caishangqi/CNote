/* The Cherno 摆烂了这部分是自己的见解*/

/* 以下是函数模型
 * template< class Function, class... Args >
 * std::future<std::result_of_t<std::decay_t<Function>(std::decay_t<Args>...)>>
 * async( std::launch policy, Function&& f, Args&&... args );
 *
 * 其中 参数f接收一个可调用对象(仿函数、lambda表达式、类成员函数、普通函数……)，用于异步或是同步执行。
 * 参数policy用于指定同步执行或者异步执行可调用对象，它的可选值有三种：
 * - std::launch::async：异步执行可调用对象
 * - std::launch::deferred：同步执行可调用对象
 * - std::launch::async | std::launch::deferred 可以异步或是同步，取决于具体实现
 *
 * 函数返回值是std::future对象，我们可以执行get、wait、wait_for、wait_until函数获取或者等待执行结果
 * 调用std::future对象的get函数时，如果执行的是异步执行策略，如果异步执行没有结束，get函数调用会阻塞当前
 * 当前调用线程；如果执行的是同步执行策略，只有当调用get函数时才真正执行
 *
 * 调用std::future对象的wait*函数时，可能返回三种状态：
 * - std::future_status::deferred：可调用对象尚未开始执行
 * - std::future_status::ready：可调用对象执行完毕
 * - std::future_status::timeout：可调用对象执行超时
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <future>
#include <string>
#include <mutex>

std::mutex m;

struct X
{
	void foo(int i, const std::string& str)
	{
		std::lock_guard<std::mutex> lk(m);
		std::cout << str << ' ' << i << '\n';
	}

	void bar(const std::string& str)
	{
		std::lock_guard<std::mutex> lk(m);
		std::cout << str << '\n';
	}

	int operator()(int i)
	{
		std::lock_guard<std::mutex> lk(m);
		std::cout << i << '\n';
		return i + 10;
	}
};

template <typename RandomIt>
int parallel_sum(RandomIt beg, RandomIt end)
{
	auto len = end - beg;
	if (len < 1000)
		return std::accumulate(beg, end, 0);

	RandomIt mid = beg + len / 2;
	auto handle = std::async(std::launch::async,
	                         parallel_sum<RandomIt>, mid, end);
	int sum = parallel_sum(beg, mid);
	return sum + handle.get();
}

int main()
{
	std::vector<int> v(10000, 1);
	std::cout << "The sum is " << parallel_sum(v.begin(), v.end()) << '\n';

	X x;
	// 以默认策略调用 x.foo(42, "Hello") ：
	// 可能同时打印 "Hello 42" 或延迟执行
	auto a1 = std::async(&X::foo, &x, 42, "Hello");
	// 以 deferred 策略调用 x.bar("world!")
	// 调用 a2.get() 或 a2.wait() 时打印 "world!"
	auto a2 = std::async(std::launch::deferred, &X::bar, x, "world!");
	// 以 async 策略调用 X()(43) ：
	// 同时打印 "43"
	auto a3 = std::async(std::launch::async, X(), 43); // X() 操作符重写
	a2.wait(); // 打印 "world!"
	std::cout << a3.get() << '\n'; // 打印 "53"
} // 若 a1 在此点未完成，则 a1 的析构函数在此打印 "Hello 42"
