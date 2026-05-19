#include "Dog.hpp"

Dog::Dog() : AAnimal()
{
	type = "Dog";
	brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : AAnimal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->brain = new Brain();
	*this = other;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other) 
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		if (this->brain)
			if (other.brain) *this->brain = *other.brain;
	}
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Wouf" << std::endl;
}

Brain*	Dog::getBrain()
{
	return brain;
}
