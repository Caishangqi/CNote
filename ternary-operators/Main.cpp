#include <iostream>
#include <string>

static int s_Level = 1;
static int s_Speed = 2;

int main(int argc, char* argv[])
{
	if (s_Level > 5)
		s_Speed = 10;
	else
		s_Speed = 5;

	s_Speed = s_Level > 5 ? 10 : 5;

	s_Speed = s_Level > 5 ? s_Level > 10 ? 15 : 10 : 5;

	std::cin.get();
}
