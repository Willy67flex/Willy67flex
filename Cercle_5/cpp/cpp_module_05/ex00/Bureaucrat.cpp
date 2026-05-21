#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor callled" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	_grade = other._grade;
	return *this;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high! (max is 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low! (Min is 150)";
}

std::string	Bureaucrat::getName() const
{
	return _name;
}

int	Bureaucrat::getGrade() const
{
	return _grade;
}

void	Bureaucrat::bePromoted()
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::beDemoted()
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

std::ostream &operator<<(std::ostream &output, Bureaucrat const &bureaucrat)
{
	output << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return output;
}
