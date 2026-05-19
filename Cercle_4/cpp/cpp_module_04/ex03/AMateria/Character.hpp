#ifndef Character_HPP
# define Character_HPP

#include "ICharacter.hpp"

class	Character : public ICharacter
{
	private:

		std::string	_name;
		AMateria	*_inventory[4];
	
	public:

		Character(std::string name);
		Character(const Character &other);
		virtual ~Character();

		Character	&operator=(const Character &other);

		std::string	const	&getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
		AMateria*			getMateria(int idx) const;
};

#endif