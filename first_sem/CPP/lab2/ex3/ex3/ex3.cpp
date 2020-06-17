#include <iostream>
#include <conio.h>
int main()
{
	int x = 0, y = 0;
	float a, b, c;

	std::cout << "enter x ";
	std::cin >> x;
	std::cout << "enter y ";
	std::cin >> y;

	if (x > y)
		y = 0;
	else if (x < y)
		x = 0;
	else
		x = y = 0;
	
	std::cout << "x is " << x << "\ny is " << y << "\n\n";
	
	std::cout << "enter A ";
	std::cin >> a;
	std::cout << "enter B";
	std::cin >> b;
	std::cout << "enter C";
	std::cin >> c;

	if (a > b)
	{
		if (a > c)
			a = a - 0.3;
		else
			if (c > b)
				c = c - 0.3;

	}
	else
		if (b > c)
			b = b - 0.3;
		else
			c = c - 0.3;

	std::cout << "a is " << a << "\nb is " << b << "\nc is " << c;
	return 0;
}