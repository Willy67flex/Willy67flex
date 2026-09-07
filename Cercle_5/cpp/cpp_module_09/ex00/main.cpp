#include "BitcoinExchange.hpp"

std::string	trim(const std::string& str)
{
	size_t	first;
	size_t	last;

	first = str.find_first_not_of(" \t\n\r");
	if (first == std::string::npos)
		return "";
	last = str.find_last_not_of(" \t\n\r");

	return (str.substr(first, (last - first + 1)));
}

bool	isValidDate(const std::string& date)
{
	if (date.length() != 10)
		return 1;
	if (date[4] != '-' || date[7] != '-')
		return 1;

	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
			return 1;
	}

	bool	leapYear;
	int		year = std::atoi(date.substr(0, 4).c_str());
	int		month = std::atoi(date.substr(5, 2).c_str());
	int		day = std::atoi(date.substr(8, 2).c_str());

	if (year < 2009 && month < 1 && day < 1)
		return 1;
	if (month < 1 || month > 12)
		return 1;

	if (month == 2)
	{
		leapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (leapYear)
		{
			if (day < 1 || day > 29)
				return 1;
		}
		else
		{
			if (day < 1 || day > 28)
				return 1;
		}
	}

	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		if (day < 1 || day > 31)
			return 1;
	}

	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day < 1 || day > 30)
			return 1;
	}

	return 0;
}

bool	init_data(Bitcoin &b)
{
	std::ifstream	file("data.csv");
	std::string		line;
	size_t			commaPos;
	std::string		date;
	std::string		rateStr;
	double			rate;
	char			*end;

	if (!file.is_open())
	{
		std::cerr << "Error: could not open data.csv" << std::endl;
		return 1;
	}

	std::getline(file, line);
	if (line != "date,exchange_rate")
	{
		std::cerr << "Error: the first line of the data file need to be: 'date,exchange_rate'" << std::endl;
		return 1;
	}

	while (std::getline(file, line))
	{
		commaPos = line.find(',');
		if (commaPos == std::string::npos)
		{
			std::cerr << "Error: invalide syntaxe in data =>" << trim(line.substr(0, commaPos + 1)) << "," << trim(line.substr(commaPos + 1)) << std::endl;
			return 1;
		}
		size_t test = line.find(',', commaPos + 1);
		if (test != std::string::npos)
		{
			std::cerr << "Error: invalide syntaxe in data =>" << trim(line.substr(0, commaPos + 1)) << trim(line.substr(commaPos + 1)) << std::endl;
			return 1;
		}

		date = trim(line.substr(0, commaPos));
		rateStr = trim(line.substr(commaPos + 1));

		if (date.empty())
		{
			std::cerr << "Error: no date in data " << std::endl;
			return 1;
		}

		if (isValidDate(date) ==  1)
		{
			std::cerr << "Error: invalide date in data => " << date << std::endl;
			return 1;
		}

		if (rateStr.empty())
		{
			std::cerr << "Error: no rate in data" << std::endl;
			return 1;
		}

		rate = std::strtod(rateStr.c_str(), &end);

		if (*end != '\0' && !std::isspace(*end))
		{
			std::cerr << "Error: invalide rate in data" << std::endl;
			return 1;
		}

		b.setData(date, rate); 
	}
	file.close();
	return 0;
}

bool	checkSyntax(std::string &line, const Bitcoin &b)
{
	size_t		p;
	std::string	date;
	std::string	value;
	double		val;
	char		*end;

	if ((p = line.find('|')) == std::string::npos)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return 1;
	}
	
	date = trim(line.substr(0, p));
	value = trim(line.substr(p + 1));

	if (date.empty())
	{
		std::cerr << "Error: bad input => No date" << std::endl;
		return 1;
	}
	if (isValidDate(date) == 1)
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return 1;
	}

	if (value.empty())
	{
		std::cerr << "Error: bad input => No value" << std::endl;
		return 1;
	}

	val = std::strtod(value.c_str(), &end);

	if (*end != '\0')
	{
		std::cerr << "Error: bad input => " << value << std::endl;
		return 1;
	}
	if (val < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return 1;
	}
	if (val > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return 1;
	}
	b.execute(date, val);
	return 0;

}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cerr << "Error:\nUsage: ./btc <file>" << std::endl, 1);

	Bitcoin		b;

	if (init_data(b) == 1)
		return 1;
	
	std::ifstream	file(argv[1]);
	std::string		line;

	if (!file.is_open())
		return 1;

	std::getline(file, line);
	if (line != "date | value")
	{
		std::cerr << "Error: the first line of the file passed as an argument need to be: 'date | value'" << std::endl;
		return 1;
	}

	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		if (checkSyntax(line, b) == 1)
			continue ;
	}

	return 0;
}
