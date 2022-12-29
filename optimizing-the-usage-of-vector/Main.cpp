#include <iostream>
#include <string>
#include <vector>

struct Vertex
{
	float x, y, z;

	Vertex(float x, float y, float z) : x(x), y(y), z(z)
	{
	}

	/* 拷贝构造函数，在我们拷贝对象时调用，自定义的深度拷贝*/
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

	/* 优化 - 1 我们可以告诉vertices我们要3个空位来避免到达满值时的复制操作*/
	vertices.reserve(3);

	/* add something*/
	/* Copied x 1
	 * 当我们构建Vertex时我们其实在当前 main 的 stack frame中 创建的
	 * 我们需要把在main stack frame的Vertex塞到 vertices 分配的内存里面
	 * 我们复制main函数里面的Vertex到 vertices里面所以进行了第一次拷贝
	 */
	vertices.push_back(Vertex(1, 2, 3));

	/* 优化 - 2 我们可以直接让Vertex在 vertices里创建避免额外的复制
	 * emplace_back 可以直接使用构造器的参数列表 同时告诉 vertices
	 * 使用当前的参数创建Vertex对象然后直接放进vertices的内存中
	 */
	vertices.emplace_back(4, 5, 6);

	/* 默认无优化*/
	vertices.push_back(Vertex(7, 8, 9));

	/* 结果调用了 2 次复制构造函数 - 两次 push_back*/
	std::cin.get();
}
