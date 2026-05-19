#ifndef Cat_HPP
# define Cat_HPP

# include "Animal.hpp"

class	Cat: public Animal
{
	public:

		Cat();
		Cat(const Cat &other);
		virtual ~Cat();

		Cat	&operator=(const Cat &other);
		virtual void	makeSound() const;
};

#endif