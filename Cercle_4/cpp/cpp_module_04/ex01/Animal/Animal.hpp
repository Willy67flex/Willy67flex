#ifndef Animal_HPP
# define Animal_HPP

# include <iostream>
# include "../Brain/Brain.hpp"

class Animal
{
	protected:

		std::string	type;

	public:

		Animal();
		Animal(const Animal &other);
		virtual ~Animal();

		Animal				&operator=(const Animal &other);
		virtual void	makeSound() const;
		std::string		getType() const;
};

#endif