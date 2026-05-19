#ifndef Dog_HPP
# define Dog_HPP

# include "Animal.hpp"

class	Dog: public Animal
{
	private:

		Brain	*brain;

	public:

		Dog();
		Dog(const Dog &other);
		virtual ~Dog();

		Dog	&operator=(const Dog &other);
		virtual void	makeSound() const;
		Brain*	getBrain();
};

#endif