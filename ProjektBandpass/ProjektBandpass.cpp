
#include <iostream>
extern "C" int MyProc1(long long x, long long y);
extern "C" int AddNumbers(int x, int y);
int main(int argc, char* argv[])
{
	int x = 3, y = 4, z = 0;

	z = MyProc1(x, y);		
	int a = AddNumbers(x, y);
	std::cout << "C++: " << a << std::endl << "Asembler: " << z << std::endl;
	return 0;
}

