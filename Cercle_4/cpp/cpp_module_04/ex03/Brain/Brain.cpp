#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain consructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	*this = other;
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain	&Brain::operator=(const Brain &other)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
	return *this;
}

void	Brain::setIdea(int i, std::string idea)
{
	ideas[i] = idea;
	std::cout << "The idea |" << idea << "| is set at index " << i << std::endl;
}

std::string	Brain::getIdea(int i)
{
	return ideas[i];
}
