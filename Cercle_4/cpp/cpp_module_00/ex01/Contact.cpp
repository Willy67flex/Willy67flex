#include "PhoneBook.hpp"

void	Contact::SetNewContact(std::string fName, std::string lName, std::string nName,
			std::string pNumber, std::string dSecret)
		{
			FirstName = fName;
			LastName = lName;
			NickName = nName;
			PhoneNumber = pNumber;
			DarkestSecret = dSecret;
		}

		std::string	Contact::GetFirstName(int flag)
		{
			if (flag == 0)
				return FirstName;
			std::string	str = FirstName;
			if (str.length() > 10)
				return str.substr(0, 9) + ".";
			return str;
		}

		std::string Contact::GetLastName(int flag)
		{
			if (flag == 0)
				return LastName;
			std::string	str = LastName;
			if (str.length() > 10)
				return str.substr(0, 9) + ".";
			return str;
		}

		std::string	Contact::GetNickName(int flag)
		{
			if (flag == 0)
				return NickName;
			std::string	str = NickName;
			if (str.length() > 10)
				return str.substr(0, 9) + ".";
			return str;
		}

		std::string	Contact::GetPhoneNumber()
		{
			return PhoneNumber;
		}

		std::string	Contact::GetDarkestSecret()
		{
			return DarkestSecret;
		}
