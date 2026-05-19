#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(std::string name) : _name(name)
{
	std::cout << "Character constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character &other) : _name(other._name)
{
	std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	*this = other;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (_inventory[i] != NULL)
			delete _inventory[i];
	std::cout << "Character destructor called" << std::endl;
}

Character	&Character::operator=(const Character &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
		for (int i = 0; i < 4; i++)
		{
			if (other._inventory[i])
				this->_inventory[i] = other._inventory[i]->clone();
		}
	}
	return *this;
}

std::string const	&Character::getName() const
{
	return _name;
}

void	Character::equip(AMateria* m)
{
	if (!m) 
		return;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			return;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3)
		_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 3)
	{
		if (_inventory[idx] != NULL)
			_inventory[idx]->use(target);
	}
}

AMateria*	Character::getMateria(int idx) const
{
	if (idx >= 0 && idx <=3)
		return _inventory[idx];
	return NULL;
}
