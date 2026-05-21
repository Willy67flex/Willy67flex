#ifndef Bureaucrat_HPP
# define Bureaucrat_HPP

# include <iostream>

class Form;

class Bureaucrat
{
	private:

		const std::string	_name;
		int					_grade;

	public:

		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();

		Bureaucrat	&operator=(const Bureaucrat &other);

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
		int			getGrade() const;

		void		bePromoted();
		void		beDemoted();

		void		signForm(Form &worker);

};

	std::ostream &operator<<(std::ostream &output, Bureaucrat const & bureaucrat);

#endif