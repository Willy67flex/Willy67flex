#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	_weapon = NULL;
	std::cout << "HumanB constructor called" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB destructor called" << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}

void	HumanB::attack()
{
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
