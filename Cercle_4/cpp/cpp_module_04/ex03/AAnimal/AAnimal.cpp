#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
	*this = other;
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal	&AAnimal::operator=(const AAnimal &other)
{
	type = other.type;
	return *this;
}

std::string	AAnimal::getType() const
{
	return type;
}

// void	AAnimal::makeSound() const
// {
// 	std::cout << "AAnimal sound" << std::endl;
// }
