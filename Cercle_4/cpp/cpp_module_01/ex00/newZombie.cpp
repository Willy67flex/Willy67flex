#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
	Zombie *ptr = new Zombie(name);
	std::cout << "Zombie " << name << " is created" << std::endl;
	return ptr;
}
