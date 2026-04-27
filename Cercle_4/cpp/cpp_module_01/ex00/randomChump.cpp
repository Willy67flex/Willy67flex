#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie zombie(name);
	std::cout << "Zombie " << name << " is created" << std::endl;
	zombie.announce();
}
