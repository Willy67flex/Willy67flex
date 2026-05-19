#ifndef DiamondTrap_HPP
# define DiamondTrap_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:

		std::string	_name;

	public:

		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &other);
		~DiamondTrap();

		DiamondTrap	&operator=(const DiamondTrap &other);

		using ScavTrap::attack;
		void	whoAmI();
};

#endif
