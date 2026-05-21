#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "--- TEST 1: Form with invalid grades ---" << std::endl;
	try 
	{
		Form	tooHight("Contract A", 0, 50);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception captured: " << e.what() << std::endl;
	}

	try
	{
		Form	tooLow("Contract B", 151, 50);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception captured: " << e.what() << std::endl;
	}

	std::cout << "\n--- TEST 2: Successful signing ---" << std::endl;
	try
	{
		Bureaucrat	boss("Boss", 1);
		Form		tax("Tax declaration", 20, 45);

		std::cout << boss << std::endl;
		std::cout << tax << std::endl;

		boss.signForm(tax);
		std::cout << tax << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Unexpected error: " << e.what() << std::endl;
	}

	std::cout << "\n--- TEST 3: Signature failed (Grade too low) ---" << std::endl;
	try
	{
		Bureaucrat	intern("Intern", 150);
		Form		secretDefense("Greg's Grok account", 1, 1);

		std::cout << intern << std::endl;
		std::cout << secretDefense << std::endl;

		intern.signForm(secretDefense);
		std::cout << secretDefense << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Unexpected error: " << e.what() << std::endl;
	}

	std::cout << "\n--- TEST 4: Promotion allowing you to sign---" << std::endl;
	try
	{
		Bureaucrat	employee("Eliott", 11);
		Form		visa("Work Visa", 10, 10);

		std::cout << employee << std::endl;
		employee.signForm(visa);

		std::cout << "Promotion of " << employee.getName() << "..." << std::endl;
		employee.bePromoted();

		employee.signForm(visa);
		std::cout << visa << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Unexpected error: " << e.what() << std::endl;
	}
	return 0;
}