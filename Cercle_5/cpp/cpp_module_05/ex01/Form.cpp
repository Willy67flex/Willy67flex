#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, int signedGrade, int executeGrade) 
	: _name(name), _signed(false), _signedGrade(signedGrade), _executeGrade(executeGrade)
{
	if (signedGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
	if (signedGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &other) : _name(other._name), _signed(other._signed), _signedGrade(other._signedGrade), _executeGrade(other._executeGrade)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form	&Form::operator=(const Form &other)
{
	_signed = other._signed;
	return *this;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}

std::string	Form::getName() const
{
	return _name;
}

bool	Form::getSigned() const
{
	return _signed;
}

int	Form::getSignedGrade() const
{
	return _signedGrade;
}

int	Form::getExecuteGrade() const
{
	return _executeGrade;
}

void Form::beSigned(const Bureaucrat &worker)
{
	if (worker.getGrade() <= _signedGrade)
		_signed = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &output, Form const &form)
{
	output << "Form " << form.getName() << " (signed: " << (form.getSigned() ? "yes" : "no") 
		   << ", grade to sign: " << form.getSignedGrade() 
		   << ", grade to execute: " << form.getExecuteGrade() << ")";
	return output;
}
