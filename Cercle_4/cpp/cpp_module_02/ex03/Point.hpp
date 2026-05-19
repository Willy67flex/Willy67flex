#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point
{
	private:

		Fixed const	_x;
		Fixed const	_y;

	public:

	Point();
	Point(const float x, const float y);
	Point(const Point &other);
	~Point();

	Fixed	getX() const;
	Fixed	getY() const;
	Point	&operator=(Point const &other);
	bool	operator==(const Point &other) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
std::ostream &operator<<(std::ostream &output, Point const &fixed);

#endif