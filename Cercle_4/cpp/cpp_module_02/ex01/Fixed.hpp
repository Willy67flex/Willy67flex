#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>


class Fixed
{
	private:
	
		int					fixedPointNumVal;
		static const int	nbFractionalBits;
	
	public:
	
		Fixed();
		Fixed(const Fixed &other); 
	
		Fixed(const int value);
		Fixed(const float nb);
	
		~Fixed();
	
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		Fixed &operator=(const Fixed& other);
	
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &output, Fixed const &fixed);

#endif
