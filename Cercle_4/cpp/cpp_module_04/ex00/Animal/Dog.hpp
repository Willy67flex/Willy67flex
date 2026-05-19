#ifndef Dog_HPP
# define Dog_HPP

# include "Animal.hpp"

class	Dog: public Animal
{
	public:

		Dog();
		Dog(const Dog &other);
		virtual ~Dog();

		Dog	&operator=(const Dog &other);
		virtual void	makeSound() const;
};

#endif