#ifndef Form_HPP
# define Form_HPP

# include <iostream>

class Bureaucrat;

class	Form
{
	private:

		const std::string	_name;
		bool				_signed;
		const int			_signedGrade;
		const int			_executeGrade;

	public:

		Form(std::string name, int signedGrade, int executeGrade);
		Form(const Form &other);
		~Form();

		Form	&operator=(const Form &other);

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		std::string	getName() const;
		bool		getSigned() const;
		int			getSignedGrade() const;
		int			getExecuteGrade() const;

		void	beSigned(const Bureaucrat &worker);

};

std::ostream &operator<<(std::ostream &ouput, Form const &form);

#endif