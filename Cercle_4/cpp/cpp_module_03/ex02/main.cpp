#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	std::cout << "==== CONSTRUCTION CHAINING ====" << std::endl;
	ClapTrap	eliott("Eliott");
	std::cout << std::endl;
	ScavTrap	greg("Greg");
	std::cout << std::endl;
	FragTrap	*antoine = new FragTrap("Antoine");
	std::cout << std::endl;

	std::cout << "==== CLAPTRAP SECTION ====" << std::endl;
	eliott.attack("a gnat");
	std::cout << eliott << std::endl;
	eliott.takeDamage(5);
	std::cout << eliott << std::endl;
	eliott.beRepaired(100);
	std::cout << eliott << std::endl;
	std::cout << "\n" << std::endl;

	std::cout << "==== SCAVTRAP SECTION ====" << std::endl;
	std::cout << greg << std::endl;
	greg.attack("Git with a --force cmd");
	std::cout << greg << std::endl;
	greg.takeDamage(1000);
	std::cout << greg << std::endl;
	greg.guardGate();
	greg.beRepaired(10);
	greg.attack("nothing");
	std::cout << greg << std::endl;
	std::cout << "\n" << std::endl;

	std::cout << "==== FRAGTRAP SECTION ====" << std::endl;
	std::cout << *antoine << std::endl;
	antoine->highFivesGuys();
	std::cout << "Antoine vs 101 minishells (Energy depletion test)" << std::endl;
	for (int i = 0; i < 101; i++)
		antoine->attack("minishell");
	
	std::cout << *antoine << std::endl;
	antoine->highFivesGuys();
	antoine->takeDamage(70);
	antoine->beRepaired(100);
	std::cout << *antoine << std::endl;
	
	std::cout << "\n" << std::endl;
	delete antoine;
	std::cout << "\n" << std::endl;

	{
		FragTrap master("Master");
		master.takeDamage(30);

		std::cout << "--- Copy Constructor ---" << std::endl;
		FragTrap copy(master);
		std::cout << "Copy: " << copy << std::endl;

		std::cout << "--- Assignment Operator ---" << std::endl;
		FragTrap assign("Temp");
		assign = master;
		std::cout << "Assign: " << assign << std::endl;
	}

	std::cout << "\n==== FINAL DESTRUCTION ====" << std::endl;
	return 0;
}
