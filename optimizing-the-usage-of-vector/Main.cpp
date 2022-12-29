#include <iostream>
#include <string>
#include <vector>

struct Vertex
{
	float x, y, z;

	Vertex(float x, float y, float z) : x(x), y(y), z(z)
	{
	}

	/* �������캯���������ǿ�������ʱ���ã��Զ������ȿ���*/
	Vertex(const Vertex& vertex) : x(vertex.x), y(vertex.y), z(vertex.z)
	{
		std::cout << "Copied" << std::endl;
	}
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
	stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
	return stream;
}

int main(int argc, char* argv[])
{
	/* we can use primitive type of data too*/
	std::vector<Vertex> vertices;

	/* �Ż� - 1 ���ǿ��Ը���vertices����Ҫ3����λ�����⵽����ֵʱ�ĸ��Ʋ���*/
	vertices.reserve(3);

	/* add something*/
	/* Copied x 1
	 * �����ǹ���Vertexʱ������ʵ�ڵ�ǰ main �� stack frame�� ������
	 * ������Ҫ����main stack frame��Vertex���� vertices ������ڴ�����
	 * ���Ǹ���main���������Vertex�� vertices�������Խ����˵�һ�ο���
	 */
	vertices.push_back(Vertex(1, 2, 3));

	/* �Ż� - 2 ���ǿ���ֱ����Vertex�� vertices�ﴴ���������ĸ���
	 * emplace_back ����ֱ��ʹ�ù������Ĳ����б� ͬʱ���� vertices
	 * ʹ�õ�ǰ�Ĳ�������Vertex����Ȼ��ֱ�ӷŽ�vertices���ڴ���
	 */
	vertices.emplace_back(4, 5, 6);

	/* Ĭ�����Ż�*/
	vertices.push_back(Vertex(7, 8, 9));

	/* ��������� 2 �θ��ƹ��캯�� - ���� push_back*/
	std::cin.get();
}
