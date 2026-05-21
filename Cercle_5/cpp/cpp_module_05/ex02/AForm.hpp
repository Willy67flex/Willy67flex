#ifndef AForm_HPP
# define AForm_HPP

# include <iostream>

class Bureaucrat;

class	AForm
{
	private:

		const std::string	_name;
		bool				_signed;
		const int			_signedGrade;
		const int			_executeGrade;

	protected:

		virtual void action() const = 0;

	public:

		AForm(std::string name, int signedGrade, int executeGrade);
		AForm(const AForm &other);
		virtual ~AForm();

		AForm	&operator=(const AForm &other);

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

		class NotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		std::string	getName() const;
		bool		getSigned() const;
		int			getSignedGrade() const;
		int			getExecuteGrade() const;

		void		beSigned(const Bureaucrat &worker);

		virtual void	execute(Bureaucrat const &executor) const;

};

std::ostream &operator<<(std::ostream &ouput, AForm const &AForm);

#endif