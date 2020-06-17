#include <iostream>
#include <conio.h>
#include <math.h>
int main()
{
	float z = 0, a = 0, x = 0, d = 0, y = 0;
	int function = 0;

	std::cout << "enter z, d, a\n";
	std::cin >> z >> d >> a;

	if (z > 0)
		x = -3 * z;
	else
		x = z * z;
	do
	{
		std::cout << "if u want f(x) = 2x  enter 1\nif u want f(x) = x^2  enter 2\nif u want f(x) = x/3  enter 3\n";
		std::cin >> function;
	} 
	while (function < 1 || function > 3);
	switch (function)
	{
	case(1): y = 2 * (2 * x) * (a * sin(x) + d * exp(-(x + 3)));
		std::cout << y << " u've chosen f(x) = 2 * x\n";
		break;
	case(2): y = 2 * (x * x) * (a * sin(x) + d * exp(-(x + 3)));
		std::cout << y << " u've chosen f(x) = x^2\n";
		break;
	case(3): y = 2 * (x / 3) * (a * sin(x) + d * exp(-(x + 3)));
		std::cout << "Result is " << y << " u've chosen f(x) = x / 3\n";
		break;
	}
	_getch();
	return 0;
}