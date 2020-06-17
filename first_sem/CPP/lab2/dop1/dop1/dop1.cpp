#include <conio.h>
#include <iostream>
#include <math.h>
int main()
{
	int digit = 0, sum = 0;
	double result = 0;

	std::cout << "Enter the number ";
	std::cin >> digit;

	sum = digit / 1000 + (digit - digit / 10 * 10);
	switch (sum)
	{
		case(3):
			result = tan(digit) * tan(digit) + sin(digit) * sin(digit) / 2.7;
			break;
		case(5):
			result = tan(digit) * tan(digit) + sin(digit) * sin(digit) / 2.7;
			break;
		case(7):
			result = log(abs(digit - 6));
			break;
		case(8):
			result = log(abs(digit - 6));
			break;
		case(9):
			result = log(abs(digit - 6));
			break;
		case(10):
			result = exp(0.2 * digit);
			break;
		default: 
			result = digit * sin(digit * digit);
	}

	std::cout << "\nResult is " << result << "\n";

	_getch();
	return 0;


}