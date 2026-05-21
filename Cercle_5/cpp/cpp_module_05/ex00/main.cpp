#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat	eliott("Eliott", 2);

		std::cout << eliott << std::endl;
		eliott.bePromoted();
		std::cout << eliott << std::endl;
		eliott.bePromoted();
		std::cout << eliott << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << std::endl;

	try
	{
		Bureaucrat	Low("Intern", 151);

		std::cout << Low << std::endl;
		Low.bePromoted();
		std::cout << Low << std::endl;
		Low.bePromoted();
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Bureaucrat	Hight("Big Boss", 0);

		Hight.beDemoted();
		std::cout << Hight << std::endl;
		Hight.beDemoted();
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Bureaucrat	gerg("Greg", 150);

		std::cout << gerg << std::endl;
		gerg.beDemoted();
		std::cout << gerg << std::endl;
	}
	catch (std::exception & e) 
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Bureaucrat	antoine("Antoine", 10);

		std::cout << antoine << std::endl;
		antoine.bePromoted();
		std::cout << antoine << std::endl;
		antoine.beDemoted();
		std::cout << antoine << std::endl;
		antoine.bePromoted();
		antoine.bePromoted();
		std::cout << antoine << std::endl;
	}
	catch (std::exception & e) 
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	

	return 0;
}