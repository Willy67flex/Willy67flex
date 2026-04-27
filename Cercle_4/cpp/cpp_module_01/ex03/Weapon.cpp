#include "Weapon.hpp"

Weapon::Weapon(std::string type): _type(type)
{
	std::cout << "Weapon constructor called" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Weapon destructor called" << std::endl;
}

std::string&	Weapon::getType()
{
	return _type;
}

void	Weapon::setType(std::string type)
{
	_type = type;
}
