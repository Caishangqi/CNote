#include <iostream>
#include <string>

/*this 只让我们访问类内部函数
 * this 是一个指针指向当前方法所属的对象
 */

class Entity;

void printEntity(Entity* entity)
{
	int a = 10;
	//Print
}

class Entity
{
public:
	int x, y;

	Entity(int x, int y)
	{
		Entity* const e = this; // const e 意味着我们无法把这个指针分配给其他内存
		/*需要引用属于这个类的x 和 y*/
		e->x = x; //因为这是一个指针所以解引用需要使用箭头 或者 (*e)
		/*简写可以写成*/
		this->y = y;

		/*如果像传入当前对象到一个定义在类外的方法*/
		printEntity(this);
	}

	int getX() const
	{
		/*因为不能在方法体中修改成员变量， Entity也就成为了 const*/
		const Entity* e = this;

		return x;
	}
};




int main(int argc, char* argv[])
{
	std::cin.get();
}
