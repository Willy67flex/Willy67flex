#include "Array.hpp"

#define MAX_VAL 750

int main()
{
	std::cout << "--- Empty array Test ---" << std::endl;
	Array<int> empty;
	std::cout << "Size of empty array : " << empty.size() << std::endl;
	try
	{
		std::cout << empty[0] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception catch: " << e.what() << std::endl;
	}

	std::cout << "\n--- Default Initialization Test (int) ---" << std::endl;
	Array<int> numbers(5);
	for (unsigned int i = 0; i < numbers.size(); i++)
		std::cout << "numbers[" << i << "] = " << numbers[i] << " (should be 0)" << std::endl;

	std::cout << "\n--- Modification Test (std::string) ---" << std::endl;
	Array<std::string> strings(3);
	strings[0] = "42";
	strings[1] = "Lausanne";
	strings[2] = "Piscine";
	for (unsigned int i = 0; i < strings.size(); i++)
		std::cout << "strings[" << i << "] = " << strings[i] << std::endl;

	std::cout << "\n--- Deep Copy Test ---" << std::endl;
	Array<std::string> copyStrings(strings);
	std::cout << "Original[0] : " << strings[0] << " | Copy[0] : " << copyStrings[0] << std::endl;
	
	std::cout << "Editing the Copy..." << std::endl;
	copyStrings[0] = "something";
	std::cout << "Original[0] : " << strings[0] << " (should not change)" << std::endl;
	std::cout << "Copy[0]    : " << copyStrings[0] << " (should be \"something\")" << std::endl;

	std::cout << "\n--- Test Operateur = ---" << std::endl;
	Array<std::string> assignStrings;
	assignStrings = strings;
	std::cout << "Assign[1] before modif: " << assignStrings[1] << std::endl;
	strings[1] = "CHANGE_ORIGINAL";
	std::cout << "Assign[1] after modif: " << assignStrings[1] << " (should not change)" << std::endl;

	std::cout << "\n--- Out-of-Bounds Test ---" << std::endl;
	try
	{
		std::cout << "Attempting to access index 10 on an array of size 5..." << std::endl;
		numbers[10] = 0;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "Attempting to access a negative index..." << std::endl;
		numbers[-1] = 0; 
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test Const-Correctness ---" << std::endl;
	const Array<int> constArray(2);
	std::cout << "Reading index 0 of constArray: " << constArray[0] << std::endl;

	return 0;
}
