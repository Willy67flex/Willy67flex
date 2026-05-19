#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	std::cout << "==== CONSTRUCTION CHAINING ====" << std::endl;
	DiamondTrap	monster1("Minishell1");
	DiamondTrap	monster2("Minishell2");
	std::cout << std::endl;

	std::cout << "==== IDENTITY & INITIAL STATS ====" << std::endl;
	monster1.whoAmI();
	std::cout << monster1 << std::endl;
	std::cout << std::endl;

	std::cout << "==== HYBRID ABILITIES TEST ====" << std::endl;
	monster1.attack("Antoine"); 
	monster1.highFivesGuys();
	monster1.guardGate();
	std::cout << std::endl;

	std::cout << "==== DAMAGE & REPAIR TEST ====" << std::endl;
	monster1.takeDamage(80);
	std::cout << monster1 << std::endl;
	monster1.beRepaired(500);
	std::cout << monster1 << std::endl;
	std::cout << std::endl;

	std::cout << "==== ENERGY DEPLETION TEST ====" << std::endl;
	std::cout << "Monster1 vs 100 air-attacks..." << std::endl;
	for (int i = 0; i < 48; i++)
		monster1.attack("the air");
	std::cout << monster1 << std::endl;
	monster1.attack("Greg");
	monster1.beRepaired(1000);
	monster1.whoAmI();
	monster1.highFivesGuys();
	std::cout << monster1 << std::endl;
	std::cout << std::endl;

	std::cout << "==== DEATH TEST ====" << std::endl;
	monster2.takeDamage(1000);
	std::cout << monster2 << std::endl;
	monster2.highFivesGuys();
	monster2.whoAmI();
	std::cout << std::endl;

	{
		DiamondTrap original("Original");
		original.takeDamage(30);

		std::cout << "--- Copy ---" << std::endl;
		DiamondTrap copy(original);
		copy.whoAmI();
		std::cout << "Copy stats: " << copy << std::endl;

		std::cout << "--- Assignment ---" << std::endl;
		DiamondTrap assign("Temp");
		assign = original;
		assign.whoAmI();
		std::cout << "Assign stats: " << assign << std::endl;
	}

	std::cout << "\n==== FINAL DESTRUCTION (Ordre : Diamond -> Frag -> Scav -> Clap) ====" << std::endl;
	return 0;
}
