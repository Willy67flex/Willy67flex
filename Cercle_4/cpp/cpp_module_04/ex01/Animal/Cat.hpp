#ifndef Cat_HPP
# define Cat_HPP

# include "Animal.hpp"

class	Cat: public Animal
{
	private:

		Brain	*brain;

	public:

		Cat();
		Cat(const Cat &other);
		virtual ~Cat();

		Cat	&operator=(const Cat &other);
		virtual void	makeSound() const;
		Brain	*getBrain();
};

#endif