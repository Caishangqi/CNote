#include <iostream>
#include <string>
#include <vector>

struct Vertex
{
	float x, y, z;
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
	/* add something*/
	vertices.push_back({1, 2, 3});
	vertices.push_back({4, 5, 6});

	/* iteratate */
	for (int i = 0; i < vertices.size(); i++)
		std::cout << vertices[i] << std::endl;

	/* erase the second element
	 * 需要传一个 iteritator
	 */
	vertices.erase(vertices.begin() + 1);
	/* iteratate with stop copying*/
	for ( const Vertex& v : vertices)
		std::cout << v << std::endl;

	/* clean the vertices */
	vertices.clear();

	std::cin.get();
}
