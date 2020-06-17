#include <iostream>
#include <conio.h>
int main()
{
	float a = 0, b = 0, c = 0;

	std::cout << "Enter 3 numbers\n";
	std::cin >> a >> b >> c;
	
	if (a > 1 && a < 3)
		std::cout << "a is in (1,3) interval\n";
	if (b > 1 && b < 3)
		std::cout << "b is in (1,3) interval\n";
	if (c > 1 && c < 3)
		std::cout << "c is in (1,3) interval\n";

	_getch();
	return 0;
}