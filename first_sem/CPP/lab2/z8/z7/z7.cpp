#include <iostream>
#include <conio.h>
int main()
{
	int last_digit = 0, cash_first = 0, cash_add = 0, sum = 0;

	std::cout << "enter the first amount of money\n";
	std::cin >> cash_first;
	std::cout << "enter the add of money\n";
	std::cin >> cash_add;

	sum = cash_first + cash_add;

	last_digit = sum - 10 * (sum / 10);

	switch (last_digit)
	{
		case(1): std::cout << "Total amount of money is " << sum << " rybl'\n";
			break;
		case(2): std::cout << "Total amount of money is " << sum << " rybl9\n";
			break;
		case(3): std::cout << "Total amount of money is " << sum << " rybl9\n";
			break;
		case(4): std::cout << "Total amount of money is " << sum << " rybl9\n";
			break;
		default: std::cout << "Total amount of money is " << sum << " ryblei\n";
	}

	_getch();
	return 0;
}
