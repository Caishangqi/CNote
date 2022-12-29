#include <iostream>
#include <string>

using String = std::string;
/*
 * new 关键词的主要目的就是在heap上分配内存 new + DataType
 * - 基于你的数据类型，会决定需要分配的内存大小空间，int 为 4 byte
 * - 当获得大小后，会让C 标准库去向系统索要 4 byte 空间
 * - 接下来需要寻找在内存中 连续 的4 byte的可分配空间
 * - 4 byte是一个比较小的空间所以搜索并且分配不需要很多时间
 * - 但是系统还是需要去花时间去找到那个地址有连续的4个 byte空的内存
 * - 一旦它找到哪个空间，它就会返回一个指向该内存的指针
 * - 接下来你就可以依据这个指针(地址)去存数据
 */

class Entity
{
public:
	Entity() : m_Name("Unknown")
	{
	}

	Entity(const String& name) : m_Name(name)
	{
	}

	const String& getName() const { return m_Name; }

private:
	String m_Name;
};


int main(int argc, char* argv[])
{
	//new return a pointer
	int* b = new int; // 4 byte
	int* c = new int[50]; // 200 byte

	//不仅仅分配了内存，new 还调用了构造器
	Entity* e = new Entity(); //这行分配大小返回指针并且调用了构造器
	//还会调用 malloc() 等同于
	Entity* e2 = (Entity*)malloc(sizeof(Entity)); //这行纯粹分配指定大小的内存返回对应指针

	/*你必须确保使用delete*/
	free(e);
	delete(e); //delete也调用构造器

	/*如果你分配内存时使用了 [] 那么删除时也需要带上 []*/
	delete[] c;

	std::cin.get();
}
