#include "Animal/Animal.hpp"
#include "Animal/Cat.hpp"
#include "Animal/Dog.hpp"
#include "WrongAnimal/WrongAnimal.hpp"
#include "WrongAnimal/WrongCat.hpp"
#include "WrongAnimal/WrongDog.hpp"

int main()
{
	const int size = 4;
	Animal* animals[size];

	std::cout << "--- TABLE CONSTRUCTOR ---" << std::endl;
	for (int i = 0; i < size; i++)
	{
		if (i < size / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << "--- REAL BRAIN TEST ---" << std::endl;
	Dog dog1;
	dog1.getBrain()->setIdea(0, "I'm hungry");
	dog1.getBrain()->setIdea(1, "I want a bone");
	std::cout << std::endl;

	Dog dog2 = dog1;
	std::cout << std::endl;

	std::cout << "dog2 idea 0 : " << dog2.getBrain()->getIdea(0) << std::endl;
	std::cout << "dog2 idea 1 : " << dog2.getBrain()->getIdea(1) << std::endl;
	std::cout << std::endl;

	dog1.getBrain()->setIdea(0, "I want to sleep");
	std::cout << std::endl;

	std::cout << "After modifying dog1..." << std::endl;
	std::cout << "dog1 idea 0 : " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "dog2 idea 0 : " << dog2.getBrain()->getIdea(0) << std::endl;

	std::cout << "\n--- TABLE DESTRUCTOR ---" << std::endl;
	for (int i = 0; i < size; i++) {
		delete animals[i];
	}

	return 0;
}
