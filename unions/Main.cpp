#include <iostream>

struct Vector2
{
	float x, y;
};

struct Vector4
{
	/* a 16 byte union*/
	union
	{
		struct
		{
			float x, y, z, w;
		};

		/* the second struct which means will occupied the same space of memory*/
		struct
		{
			Vector2 a, b;
			/* a would be the same as x, y
			 * b would be the same as z, w
			 */
		};
	};
};

void printVector2(const Vector2& vector)
{
	std::cout << vector.x << ", " << vector.y << std::endl;
}

int main(int argc, char* argv[])
{
	struct Union
	{
		/* anonymous union
		 * union will only have one block of memory
		 */
		union
		{
			/* two different way to address same memory*/
			float a;
			int b;
		};
	};

	/* used for type punning*/
	Union u;
	u.a = 2.0f;

	std::cout << u.a << ", " << u.b << std::endl;

	/* useful use of union*/
	Vector4 vector = {1.0f, 2.0f, 3.0f, 4.0f};

	/* struct {float x, y, z, w;} �� struct {Vector2 a, b;}
	 * ���ù�ͬ���ڴ��С�͵�ַ������ζ�� float x, y ��Ӧ Vector2 a
	 * float z, w ��Ӧ Vector b
	 */

	printVector2(vector.a);
	printVector2(vector.b);
	vector.z = 500.0f;
	/* ������ z ����ӡ vector.b ʱֵ�ᷢ���仯*/
	std::cout << "----------------------" << std::endl;
	printVector2(vector.a);
	printVector2(vector.b);

	std::cin.get();
}
