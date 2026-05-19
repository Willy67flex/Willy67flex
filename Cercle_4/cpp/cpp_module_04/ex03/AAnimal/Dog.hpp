#ifndef Dog_HPP
# define Dog_HPP

# include "AAnimal.hpp"

class	Dog: public AAnimal
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