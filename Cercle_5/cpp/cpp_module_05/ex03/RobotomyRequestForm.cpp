#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
	*this = other;
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

void	RobotomyRequestForm::action() const
{
	int	random = (rand() % 2);

	std::cout << "PPPRRRRPPPPPRRRRRR" << std::endl;
	if (random == 1)
		std::cout << "The robotization of \"" << _target << "\" was successful" << std::endl;
	else
		std::cout << "The robotization of \"" << _target << "\" failed" << std::endl;
}
