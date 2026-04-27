#include "PhoneBook.hpp"

bool PhoneBook::IsOnlySapce(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isspace(str[i]))
			return false;
	}
	return (true);
}

std::string PhoneBook::getInput(std::string prompt)
{
	std::string input = "";

	while (input.empty() || IsOnlySapce(input))
	{
		std::cout << prompt;
		std::getline(std::cin, input);
		if (input.empty() || IsOnlySapce(input))
			std::cout << "Please write something" << std::endl;

		if (std::cin.eof())
		{
			std::cout << "\nWarning: End of file reached. Exiting." << std::endl;
			exit(0);
		}
	}
	return input;
}

PhoneBook::PhoneBook()
{
	nbContact = 0;
}

void PhoneBook::AddNewContact()
{
	std::string fName, lName, nName, pNumber, dSecret;
	std::cin.ignore(10000, '\n');
	std::cout << "\nCreating a contact" << std::endl;

	fName = getInput("First name: ");
	lName = getInput("Last name: ");
	nName = getInput("Nickname: ");
	pNumber = getInput("Phone number: ");
	dSecret = getInput("Darkest secret: ");

	contact[nbContact % 8].SetNewContact(fName, lName, nName, pNumber, dSecret);
	nbContact++;

	std::cout << "Contact added successfully!" << std::endl;
}

void	PhoneBook::SearchContact()
{
	int	max = nbContact;

	if (max == 0)
	{
		std::cout << "You don't have any contacts to look for." << std::endl;
		return ;
	}
	if (max > 8)
		max = 8;

	std::cout << "|" << std::setw(10) << "Index" << "|" << std::setw(10)
			  << "First Name" << "|" << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "NickName" << "|" << std::endl;

	for (int i = 0; i < max; i++)
	{
		std::cout << "|" << std::setw(10) << i + 1 << "|"
				  << std::setw(10) << contact[i].GetFirstName(1) << "|"
				  << std::setw(10) << contact[i].GetLastName(1) << "|"
				  << std::setw(10) << contact[i].GetNickName(1) << "|" << std::endl;
	}

	std::cout << "\nWhich profile do you want to display? (1, 2, ...)" << std::endl;

	int	indx;
	std::cin >> indx;

	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Invalid input! Please enter a number." << std::endl;
		return ;
	}

	if (indx > max || indx < 1)
	{
		std::cout << "Contact not parameter at index " << indx
				  << ", or invalid index" << std::endl;
		return ;
	}

	std::cout << contact[indx - 1].GetFirstName(0) << "'s information\n"
	  << "First Name: " << contact[indx - 1].GetFirstName(0)
	  << "\nLast Name: " << contact[indx - 1].GetLastName(0)
	  << "\nNickname: " << contact[indx - 1].GetNickName(0)
	  << "\nPhone Number: " << contact[indx - 1].GetPhoneNumber()
	  << "\nDarkest Secret: " << contact[indx - 1].GetDarkestSecret()
	  << "\n" << std::endl;
}
