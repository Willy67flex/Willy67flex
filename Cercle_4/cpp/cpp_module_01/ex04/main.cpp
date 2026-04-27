#include <fstream>
#include <iostream>
#include <string>

std::string	scan_line(std::string line, std::string s1, std::string s2)
{
	if (s1.empty())
		return line;

	std::size_t	found = line.find(s2);

	while (found != std::string::npos)
	{
		// remplacer;
		found = line.find(s2);
	}
	return line;
}

int	main(int argc, char **argv)
{
	std::string	filename = argv[1], s1 = argv[2], s2 = argv[3];

	if (argc != 4)
		return (std::cout << "Wrong input!\nInput accepted: ./SedIsForLosers"
			<< "\"<filenam> <string> <string>\"" << std::endl, 1);

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
		line = scan_line(line, s1, s2);
		outFile << line;

		if (!file.eof())
			outFile << std::endl;
	}
	return 0;
}
