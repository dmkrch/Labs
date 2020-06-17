#include <conio.h>
#include <iostream>
#include <math.h>
int main()
{
	float x = 0, y = 0, result = 0;

	std::cout << "Enter x, y\n";
	std::cin >> x >> y;

	if (x > 0)
	{
		result = (x * x + y * y * y) / y;
		std::cout << "Result is " << result << " because x > 0\n";
	}
	else if (x < 0)
	{
		result = log(fabs(x * x * x)) + cos(y);
		std::cout << "Result is " << result << " because x < 0\n";
	}
	else
	{
		result = pow((sin(y) * sin(y)), 1.0 / 3);
		std::cout << "Result is " << result << " because x = 0\n";
	}
	_getch();
	return 0;
}