#ifndef MateriaSource_HPP
# define MateriaSource_HPP

#include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource
{
	private:

		AMateria	*_learnedMaterias[4];

	public:

	MateriaSource();
	MateriaSource(const MateriaSource &other);
	~MateriaSource();

	MateriaSource	&operator=(const MateriaSource &other);

	virtual void		learnMateria(AMateria *m);
	virtual AMateria*	createMateria(std::string const &type);

};

#endif