#include <iostream>
#include <string>


struct Vector2
{
	float x, y;

	Vector2(float x, float y) : x(x), y(y)
	{
	}

	/* ������ӣ����޸�ԭ����Ա�����������Ժ����� const
	 * Ϊ�˽�ʡ���ܲ����¿�����������������
	 */
	Vector2 add(const Vector2& other) const
	{
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 multiply(const Vector2& other) const
	{
		return Vector2(x * other.x, y * other.y);
	}

	/*ʹ�ò���������*/
	Vector2 operator+(const Vector2& other) const
	{
		return add(other);
	}

	Vector2 operator*(const Vector2& other) const
	{
		return multiply(other);
	}
	/*��д << ����*/
	std::ostream& operator<<(std::ostream& stream, const Vector2& other) const
	{
		stream << other.x << ", " << other.y;
		return stream;
	}
	/*��д == ����*/
	bool operator==(const Vector2& other) const
	{
		return x == other.x && y == other.y;
	}

	/*��д != ����*/
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

	/*���԰�2������������ Java Ψһд������Ϊ��֧�� ����������*/
	Vector2 result = position.add(speed.multiply(powerup));

	/*����������*/
	Vector2 result_with_operator = position + speed * powerup;

	/*������ << ���� ?*/
	std::cout << result_with_operator << std::endl;

	std::cin.get();
}
