#include <iostream>
#include <conio.h>
int main()
{
	int two_digits = 0, digit = 0, i = 0, result = 0;

	for (i = 99; i <= 200; ++i)
	{
		two_digits = i / 10;
		digit = i - two_digits * 10;

		result = two_digits * two_digits - digit * digit;

		if (i == result)
			std::cout << i << "\t";
	}

	_getch();
	return 0;
}


