#include <iostream>
#include <string>

using String = std::string;

class Entity
{
public:
	Entity(): m_Name("Unknown")
	{
	}

	Entity(const String& name) : m_Name(name)
	{
	}

	const String& getName() const { return m_Name; }

private:
	String m_Name;
};

void Function() //调用该函数时stack函数被创建，里面存放所有括号内
{
	int a = 2;
	Entity entity = Entity("?");
} //一但到达最底部，这个entity从内存中被摧毁

int main(int argc, char* argv[])
{
	/*creating on the stack*/
	Entity entity; //use the default constructor
	Entity entity2 = Entity("Caizii");
	/*if you can create object like this, do like this*/
	std::cout << entity2.getName() << std::endl;

	Entity* e;
	{
		Entity entity3 = Entity("OP");
		e = &entity3;
		std::cout << entity3.getName() << std::endl;
	}
	/*在这即使指针 e 指向相同的地址但是地址内部的Entity值是空的
	 * {m_name = ""} 对象被摧毁
	 */


	/*creating on the heap*/
	Entity* e1;
	{
		//类型是Entity的指针
		//使用new 关键词就在heap上分配内存
		//返回一个Entity的指针告诉我们这个entity在heap的哪个地址！
		Entity* entityHeap = new Entity("ABBA");
		e1 = entityHeap; //指向我们设置的指针
		std::cout << (*entityHeap).getName() << std::endl; //解引获取实际变量
		std::cout << entityHeap->getName() << std::endl; //或者使用箭头
		/*不能随便在heap上面放东西的几个原因：
		 * 1. heap创建对象相对较慢，性能损失
		 * 2. 你必须手动删除heap上的对象
		 */
		
	}
	delete e1; //别忘了释放Heap上的东西

	std::cin.get();
}
