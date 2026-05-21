#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
	*this = other;
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

void	ShrubberyCreationForm::action() const
{
	std::string filename = _target + "_shrubbery";

	std::ofstream file(filename.c_str());

	if (!file)
	{
		std::cerr << "Failed to open file: " << filename << std::endl;
		return;
	}


    file << "      *      " << std::endl;
    file << "     /.\\     " << std::endl;
    file << "    /..'\\    " << std::endl;
    file << "    /'.'\\    " << std::endl;
    file << "   /.''.'\\   " << std::endl;
    file << "   /.'.'.\\   " << std::endl;
    file << "  /'.''.'.\\  " << std::endl;
    file << "  ^^^[_]^^^  " << std::endl;

	file.close();

	file.close();
}
