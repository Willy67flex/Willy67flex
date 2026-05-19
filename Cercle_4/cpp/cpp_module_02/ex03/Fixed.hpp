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
	
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		Fixed	&operator=(const Fixed &other);
		float	toFloat( void ) const;
		int		toInt( void ) const;

		bool	operator>(const Fixed &other) const;
		bool	operator<(const Fixed &other) const;
		bool	operator>=(const Fixed &other) const;
		bool	operator<=(const Fixed &other) const;
		bool	operator==(const Fixed &other) const;
		bool	operator!=(const Fixed &other) const;

		Fixed	operator+(const Fixed &other) const;
		Fixed	operator-(const Fixed &other) const;
		Fixed	operator*(const Fixed &other) const;
		Fixed	operator/(const Fixed &other) const;

		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);

		static Fixed		&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &output, Fixed const &fixed);

#endif
