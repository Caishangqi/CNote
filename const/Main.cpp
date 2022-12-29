#include <iostream>
#include <string>

class Entity
{
private:
	int m_X, m_Y;
	mutable int var;
public:
	/*这意味着这个方法不能修改成员变量*/
	int getX() const
	{
		// read - only
		//m_X = 2;

		/*如果你需要在const方法里修改内容，你需要赐予关键词 mutable*/
		var = 5;
		return m_X;
	}

	void setX(int x)
	{
		m_X = x;
	}

};

int main(int argc, char* argv[])
{

	const int MAX_AGE = 90;

	int* a = new int; //create int on heap
	*a = 2;
	a = (int*)&MAX_AGE; //reassign the pointer
	std::cout << *a<< std::endl;

	/*只能改指向不能改内容的const用法*/
	const int* b = new int;
	//*b = 3 you can not change the content of the const pointer
	b = (int*)&MAX_AGE; //but you can change the direction

	/*可以改数据但不能改指向的 const用法*/
	int* const c = new int;
	*c = 15; //可以改指针指向的变量内容
	//c = (int*)&MAX_AGE; 不能修改指向

	/*既不能修改数据又不能重新指向*/
	const int* const d = new int;


	std::cin.get();

}
