#include <iostream>
#include <string>

/*this ֻ�����Ƿ������ڲ�����
 * this ��һ��ָ��ָ��ǰ���������Ķ���
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
		Entity* const e = this; // const e ��ζ�������޷������ָ�����������ڴ�
		/*��Ҫ��������������x �� y*/
		e->x = x; //��Ϊ����һ��ָ�����Խ�������Ҫʹ�ü�ͷ ���� (*e)
		/*��д����д��*/
		this->y = y;

		/*������뵱ǰ����һ������������ķ���*/
		printEntity(this);
	}

	int getX() const
	{
		/*��Ϊ�����ڷ��������޸ĳ�Ա������ EntityҲ�ͳ�Ϊ�� const*/
		const Entity* e = this;

		return x;
	}
};




int main(int argc, char* argv[])
{
	std::cin.get();
}
