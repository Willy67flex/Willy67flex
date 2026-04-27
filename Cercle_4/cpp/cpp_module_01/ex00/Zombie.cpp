#include "Zombie.hpp"

Zombie::Zombie(std::string name)
	: _name(name)
{
	std::cout << "Zombie constructor called" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << _name << " is dead" << std::endl;
}

void	Zombie::announce()
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
