#include "AAnimal/AAnimal.hpp"
#include "AAnimal/Cat.hpp"
#include "AAnimal/Dog.hpp"
#include "WrongAnimal/WrongAnimal.hpp"
#include "WrongAnimal/WrongCat.hpp"
#include "WrongAnimal/WrongDog.hpp"

int main()
{
	// AAnimal test;
	// AAnimal* meta = new AAnimal();

	std::cout << "\n--- 1. SUBJECT TEST (TABLE)---" << std::endl;
	const int size = 4;
	AAnimal* animals[size];

	for (int i = 0; i < size; i++)
	{
		if (size > 0 && i < size / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << "\n--- DISPLAYING SOUNDS ---" << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << animals[i]->getType() << " said : ";
		animals[i]->makeSound();
	}

	std::cout << "\n--- 2. TEST DEEP COPY ---" << std::endl;
	Dog* dog1 = new Dog();
	dog1->getBrain()->setIdea(0, "Running after the ball");
	
	Dog* dog2 = new Dog(*dog1);
	
	std::cout << "Dog1 idea 0: " << dog1->getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog2 idea 0: " << dog2->getBrain()->getIdea(0) << std::endl;

	std::cout << "\nEditing dog1..." << std::endl;
	dog1->getBrain()->setIdea(0, "Sleeping on the sofa");

	std::cout << "Dog1 idea 0(apres modif): " << dog1->getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog2 idea 0(doit rester inchangee): " << dog2->getBrain()->getIdea(0) << std::endl;

	std::cout << "\n--- 3. GENERAL CLEANING ---" << std::endl;
	
	std::cout << "Removal of the animal display:" << std::endl;
	for (int i = 0; i < size; i++)
	{
		delete animals[i];
	}

	std::cout << "\nRemoval of test dogs:" << std::endl;
	delete dog1;
	delete dog2;

	return 0;
}
