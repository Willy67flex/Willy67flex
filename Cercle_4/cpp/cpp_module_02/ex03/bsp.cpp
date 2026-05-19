#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	res1;
	Fixed	res2;
	Fixed	res3;

	if (a == b || a == c || b == c)
		return false;

	res1 = (((c.getX() - point.getX()) * (a.getY() - point.getY())) - ((c.getY() - point.getY()) * (a.getX() - point.getX())));
	res2 = (((a.getX() - point.getX()) * (b.getY() - point.getY())) - ((a.getY() - point.getY()) * (b.getX() - point.getX())));
	res3 = (((b.getX() - point.getX()) * (c.getY() - point.getY())) - ((b.getY() - point.getY()) * (c.getX() - point.getX())));

	if ((res1 > 0 && res2 > 0 && res3 > 0) || (res1 < 0 && res2 < 0 && res3 < 0))
		return true;
	return false;
}
