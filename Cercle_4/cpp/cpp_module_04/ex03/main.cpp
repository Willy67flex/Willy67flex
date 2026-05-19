#include "AMateria/AMateria.hpp"
#include "AMateria/Character.hpp"
#include "AMateria/Cure.hpp"
#include "AMateria/Ice.hpp"
#include "AMateria/ICharacter.hpp"
#include "AMateria/IMateriaSource.hpp"
#include "AMateria/MateriaSource.hpp"

int main()
{
	// std::cout << "--- STEP 1: Creating the Source ---" << std::endl;
	// IMateriaSource* src = new MateriaSource();
	

	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());
	// std::cout << std::endl;

	// std::cout << "--- STEP 2: Character Creation and Overfilling ---" << std::endl;
	// Character* cloud = new Character("Cloud");

	// AMateria* tmp;
	// tmp = src->createMateria("ice");
	// cloud->equip(tmp);
	// tmp = src->createMateria("cure");
	// cloud->equip(tmp);
	// tmp = src->createMateria("ice");
	// cloud->equip(tmp);
	// tmp = src->createMateria("cure");
	// cloud->equip(tmp);

	// std::cout << "Attempting to equip a 5th item (should fail)..." << std::endl;
	// AMateria* extra = src->createMateria("ice");
	// cloud->equip(extra); 
	// delete extra; 
	// std::cout << std::endl;

	// std::cout << "--- STEP 3: Deep Copy Test ---" << std::endl;
	// Character* clone = new Character(*cloud);

	// std::cout << "Original (Cloud) uses slot 0: ";
	// cloud->use(0, *clone);
	// std::cout << "Clone uses slot 0: ";
	// clone->use(0, *cloud);

	// std::cout << "Modifying the clone's equipment..." << std::endl;
	
	// AMateria* dropped = clone->getMateria(0); 
	// clone->unequip(0);
	// delete dropped;
	
	// std::cout << "Cloud slot 0 after clone unequipped its own slot 0: ";
	// cloud->use(0, *clone);
	// std::cout << std::endl;

	// std::cout << "--- STEP 4: Assignment Operator Test ---" << std::endl;
	// Character* sephiroth = new Character("Sephiroth");
	// *sephiroth = *cloud;
	// std::cout << "Sephiroth (assigned from Cloud) uses slot 1: ";
	// sephiroth->use(1, *cloud);
	// std::cout << std::endl;

	// std::cout << "--- STEP 5: The Unequip Trap ---" << std::endl;
	// AMateria* floor_item = cloud->getMateria(1); 
	// cloud->unequip(1);
	
	// delete floor_item;
	// std::cout << "Unequipped slot 1 and deleted it manually." << std::endl;
	// std::cout << std::endl;

	// std::cout << "--- STEP 6: Final Cleanup ---" << std::endl;
	// delete cloud;
	// delete clone;
	// delete sephiroth;
	// delete src;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	std::cout << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << std::endl;

	delete bob;
	delete me;
	delete src;

	return 0;
}
