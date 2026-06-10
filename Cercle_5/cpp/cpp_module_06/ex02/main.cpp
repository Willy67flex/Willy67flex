#include "Base.hpp"
#include <cstdlib>

int main()
{
	srand(time(NULL));

	for (int i = 1; i < 4; i++)
	{
		std::cout << "Test " << i << ": " << std::endl;
		Base *ptr = generate();
		std::cout << "By pointer: ";
		identify(ptr);
		std::cout << "By address: ";
		identify(*ptr);
		delete ptr;
		std::cout << std::endl;
	}
	return 0;
}
