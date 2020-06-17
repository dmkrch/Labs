#include <conio.h>
#include <iostream>
#include <math.h>
int main()
{
	float radius = 0, side = 0, sq_max = 0, sq_current = 0, angle = 0, radius_max = 0;

	std::cout << "Enter the side of rhombus hole ";
	std::cin >> side;
	std::cout << "Enter the radius of sphere ";
	std::cin >> radius;
	std::cout << "Enter the angle in degrees(0 - 90) ";
	std::cin >> angle;

	angle *= 3.14 / 180;

	sq_max = side * side * sin(angle);
	sq_current = 2 * radius * side;

	if (sq_max >= sq_current)
		std::cout << "\nThe sphere can pass the hole\n";
	else
		{
			radius_max = 0.5 * side * sin(angle);
			std::cout << "\nThe sphere can't pass the hole\nThe maximum radius of sphere can be " << radius_max;
		}

	_getch();
	return 0;
}