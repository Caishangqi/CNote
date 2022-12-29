#include <iostream>

class Entity
{
public:
	float x, y; //实例化分配内存时如果没有指定值则在内存中是随机的值

	//构造器，C++不会帮你自动设置内存初始化
	Entity()
	{
		x = 0.0f;
		y = 0.0f;
		std::cout << "Created this object" << std::endl;
	}

	//含参构造器 (重载)
	Entity(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	~Entity() //Destructor
	{
		std::cout << "Destroyed this object" << std::endl;
	}

	void Init()
	{
		x = 0.0f;
		y = 0.0f;
	}

	void echo()
	{
		std::cout << x << ", " << y << std::endl;
	}
};

class Log
{
public:
	static void write()
	{
	}

	Log() = delete; //删除默认构造器,或者表示这个函数不可用

private:
	// Log()
	// {
	// }
	// //可以把构造器放入private让别人无法实例化它  // NOLINT(clang-diagnostic-invalid-utf8)
};

void Fuction()
{
	Entity e; //由于在堆栈上创建的，超出范围自动摧毁
	e.echo();
} //在这里自动摧毁 调用删除函数

int main(int argc, char* argv[])
{
	//Entity e(10.0f, 5.0f);
	//Entity e1;
	//e.echo();
	//Log::write();
	Fuction(); 
	std::cin.get();
}
