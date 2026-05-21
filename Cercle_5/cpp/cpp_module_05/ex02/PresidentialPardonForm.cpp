#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{
	*this = other;
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

void	PresidentialPardonForm::action() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
