#include "Fixed.hpp"

const int Fixed::nbFractionalBits = 8;

Fixed::Fixed() : fixedPointNumVal(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}



Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	fixedPointNumVal = value << nbFractionalBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedPointNumVal = roundf(value * (1 << nbFractionalBits));
}




Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const 
{
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



float	Fixed::toFloat( void ) const
{
	return ((float)fixedPointNumVal / (1 << nbFractionalBits));
}

int	Fixed::toInt( void ) const
{
	return (fixedPointNumVal >> nbFractionalBits);
}

std::ostream &operator<<(std::ostream &output, Fixed const &fixed)
{
	output << fixed.toFloat();
	return output;
}
