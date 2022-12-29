#include <iostream>
#include <string>

class Entity
{
public:
	Entity()
	{
		std::cout << "Created Entity!" << std::endl;
	}

	~Entity()
	{
		std::cout << "Destroyed Entity!" << std::endl;
	}
};

/*错误示范*/
int* CreateArrayFail()
{
	int array[50]; //分配50 x 4 字节并且返回当前地址指针
	/* 我们确实返回了指向这块内存的指针
	 * 但是这是创建到stack上面的数据，
	 * 因此在return结束后对应地址的内存
	 * 会被释放
	 */
	return array;
}

/*正确示范*/
int* CreatArraySucc()
{
	int* array = new int[50]; //分配200字节在heap上并且返回地址指针
	return array;
}

/*手搓的scoped pointer (Unique Pointer)*/
class ScopedPtr
{
public:
	ScopedPtr(Entity* ptr) : m_Ptr(ptr)
	{
	}

	~ScopedPtr()
	{
		delete m_Ptr;
	}

private:
	Entity* m_Ptr;
};

int main(int argc, char* argv[])
{	// begin of scope
	{
		

		Entity e;
	} // end of scope

	{
		Entity* eh = new Entity();
		/*如何让Entity自动销毁？使用 unique pointer - scoped pointer*/
		ScopedPtr sp = new Entity(); //这里还有隐性转换内容 P39
		/*ScopedPtr 是创建在 stack上的，这意味着当离开scope范围后，sp会自动删除
		 * 调用摧毁构造器，在摧毁构造器中执行了 delete m_Ptr 也就是 Entity的指针
		 */
	}

	std::cin.get();
}
