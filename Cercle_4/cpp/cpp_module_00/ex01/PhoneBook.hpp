#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cctype>

class	Contact
{
	private:
		std::string	FirstName;
		std::string	LastName;
		std::string	NickName;
		std::string	PhoneNumber;
		std::string	DarkestSecret;

	public:
		Contact() {}

		void	SetNewContact(std::string fName, std::string lName, std::string nName,
			std::string pNumber, std::string dSecret)
		{
			FirstName = fName;
			LastName = lName;
			NickName = nName;
			PhoneNumber = pNumber;
			DarkestSecret = dSecret;
		}

		std::string	GetFirstName(int flag)
		{
			if (flag == 0)
				return FirstName;
			std::string	str = FirstName;
			if (str.length() > 10)
				return str.substr(0, 9) + ".";
			return str;
		}

		std::string GetLastName(int flag)
		{
			if (flag == 0)
				return LastName;
			std::string	str = LastName;
			if (str.length() > 10)
				return str.substr(0, 9) + ".";
			return str;
		}

		std::string	GetNickName(int flag)
		{
			if (flag == 0)
				return NickName;
			std::string	str = NickName;
			if (str.length() > 10)
				return str.substr(0, 9) + ".";
			return str;
		}

		std::string	GetPhoneNumber()
		{
			return PhoneNumber;
		}

		std::string	GetDarkestSecret()
		{
			return DarkestSecret;
		}
};

class	PhoneBook
{
	private:
		Contact	contact[8];
		int	nbContact;

		bool IsOnlySapce(std::string str)
		{
			for (size_t i = 0; i < str.length(); i++)
			{
				if (!std::isspace(str[i]))
					return false;
			}
			return (true);
		}

		std::string getInput(std::string prompt)
		{
			std::string input = "";

			while (input.empty() || IsOnlySapce(input))
			{
				std::cout << prompt;
				std::getline(std::cin, input);

				if (std::cin.eof())
				{
					std::cout << "\nWarning: End of file reached. Exiting." << std::endl;
					exit(0);
				}
			}
			return input;
		}

	public:
		PhoneBook()
		{
			nbContact = 0;
		}

		void AddNewContact()
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

		void	SearchContact()
		{
			int	max = nbContact;

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
};

#endif
