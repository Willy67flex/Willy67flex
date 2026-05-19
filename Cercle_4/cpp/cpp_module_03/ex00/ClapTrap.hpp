#ifndef ClapTrap_HPP
# define ClapTrap_HPP

# include <iostream>

class ClapTrap
{
	private:

	std::string	_name;
	int			hitPoints;
	int			energyPoints;
	int			attackDamage;
	int			maxHitPoint;

	public:

	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &other);
	~ClapTrap();

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	std::string	getName() const;
	int			getHitPoints() const;
	int			getenergyPoints() const;
	ClapTrap	&operator=(const ClapTrap &other);
	
};

std::ostream &operator<<(std::ostream &output, ClapTrap const &ClapTrap);

#endif