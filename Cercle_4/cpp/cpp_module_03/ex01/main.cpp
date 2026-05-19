#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap	eliott("Eliott");
	ScavTrap	greg("Greg");
	ScavTrap	*ptr = new ScavTrap("Antoine");

	std::cout << "\n" << std::endl;
	eliott.attack("a gnat");
	std::cout << eliott << std::endl;
	eliott.takeDamage(5);
	std::cout << eliott << std::endl;
	eliott.beRepaired(100);
	std::cout << eliott << std::endl;

	std::cout << "\n\n" << std::endl;
	std::cout << greg << std::endl;
	greg.attack("Git with a --force cmd");
	std::cout << greg << std::endl;
	greg.takeDamage(1000);
	std::cout << greg << std::endl;
	greg.guardGate();
	greg.beRepaired(10);
	greg.attack("nothing");
	std::cout << greg << std::endl;

	std::cout << *ptr << std::endl;
	ptr->guardGate();
	for (int i = 0; i < 50; i++)
		ptr->attack("minishell");
	std::cout << *ptr << std::endl;
	ptr->takeDamage(70);
	ptr->beRepaired(100);
	std::cout << *ptr << std::endl;
	delete	ptr;

	return 0;
}
