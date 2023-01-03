#include "pch.h"
/* turn pch.h to precompile headers
 * - first make a pch.cpp and include pch.h
 * - in pch.cpp, setting - property - C/C++ - precompiled Headers
 *	 - Create (/Yc) - Precompiled Header File pch.h
 * - in project, setting - property - C/C++ - precompiled Headers - use precompiled header
 */

int main(int argc, char* argv[])
{
	std::cout << "Hello precompile\n";
}
