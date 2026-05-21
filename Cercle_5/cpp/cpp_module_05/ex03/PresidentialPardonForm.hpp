#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP

# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:

		std::string _target;

	protected:

		virtual void action() const;

	public:

		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		~PresidentialPardonForm();

		PresidentialPardonForm	&operator=(const PresidentialPardonForm &other);

};


#endif