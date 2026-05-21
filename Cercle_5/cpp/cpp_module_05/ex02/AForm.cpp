#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string name, int signedGrade, int executeGrade) 
	: _name(name), _signed(false), _signedGrade(signedGrade), _executeGrade(executeGrade)
{
	if (signedGrade < 1 || executeGrade < 1)
		throw AForm::GradeTooHighException();
	if (signedGrade > 150 || executeGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed), _signedGrade(other._signedGrade), _executeGrade(other._executeGrade)
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

AForm	&AForm::operator=(const AForm &other)
{
	_signed = other._signed;
	return *this;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}

const char *AForm::NotSignedException::what() const throw()
{
	return "cannot execute because it's not signed!";
}

std::string	AForm::getName() const
{
	return _name;
}

bool	AForm::getSigned() const
{
	return _signed;
}

int	AForm::getSignedGrade() const
{
	return _signedGrade;
}

int	AForm::getExecuteGrade() const
{
	return _executeGrade;
}

void AForm::beSigned(const Bureaucrat &worker)
{
	if (worker.getGrade() <= _signedGrade)
		_signed = true;
	else
		throw AForm::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &output, AForm const &AForm)
{
	output << "AForm " << AForm.getName() << " (signed: " << (AForm.getSigned() ? "yes" : "no") 
		   << ", grade to sign: " << AForm.getSignedGrade() 
		   << ", grade to execute: " << AForm.getExecuteGrade() << ")";
	return output;
}

void AForm::execute(Bureaucrat const & executor) const {
	if (getSigned() == false)
		throw AForm::NotSignedException();
	if (executor.getGrade() > getExecuteGrade())
		throw AForm::GradeTooLowException();
	
	action();
}
