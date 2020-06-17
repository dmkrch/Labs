#include <conio.h>
#include <iostream>
int main()
{
	float a = 0, b = 0, z = 0;
	bool Y;

	std::cout << "enter a ";
	std::cin >> a;
	std::cout << "enter b ";
	std::cin >> b;

	Y = a >= b;
	Y ? std::cout << "the biggest is " << a : std::cout << "the biggest is " << b;
}