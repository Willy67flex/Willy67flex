#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), hitPoints(10), energyPoints(10), attackDamage(0), maxHitPoint(hitPoints)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Default destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
	std::cout << "Copy contructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		_name = other._name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return *this;
}

std::string	ClapTrap::getName() const
{
	return _name;
}

int	ClapTrap::getHitPoints() const
{
	return hitPoints;
}

int	ClapTrap::getenergyPoints() const
{
	return energyPoints;
}

std::ostream &operator<<(std::ostream &output, ClapTrap const &ClapTrap)
{
	output << ClapTrap.getName() << " has " << ClapTrap.getHitPoints() 
		   << " lives and " << ClapTrap.getenergyPoints() << " energy.";
	return output;
}

void	ClapTrap::attack(const std::string& target)
{
	if (hitPoints > 0 && energyPoints > 0)
	{
		energyPoints--;
		std::cout << _name << " attacks " << target << ", causing " 
				  << attackDamage << " points of damage!" << std::endl;
		return ;
	}
	std::cout << _name << " can't do anything (not enough energy or he's dead)" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints > 0)
	{
		hitPoints -= amount;
		if (hitPoints < 0)
			hitPoints = 0;
		std::cout << _name << " takes " << amount << " points of damage!" << std::endl;
		return ;
	}
	std::cout << _name << " can't do anything (not enough energy or he's dead)" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints > 0 && energyPoints > 0)
	{
		hitPoints += amount;
		if (hitPoints > maxHitPoint)
			hitPoints = maxHitPoint;
		energyPoints--;
		std::cout << _name << " repairs itself, regaining " << amount << " hit points" << std::endl;
		return ;
	}
	std::cout << _name << " can't do anything (not enough energy or he's dead)" << std::endl;
}
