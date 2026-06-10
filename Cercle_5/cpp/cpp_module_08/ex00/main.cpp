#include "easyfind.hpp"

int main()
{
	std::vector<int>	v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	try
	{
		std::cout << "Search 2 in Vector: ";
		std::vector<int>::iterator i = ::easyfind(v, 2);
		std::cout << "Find (" << *i << ")" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "Search 2 in Vector: ";
		std::vector<int>::iterator i = ::easyfind(v, 10);
		std::cout << "Find (" << *i << ")" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::list<int>	l;

	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_back(50);
	l.push_back(100);
	
	try
	{
		std::cout << "Search 50 in List : ";
		std::list<int>::iterator i = ::easyfind(l, 50);
		std::cout << "Find (" << *i << ")" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "Search 50 in List : ";
		std::list<int>::iterator i = ::easyfind(l, 200);
		std::cout << "Find (" << *i << ")" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}