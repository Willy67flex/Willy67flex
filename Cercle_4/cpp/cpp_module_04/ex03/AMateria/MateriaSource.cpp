#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_learnedMaterias[i] = NULL;
	std::cout << "MateriaSource constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_learnedMaterias[i] = NULL;
	*this = other;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_learnedMaterias[i])
				delete this->_learnedMaterias[i];
			this->_learnedMaterias[i] = NULL;
			if (other._learnedMaterias[i])
				this->_learnedMaterias[i] = other._learnedMaterias[i]->clone();
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++) 
	{
		if (this->_learnedMaterias[i])
			delete this->_learnedMaterias[i];
	}
	std::cout << "MateriaSource destructor called" << std::endl;
}

void	MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (_learnedMaterias[i] == NULL)
		{
			_learnedMaterias[i] = m;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++) 
		if (_learnedMaterias[i] != NULL && _learnedMaterias[i]->getType() == type) 
			return _learnedMaterias[i]->clone();
	return 0;
}
