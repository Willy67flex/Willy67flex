#include <fstream>
#include <iostream>
#include <string>

std::string replace_occurrences(std::string line, std::string s1, std::string s2) 
{
	if (s1.empty())
		return line;

	std::string	result;
	std::size_t	pos = 0;
	std::size_t	found;

	while ((found = line.find(s1, pos)) != std::string::npos) 
	{
		result.append(line, pos, found - pos);//copy tout ce qu'il y a avant s1
		result += s2;//ajoute s2 a la place de s2
		pos = found + s1.length();//redefini pos a juste apres s1 trouver precedament
	}
	result.append(line, pos);//met tout le reste du texte apres le derrnier s1
	return result;
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (std::cout << "Wrong input!\nInput accepted: ./SedIsForLosers"
			<< "\"<filenam> <string> <string>\"" << std::endl, 1);
	
	std::string	filename = argv[1], s1 = argv[2], s2 = argv[3];

	//ifstream = ouvre fichier + lit
	std::ifstream	file(filename.c_str());//convertion en const char *
	if (!file.is_open())
		return (std::cout << "File \"" << filename << "\" does't exist" << std::endl, 1);

	//ofstream = cree nouveau fichier + ecrit
	std::ofstream	outFile((filename + ".replace").c_str());//convertion en const char *
	if (!outFile.is_open())
		return (std::cout << "Error creating output file" << std::endl, 1);

	std::string	line;

	while (std::getline(file, line))
	{
		line = replace_occurrences(line, s1, s2);

		outFile << line;

		if (!file.eof())
			outFile << std::endl;
	}
	return 0;
}
