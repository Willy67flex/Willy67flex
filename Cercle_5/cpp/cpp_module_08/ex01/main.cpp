#include "Span.hpp"

int main()
{
	std::cout << "--- Subject Test ---" << std::endl;
	try
	{
		Span	sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest:  " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n--- Exeption Test ---" << std::endl;
	try
	{
		Span	sp2 = Span(1);

		sp2.addNumber(42);
		std::cout << "Attempting a calculation with only one number..." << std::endl;
		sp2.shortestSpan(); 
	}
	catch (std::exception &e)
	{
		std::cerr << "Erreur : " << e.what() << std::endl;
	}

	try
	{
		Span	sp3 = Span(2);

		sp3.addNumber(1);
		sp3.addNumber(2);
		std::cout << "Attempting to add beyond the limit (N=2)..." << std::endl;
		sp3.addNumber(3);
	}
	catch (std::exception &e)
	{
		std::cerr << "Erreur : " << e.what() << std::endl;
	}

	std::cout << "\n--- Test addNumbers (Range) ---" << std::endl;
	try
	{
		std::vector<int>	v;

		v.push_back(100);
		v.push_back(200);
		v.push_back(300);
		v.push_back(400);

		Span	sp4(10);

		sp4.addNumber(50);
		sp4.addNumber(v.begin(), v.end());

		std::cout << "Size after addNumbers: 5 (Verified via longest: " << sp4.shortestSpan() << ")" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n--- Performence Test (20 000 nombres) ---" << std::endl;
	try
	{
		unsigned int		size = 20000;
		Span				bigSpan(size);
		std::vector<int>	bigVector;

		std::srand(std::time(0));
		for (unsigned int i = 0; i < size; i++)
			bigVector.push_back(std::rand());

		bigSpan.addNumber(bigVector.begin(), bigVector.end());

		std::cout << "Shortest: " << bigSpan.shortestSpan() << std::endl;
		std::cout << "Longest:  " << bigSpan.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n--- Deep Copy Test ---" << std::endl;
	Span	a(5);

	a.addNumber(1);
	a.addNumber(10);
	
	Span	b = a;
	
	b.addNumber(100);

	std::cout << "Longest Span A: " << a.longestSpan() << " (Should be 9)" << std::endl;
	std::cout << "Longest Span B: " << b.longestSpan() << " (Should be 99)" << std::endl;

	return 0;
}
