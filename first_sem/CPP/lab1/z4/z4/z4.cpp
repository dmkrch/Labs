#include <conio.h>
#include <iostream>

int main()
{
	int a, b;
	std::cout << "enter 1st number ";
	std::cin >> a;
	std::cout << "enter 2nd number ";
	std::cin >> b;
	a = a + b;
	b = a - b;
	a = a - b;
	std::cout << "now a is " << a << "\nand b is " << b;
	_getch();
	return 0;
}