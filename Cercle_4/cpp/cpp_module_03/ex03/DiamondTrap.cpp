#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) 
	: ClapTrap(name + "_clap_name"),
	ScavTrap(name),
	FragTrap(name)
{
	_name = name;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 30;
	maxHitPoint = hitPoints;

	std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) 
	: ClapTrap(other),
	ScavTrap(other),
	FragTrap(other)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = other;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "DiamondTrap assignment operator called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		ClapTrap::_name = other.ClapTrap::_name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return *this;
}

void	DiamondTrap::whoAmI()
{
	if (hitPoints <= 0)
	{
		std::cout << _name << " is dead and cannot know who he is" << std::endl;
		return ;
	}
	std::cout << "I am " << this->_name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}
