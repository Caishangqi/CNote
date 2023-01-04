/* The Cherno �������ⲿ�����Լ��ļ���*/

/* �����Ǻ���ģ��
 * template< class Function, class... Args >
 * std::future<std::result_of_t<std::decay_t<Function>(std::decay_t<Args>...)>>
 * async( std::launch policy, Function&& f, Args&&... args );
 *
 * ���� ����f����һ���ɵ��ö���(�º�����lambda���ʽ�����Ա��������ͨ��������)�������첽����ͬ��ִ�С�
 * ����policy����ָ��ͬ��ִ�л����첽ִ�пɵ��ö������Ŀ�ѡֵ�����֣�
 * - std::launch::async���첽ִ�пɵ��ö���
 * - std::launch::deferred��ͬ��ִ�пɵ��ö���
 * - std::launch::async | std::launch::deferred �����첽����ͬ����ȡ���ھ���ʵ��
 *
 * ��������ֵ��std::future�������ǿ���ִ��get��wait��wait_for��wait_until������ȡ���ߵȴ�ִ�н��
 * ����std::future�����get����ʱ�����ִ�е����첽ִ�в��ԣ�����첽ִ��û�н�����get�������û�������ǰ
 * ��ǰ�����̣߳����ִ�е���ͬ��ִ�в��ԣ�ֻ�е�����get����ʱ������ִ��
 *
 * ����std::future�����wait*����ʱ�����ܷ�������״̬��
 * - std::future_status::deferred���ɵ��ö�����δ��ʼִ��
 * - std::future_status::ready���ɵ��ö���ִ�����
 * - std::future_status::timeout���ɵ��ö���ִ�г�ʱ
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
	// ��Ĭ�ϲ��Ե��� x.foo(42, "Hello") ��
	// ����ͬʱ��ӡ "Hello 42" ���ӳ�ִ��
	auto a1 = std::async(&X::foo, &x, 42, "Hello");
	// �� deferred ���Ե��� x.bar("world!")
	// ���� a2.get() �� a2.wait() ʱ��ӡ "world!"
	auto a2 = std::async(std::launch::deferred, &X::bar, x, "world!");
	// �� async ���Ե��� X()(43) ��
	// ͬʱ��ӡ "43"
	auto a3 = std::async(std::launch::async, X(), 43); // X() ��������д
	a2.wait(); // ��ӡ "world!"
	std::cout << a3.get() << '\n'; // ��ӡ "53"
} // �� a1 �ڴ˵�δ��ɣ��� a1 �����������ڴ˴�ӡ "Hello 42"
