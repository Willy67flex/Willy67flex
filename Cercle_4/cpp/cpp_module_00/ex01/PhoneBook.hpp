#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

class	Contact
{
	private:
		std::string	FirstName, LastName, NickName, PhoneNumber, DarkestSecret;

	public:

		void	SetNewContact(std::string fName, std::string lName, std::string nName,
			std::string pNumber, std::string dSecret);
		std::string	GetFirstName(int flag);
		std::string GetLastName(int flag);
		std::string	GetNickName(int flag);
		std::string	GetPhoneNumber();
		std::string	GetDarkestSecret();
};

class	PhoneBook
{
	private:
		Contact	contact[8];
		int	nbContact;

		bool IsOnlySapce(std::string str);
		std::string getInput(std::string prompt);

	public:

		PhoneBook();
		void	AddNewContact();
		void	SearchContact();
};

#endif
