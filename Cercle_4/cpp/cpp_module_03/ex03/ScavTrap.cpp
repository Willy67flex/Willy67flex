#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	maxHitPoint = hitPoints;
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap Copy contructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}


ScavTrap	&ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap Assignation operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return *this;
}

void	ScavTrap::attack(const std::string& target)
{
	if (hitPoints > 0 && energyPoints > 0)
	{
		energyPoints--;
		std::cout << "Super " << _name << " attacks " << target << ", causing " 
				  << attackDamage << " points of damage!" << std::endl;
		return ;
	}
	std::cout << "Super " << _name << " can't do anything (not enough energy or he's dead)" << std::endl;
}

void	ScavTrap::guardGate()
{
	if (hitPoints <= 0)
	{
		std::cout << "Super " << _name << " can't do anything (he's dead)" << std::endl;
		return ;
	}
	std::cout << "Super " << _name << " is now in Gate keeper mode." << std::endl;
}

std::ostream &operator<<(std::ostream &output, ScavTrap const &ScavTrap)
{
	output << "Super " << ScavTrap.getName() << " has " << ScavTrap.getHitPoints()
		   << " lives and " << ScavTrap.getenergyPoints() << " energy" << std::endl;
	return output;
}

