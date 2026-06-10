#include <iostream>
#include "Serializer.hpp"

int main()
{
	Data	myData;
	myData.id = 42;
	myData.name = "Eliott";

	Data* originalPtr = &myData;

	uintptr_t raw = Serializer::serialize(originalPtr);

	Data* resultPtr = Serializer::deserialize(raw);

	std::cout << "Original Ptr: " << originalPtr << std::endl;
	std::cout << "Result Ptr:   " << resultPtr << std::endl;

	if (resultPtr == originalPtr)
	{
		std::cout << "SUCCESS: Pointers match!" << std::endl;
		std::cout << "Data check: " << resultPtr->name << " (ID: " << resultPtr->id << ")" << std::endl;
	}
	else
	{
		std::cout << "FAILURE: Pointers are different!" << std::endl;
	}

	return 0;
}
