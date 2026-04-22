#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	std::string str;

	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 1;
	}
	for (int i = 1; i < argc; i++)
	{
		std::string word = argv[i];

		for (int j = 0; word[j]; j++)
			str += toupper(word[j]);
		if (i < argc - 1)
			str += " ";
	}
	std::cout << str << std::endl;
	return 0;
}
