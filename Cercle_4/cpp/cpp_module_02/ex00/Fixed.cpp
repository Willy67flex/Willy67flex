#include "Fixed.hpp"

const int Fixed::nbFractionalBits = 8;

Fixed::Fixed() : fixedPointNumVal(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	fixedPointNumVal = other.getRawBits();
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const 
{
	std::cout << "getRawBits member function called" << std::endl;
	return fixedPointNumVal;
}

void Fixed::setRawBits( int const raw )
{
	fixedPointNumVal = raw;
}

Fixed	&Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		fixedPointNumVal = other.getRawBits();
	return *this;
}
