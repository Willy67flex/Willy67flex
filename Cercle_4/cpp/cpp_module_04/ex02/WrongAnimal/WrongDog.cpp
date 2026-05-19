#include "WrongDog.hpp"

WrongDog::WrongDog() : WrongAnimal()
{
	type = "WrongDog";
	std::cout << "WrongDog constructor called" << std::endl;
}

WrongDog::WrongDog(const WrongDog &other) : WrongAnimal(other)
{
	*this = other;
	std::cout << "WrongDog copy constructor called" << std::endl;
}

WrongDog::~WrongDog()
{
	std::cout << "WrongDog destructor called" << std::endl;
}

WrongDog	&WrongDog::operator=(const WrongDog &other)
{
	type = other.type;
	return *this;
}

void	WrongDog::makeSound() const
{
	std::cout << "Wouf" << std::endl;
}
