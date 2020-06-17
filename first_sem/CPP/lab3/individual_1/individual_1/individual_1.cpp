#include <iostream>
#include <conio.h>
#include <math.h>
int main()
{
	float function_y = 0, function_s = 0, x = 0, argument_s = 0;
	int n = 0, number = 0, i = 0;

	std::cout << "How many times do u want to calculate?  ";
	std::cin >> number;

	for (;number > 0; --number)
	{
		std::cout << "Put amount of n in row (the more the better)  ";
		std::cin >> i;
		do
		{
			std::cout << "Put the argument X ( 0.1 - 0.9)  ";
			std::cin >> x;
		} 
		while (x < 0.1 || x > 0.9);

		for (n = 1; n <= i; ++n)
		{
			argument_s = (pow(-1.0, n + 1) * pow(x / 1.0, 2 * n)) / (2 * n * (2 * n - 1));
			function_s += argument_s;
		}

		function_y = x * atan(x) - log(sqrt(1 + x * x));

		std::cout << "\nY(x) = " << function_y << "\t\t" << "Row S(x) = " << function_s << "\n";

		function_y = function_s = 0;
	}

	_getch();
	return 0;
}