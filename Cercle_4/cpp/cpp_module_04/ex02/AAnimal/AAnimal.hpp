#ifndef AAnimal_HPP
# define AAnimal_HPP

# include <iostream>
# include "../Brain/Brain.hpp"

class AAnimal
{
	protected:

		std::string	type;

	public:

		AAnimal();
		AAnimal(const AAnimal &other);
		virtual ~AAnimal();

		AAnimal				&operator=(const AAnimal &other);
		virtual void	makeSound() const = 0;
		std::string		getType() const;
};

#endif