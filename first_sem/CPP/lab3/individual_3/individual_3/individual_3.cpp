#include <conio.h>
#include <iostream>
#include <math.h>
int main()
{
	float function_f = 0, lim_bot = 0, lim_up = 0, step = 0, x = 0;

	do
	{
		std::cout << "Enter the limit of argument in bottom ";
		std::cin >> lim_bot;
		std::cout << "Enter the upper limit of argument ";
		std::cin >> lim_up;
	}
	while (lim_bot >= lim_up);

	std::cout << "Enter the change of argument (step) ";
	std::cin >> step;

	for (x = lim_bot; x <= lim_up; x += step)
	{
		function_f = 1.0 / (1.0 + sin(x));
		std::cout << "argument(x) =  " << x << "\tand function 1 / (1 + sin(x)) =  " << function_f << "\n";
	}

	_getch();
	return 0;
}

