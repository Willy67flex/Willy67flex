#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
	srand(time(NULL));

	std::cout << "===== TEST 1: The levels of the hierarchy =====" << std::endl;
	Bureaucrat boss("The boss", 1);
	Bureaucrat manage("The manage", 40);
	Bureaucrat Intern("The Intern", 150);

	std::cout << boss << std::endl;
	std::cout << manage << std::endl;
	std::cout << Intern << std::endl;

	std::cout << "\n===== TEST 2: Shrubbery Creation (Sign 145, Exec 137) =====" << std::endl;
	AForm* shrub = new ShrubberyCreationForm("garden");
	
	boss.executeForm(*shrub); 
	
	Intern.signAForm(*shrub);
	
	manage.signAForm(*shrub);
	manage.executeForm(*shrub);
	
	delete shrub;

	std::cout << "\n===== TEST 3: Robotomy Request (Sign 72, Exec 45) =====" << std::endl;
	AForm* robot = new RobotomyRequestForm("Bender");
	
	manage.signAForm(*robot);
	manage.executeForm(*robot);
	manage.executeForm(*robot);
	manage.executeForm(*robot);
	
	delete robot;

	std::cout << "\n===== TEST 4: Presidential Pardon (Sign 25, Exec 5) =====" << std::endl;
	AForm* pardon = new PresidentialPardonForm("Repentant Criminal");
	
	manage.signAForm(*pardon);
	
	boss.signAForm(*pardon);
	manage.executeForm(*pardon);
	
	boss.executeForm(*pardon);

	delete pardon;

	std::cout << "\n===== TEST 5: Test copy =====" << std::endl;
	{
		PresidentialPardonForm original("Prisoner A");
		boss.signAForm(original);
		
		PresidentialPardonForm copy(original);
		std::cout << "Copy status: " << copy << std::endl;
		boss.executeForm(copy);
	}

	std::cout << "\n===== END OF TESTS =====" << std::endl;
	return 0;
}