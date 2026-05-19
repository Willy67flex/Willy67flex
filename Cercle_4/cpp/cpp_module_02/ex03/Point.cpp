#include "Point.hpp"

Point::Point() :_x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point &other) : _x(other._x), _y(other._y) {}

Point::~Point() {}

Fixed	Point::getX() const 
{
	return _x;
}

Fixed	Point::getY() const 
{
	return _y;
}

std::ostream &operator<<(std::ostream &output, Point const &point)
{
	output << "(" << point.getX() << ", " << point.getY() << ")";
	return output;
}

bool	Point::operator==(const Point &other) const
{
	if (this->_x == other._x && this->_y == other._y)
		return true;
	return false;
}

Point	&Point::operator=(Point const &other)
{
	(void)other; 
	return *this;
}
