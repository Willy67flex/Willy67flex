#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>
#include "Intern.hpp"

int main()
{
	srand(time(NULL));

	std::cout << "--- STEP 1: The Staff Arrives ---" << std::endl;
	Intern someRandomIntern;
	Bureaucrat boss("The Boss", 1);
	Bureaucrat slave("The slave", 150);
	Bureaucrat manager("The Manager", 45);
	std::cout << std::endl;

	AForm* forms[4];

	std::cout << "--- STEP 2: The Intern at Work ---" << std::endl;
	forms[0] = someRandomIntern.makeForm("shrubbery creation", "Garden");
	forms[1] = someRandomIntern.makeForm("robotomy request", "Bender");
	forms[2] = someRandomIntern.makeForm("presidential pardon", "Luffy");
	forms[3] = someRandomIntern.makeForm("coffee request", "Intern");
	std::cout << std::endl;

	std::cout << "--- STEP 3: Trying to execute unsigned forms ---" << std::endl;
	if (forms[0])
		boss.executeForm(*forms[0]);
	std::cout << std::endl;

	std::cout << "--- STEP 4: The Signing Process ---" << std::endl;
	if (forms[0])
		slave.signAForm(*forms[0]);
	
	if (forms[0])
		manager.signAForm(*forms[0]);
	if (forms[1])
		manager.signAForm(*forms[1]);

	if (forms[2])
		boss.signAForm(*forms[2]);
	std::cout << std::endl;

	std::cout << "--- STEP 5: Execution Day ---" << std::endl;
	
	std::cout << "[ Test Shrubbery (Manager grade 45 vs Exec 137) ]" << std::endl;
	if (forms[0]) 
		manager.executeForm(*forms[0]);

	std::cout << "\n[ Test Robotomy (Manager grade 45 vs Exec 45) ]" << std::endl;
	if (forms[1])
		manager.executeForm(*forms[1]);
	if (forms[1])
		manager.executeForm(*forms[1]);

	std::cout << "\n[ Test Presidential Pardon (Manager grade 45 vs Exec 5) ]" << std::endl;
	if (forms[2])
		manager.executeForm(*forms[2]);
	
	std::cout << "\n[ Test Presidential Pardon (Boss grade 1 vs Exec 5) ]" << std::endl;
	if (forms[2])
		boss.executeForm(*forms[2]);
	std::cout << std::endl;

	std::cout << "--- STEP 6: Cleaning the Office ---" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (forms[i])
		{
			delete forms[i];
		}
	}

	std::cout << "\n--- END OF TESTS ---" << std::endl;
	return 0;
}
