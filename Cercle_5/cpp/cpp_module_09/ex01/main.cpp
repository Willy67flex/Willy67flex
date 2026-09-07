#include "RPN.hpp"

bool	isSpace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r')
		return 1;
	return 0;
}

bool	isOperator(char c)
{
	if (c == '+' || c == '-' || c == '/' || c == '*')
		return 1;
	return 0;
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (std::cerr << "Error:\nUsage: ./RPN <what do you want to calcule>" << std::endl, 1);
	if (argc > 2)
		return (std::cerr << "Error\nThis program accepts only two arguments" << std::endl, 1);
	
	RPN	rpn;

	try
	{
		for (int i = 0; argv[1][i] != '\0'; i++)
		{
			if (isSpace(argv[1][i]))
				continue ;

			if (argv[1][i] >= '0' && argv[1][i] <= '9')
			{
				if (argv[1][i+1] != '\0' && (argv[1][i+1] >= '0' && argv[1][i+1] <= '9'))
					throw std::runtime_error("Error");
				
				rpn.setData(argv[1][i] - '0');
			}
			else if (isOperator(argv[1][i]))
				rpn.calculate(argv[1][i]);
			else
				throw std::runtime_error("Error");
		}
		std::cout << rpn.getResult() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
