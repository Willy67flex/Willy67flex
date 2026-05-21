#ifndef ShrubberyCreationForm_HPP
# define ShrubberyCreationForm_HPP

# include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	private:

		std::string _target;

	protected:

		virtual void action() const;

	public:

		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();

		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &other);

};

#endif