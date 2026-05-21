#ifndef Intern_HPP
# define Intern_HPP

#include <iostream>

class AForm;

class Intern
{
	private:

		std::string	actionTable[3];
		AForm	*createPresidential(std::string target);
		AForm	*createRobotomy(std::string target);
		AForm	*createShrubbery(std::string target);

	public:

		Intern();
		Intern(const Intern &other);
		~Intern();

		Intern	&operator=(const Intern &other);


		AForm	*makeForm(std::string action, std::string target);

};


#endif