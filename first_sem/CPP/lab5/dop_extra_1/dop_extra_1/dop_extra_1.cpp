#include <stdio.h>
#include <iostream>

int function_f(int number);
int function_s(int low_lim , int up_lim);


int main()
{
	int low_lim;
	int up_lim;
	int tests;

	std::cout << "Enter number of tests "; // how many times to calculate function_s
	std::cin >> tests;

	for (int i = 0; i < tests; ++i)
	{
		std::cout << "\nEnter lower limit ";
		std::cin >> low_lim;
		std::cout << "Enter upper limit ";
		std::cin >> up_lim;

		if (low_lim >= 0 && up_lim >= 0)
			std::cout << "\nResult = " << function_s(low_lim, up_lim) << "\n";
		else
			std::cout << "\nWrong limits\n";
	}
}


int function_f(int number)
{
	if ((number % 10) > 0)
		return number % 10;
	else if (number == 0)
		return 0;
	else
		return function_f(number / 10);
}


int function_s(int low_lim, int up_lim)
{
	int sum = 0;
	for (int i = low_lim; i <= up_lim; ++i)
		sum += function_f(i);
		
	return sum;
}