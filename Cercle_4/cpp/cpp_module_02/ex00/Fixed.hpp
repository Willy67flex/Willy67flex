#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:

	int					fixedPointNumVal;
	static const int	nbFractionalBits;

	public:

	Fixed();
	Fixed(const Fixed &other); 
	~Fixed();

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	Fixed &operator=(const Fixed &other);
};

#endif
