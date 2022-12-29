#include <iostream>
#include <string>


struct Vector2
{
	float x, y;

	Vector2(float x, float y) : x(x), y(y)
	{
	}

	/* 向量相加，不修改原本成员变量内容所以函数用 const
	 * 为了节省性能不重新拷贝向量所以用引用
	 */
	Vector2 add(const Vector2& other) const
	{
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 multiply(const Vector2& other) const
	{
		return Vector2(x * other.x, y * other.y);
	}

	/*使用操作符重载*/
	Vector2 operator+(const Vector2& other) const
	{
		return add(other);
	}

	Vector2 operator*(const Vector2& other) const
	{
		return multiply(other);
	}
	/*重写 << 符号*/
	std::ostream& operator<<(std::ostream& stream, const Vector2& other) const
	{
		stream << other.x << ", " << other.y;
		return stream;
	}
	/*重写 == 符号*/
	bool operator==(const Vector2& other) const
	{
		return x == other.x && y == other.y;
	}

	/*重写 != 符号*/
	bool operator!=(const Vector2& other) const
	{
		return !(*this == other);
	}

};

int main(int argc, char* argv[])
{
	Vector2 position = Vector2(4.0f, 4.0f);
	Vector2 speed = Vector2(0.5f, 1.5f);
	Vector2 powerup = Vector2(1.1f, 1.1f);

	/*尝试把2个向量加起来 Java 唯一写法，因为不支持 操作符重载*/
	Vector2 result = position.add(speed.multiply(powerup));

	/*操作符重载*/
	Vector2 result_with_operator = position + speed * powerup;

	/*操作符 << 重载 ?*/
	std::cout << result_with_operator << std::endl;

	std::cin.get();
}
