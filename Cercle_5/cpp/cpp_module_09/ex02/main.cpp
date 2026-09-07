#include "PmergeMe.hpp"

int	isDigit(char c, int &count)
{
	if ((c == '+' || c == '-') && count == 0)
	{
		count++;
		return 1;
	}
	else if (c >= '0' && c <= '9')
	{
		count++;
		return 1;
	}
	else if (c == ' ' || c == '\r' || c == '\n' || c == '\t')
	{
		count = 0;
		return 0;
	}
	return 2;
}

bool	fileClass(std::string &str, PmergeMe &p)
{
	long	number;

	if (!str.empty())
	{
		if (str == "+" || str == "-")
			return (std::cerr << "Error:\nInvalide charactere found" << std::endl, 1);
		number = atol(str.c_str());
		str = "";
		if (number < 0)
			return (std::cerr << "Error:\nNegative value found" << std::endl, 1);
		if (number >  2147483647)
			return (std::cerr << "Error:\nINT_MAX overflow" << std::endl, 1);
		else
		{
			p.setVector(static_cast<int>(number));
			p.setDeque(static_cast<int>(number));
			p.incrSize();
		}
	}
	return 0;
}

bool	checkArgs(char **args, PmergeMe &p)
{
	std::string	str;
	int			result;
	int			count;

	for (int i = 1; args[i]; i++)
	{
		count = 0;
		str = "";
		for (int j = 0; args[i][j]; j++)
		{
			result = isDigit(args[i][j], count);
			if (result == 1)
				str += args[i][j];
			else if (result == 2)
				return (std::cerr << "Error:\nInvalide charactere found" << std::endl, 1);
			else
			{
				if (fileClass(str, p))
					return 1;
			}
		}
		if (fileClass(str, p))
			return 1;
	}
	return 0;
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (std::cerr << "Error:\nUsage: ./PmergeMe <positive integer sequence>" << std::endl, 1);

	PmergeMe			p;
	double				duartionV;
	double				duartionD;

	if (checkArgs(argv, p))
		return 1;
	std::cout << "Before: ";
	p.printVector();
	// p.printDeque();
	p.sort(0, p, duartionV);
	p.sort(1, p, duartionD);

	std::cout << "After : ";
	p.printVector();
	// p.printDeque();

	std::cout << "Time to process a range of " << p.getSize() << " elements with std::vector : " << duartionV << " us" << std::endl;
	std::cout << "Time to process a range of " << p.getSize() << " elements with std::deque  : " << duartionD << " us" << std::endl;

	return 0;
}
