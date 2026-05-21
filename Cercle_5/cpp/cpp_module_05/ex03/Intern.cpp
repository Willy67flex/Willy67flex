#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	actionTable[0] = "presidential pardon";
	actionTable[1] = "robotomy request";
	actionTable[2] = "shrubbery creation";
	std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
	*this = other;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern	&Intern::operator=(const Intern &other)
{
	for (int i = 0; i < 3; i++)
		actionTable[i] = other.actionTable[i];
	return *this;
}

AForm	*Intern::createPresidential(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::createRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::createShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeForm(std::string action, std::string target)
{
	AForm* (Intern::*fonctions[])(std::string) = {&Intern::createPresidential, &Intern::createRobotomy, &Intern::createShrubbery};
	for (int i = 0; i < 3; i++)
	{
		if (actionTable[i] == action)
		{
			std::cout << "Intern creates " << action << std::endl;
			return (this->*fonctions[i])(target);
		}
	}
	std::cout << "Error: Intern cannot create '" << action << "' because it's unknown." << std::endl;
	return NULL;
}
