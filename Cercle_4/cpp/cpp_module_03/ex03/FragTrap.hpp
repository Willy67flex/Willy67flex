#ifndef FragTrap_HPP
# define FragTrap_HPP

#include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(std::string name);
		FragTrap(const FragTrap &other);
		~FragTrap();

		FragTrap	&operator=(const FragTrap &other);
		
		void	highFivesGuys(void);

};

#endif