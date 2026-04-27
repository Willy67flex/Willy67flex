#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void	randomChump(std::string name);

int	main()
{
	Zombie *ptr = newZombie("Eliott");
	ptr->announce();
	randomChump("Greg");
	delete ptr;
	return 0;
}
