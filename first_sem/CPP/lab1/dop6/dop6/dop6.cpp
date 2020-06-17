#include <iostream>
#include <conio.h>
#include <math.h>
int main()
{
	float x1 = 0, x2 = 0, x3 = 0, y1 = 0, y2 = 0, y3 = 0, a1 = 0, a2 = 0, a3 = 0;

	std::cout << "Enter x and y of 1st peak\n";
	std::cin >> x1 >> y1;
	std::cout << "Enter x and y of 2nd peak\n";
	std::cin >> x2 >> y2;
	std::cout << "Enter x and y of 3d peak\n";
	std::cin >> x3 >> y3;
	


	a1 = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	a2 = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
	a3 = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));

	std::cout << "Perimeter of triangle is " << a1 + a2 + a3;

	_getch();
	return 0;
}