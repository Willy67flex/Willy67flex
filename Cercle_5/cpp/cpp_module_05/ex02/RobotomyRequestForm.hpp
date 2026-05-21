#ifndef RobotomyRequestForm_HPP
# define RobotomyRequestForm_HPP

# include "AForm.hpp"
# include <cstdlib>

class RobotomyRequestForm: public AForm
{
	private:

		std::string _target;


	protected:

		virtual void action() const;


	public:

		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		~RobotomyRequestForm();

		RobotomyRequestForm	&operator=(const RobotomyRequestForm &other);

};


#endif