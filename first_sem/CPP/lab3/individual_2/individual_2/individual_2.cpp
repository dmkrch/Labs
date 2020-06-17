#include <iostream>
#include <conio.h>
#include <math.h>
int main()
{
	float function = 0, step = 0, low_value = 0, up_value = 0, x = 0, function_min = 0, x_min = 0;
	int separations = 0;
	
	do
	{
		std::cout << "Enter lowest value of interval ";
		std::cin >> low_value;
		std::cout << "Enter upper value of interval ";
		std::cin >> up_value;
	}
	while (up_value <= low_value);

	do
	{
		std::cout << "Enter the number of separations ";
		std::cin >> separations;
	} 
	while (separations <= 0);

	step = (up_value - low_value) / separations;
	x = low_value, function_min = acos(exp(-(x + 1) * (x + 1))) + sin(x);

	while (x <= up_value)
	{
		function = acos(exp(-(x + 1) * (x + 1))) + sin(x);

		if (fabs(function) < function_min)
		{
			function_min = function;
			x_min = x;
		}
		x += step;
	}
	/*for (x = low_value, function_min = acos(exp(-(x + 1) * (x + 1))) + sin(x); x <= up_value; x += step)
	{
		function = acos(exp(-(x + 1) * (x + 1))) + sin(x);

		if (fabs(function) < function_min)
		{
			function_min = function;
			x_min = x;
		}
	}
	*/

	std::cout << "The lowest value of function = " << function_min << "\t argument X = " << x_min << "\n";
	_getch();
	return 0;
}