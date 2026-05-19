#ifndef WrongDog_HPP
# define WrongDog_HPP

# include "WrongAnimal.hpp"

class	WrongDog: public WrongAnimal
{
	public:

		WrongDog();
		WrongDog(const WrongDog &other);
		~WrongDog();

		WrongDog	&operator=(const WrongDog &other);
		void	makeSound() const;
};

#endif