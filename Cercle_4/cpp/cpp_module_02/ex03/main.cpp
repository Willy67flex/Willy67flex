#include "Fixed.hpp"
#include "Point.hpp"

int	main()
{
	Point	A;
	Point	B(5, 1);
	Point	C(3, 3);
	Point	X(2, 1);
	Point	nothing(C);

	std::cout << "Coordinates of A: " << A << std::endl;
	std::cout << "Coordinates of B: " << B << std::endl;
	std::cout << "Coordinates of C: " << C << std::endl;
	std::cout << "Coordinates of X: " << X << std::endl;
	std::cout << "Coordinates of nothing: " << nothing << std::endl;

	if (bsp(A, B, C, X))
		return (std::cout << "Yes! The point is in the triangle!" << std::endl, 0);
	std::cout << "No. The point isn't in the triangle." << std::endl;
	return 0;
}
