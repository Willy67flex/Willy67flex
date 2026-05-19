#include "Cat.hpp"

Cat::Cat() : Animal()
{
	type = "Cat";
	brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	brain = new Brain();
	*this = other;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other) 
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		if (this->brain)
			if (other.brain) *this->brain = *other.brain;
	}
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Miaou" << std::endl;
}

Brain*	Cat::getBrain()
{
	return brain;
}
