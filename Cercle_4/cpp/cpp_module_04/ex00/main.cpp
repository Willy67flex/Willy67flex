#include "Animal/Animal.hpp"
#include "Animal/Cat.hpp"
#include "Animal/Dog.hpp"
#include "WrongAnimal/WrongAnimal.hpp"
#include "WrongAnimal/WrongCat.hpp"
#include "WrongAnimal/WrongDog.hpp"

int main()
{
	std::cout << "--- 1. Subject test (Polymorphisme) ---" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "Type Dog : " << j->getType() << " " << std::endl;
	std::cout << "Type Cat  : " << i->getType() << " " << std::endl;
	
	std::cout << "Sound of the Cat: ";
	i->makeSound();
	std::cout << "Sound of the Dog: ";
	j->makeSound();
	std::cout << "Sound of the Animal: ";
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << "\n--- 2. Stack test ---" << std::endl;
	{
		Dog doggy;
		Cat catty;
		std::cout << "Name: " << doggy.getType() << " | Sound: ";
		doggy.makeSound();
		std::cout << "Name: " << catty.getType() << " | Sound: ";
		catty.makeSound();
	}

	std::cout << "\n--- 3. Copy constructor test ---" << std::endl;
	{
		Dog originalDog;
		Dog copyDog(originalDog);
		
		std::cout << "Original Type: " << originalDog.getType() << std::endl;
		std::cout << "Copy Type: " << copyDog.getType() << std::endl;
		
		Cat originalCat;
		Cat assignCat;
		assignCat = originalCat;
		std::cout << "Assign Type: " << assignCat.getType() << std::endl;
	}

	std::cout << "\n--- 4. Wrong animal test ---" << std::endl;
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;
	std::cout << "WrongCat sound: ";
	wrongCat->makeSound();
	std::cout << "WrongAnimal sound: ";
	wrongMeta->makeSound();

	delete wrongMeta;
	delete wrongCat;

	return 0;
}
