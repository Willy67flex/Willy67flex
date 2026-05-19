#include "Fixed.hpp"

const int Fixed::nbFractionalBits = 8;

Fixed::Fixed() : fixedPointNumVal(0) {}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed::Fixed(const int value)
{
	fixedPointNumVal = value << nbFractionalBits;
}

Fixed::Fixed(const float value)
{
	this->fixedPointNumVal = roundf(value * (1 << nbFractionalBits));
}

Fixed::~Fixed() {}

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




bool	Fixed::operator>(const Fixed &other) const
{
	return (fixedPointNumVal > other.fixedPointNumVal);
}

bool	Fixed::operator<(const Fixed &other) const
{
	return (fixedPointNumVal < other.fixedPointNumVal);
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (fixedPointNumVal >= other.fixedPointNumVal);
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (fixedPointNumVal <= other.fixedPointNumVal);
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (fixedPointNumVal == other.fixedPointNumVal);
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (fixedPointNumVal != other.fixedPointNumVal);
}

Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed	res;
	int		sum = this->getRawBits() + other.getRawBits();

	res.setRawBits(sum);

	return res;
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed	res;
	int		sum = this->getRawBits() - other.getRawBits();

	res.setRawBits(sum);

	return res;
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	return (this->toFloat() * other.toFloat());
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	return (this->toFloat() / other.toFloat());
}

Fixed	&Fixed::operator++()
{
	fixedPointNumVal++;

	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed temp(*this);

	operator++();

	return temp;
}

Fixed	&Fixed::operator--()
{
	fixedPointNumVal--;

	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed temp(*this);

	operator--();
	
	return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) 
{
	if (a < b)
		return a;
	return b;
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) 
{
	if (a > b)
		return a;
	return b;
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return a;
	return b;
}
