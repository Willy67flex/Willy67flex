#include "iter.hpp"

void incrementInt(int &n)
{
	n++;
}

template <typename T>

void printElement(T const &x)
{
	std::cout << x << " ";
}

void myToUpper(char &c)
{
	c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
}

int main()
{
	int tab[] = {0, 1, 2, 3, 4};
	std::cout << "Basic int array : ";
	::iter(tab, 5, printElement<int>);
	std::cout << std::endl;
	::iter(tab, 5, incrementInt);
	std::cout << "Int array after iter : ";
	::iter(tab, 5, printElement<int>);
	std::cout << "\n\n";

	std::string strings[] = {"One", "Two", "Three"};
	std::cout << "Str array : ";
	::iter(strings, 3, printElement<std::string>);
	std::cout << "\n\n";

	char charArray[5] = {'a', 'b', 'c', 'd', 'e'};
	std::cout << "Basic char array : ";
	::iter(charArray, 5, printElement<char>);
	std::cout << std::endl;
	::iter(charArray, 5, myToUpper);
	std::cout << "Char array after iter : ";
	::iter(charArray, 5, printElement<char>);
	std::cout << "\n\n";

	const int constTab[] = {10, 20, 30};
	std::cout << "Const array : ";
	::iter(constTab, 3, printElement<int>);
	std::cout << std::endl;

	return 0;
}
