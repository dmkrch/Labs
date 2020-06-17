#include <conio.h>
#include <iostream>
#include <math.h>
int main()
{
	float Side = 0;
	std::cout << "Enter side of cube ";
	std::cin >> Side;
	std::cout << "V = " << pow(Side, 3);
	std::cout << "\nAnd S = " << Side * Side * 6 << "\n";
	_getch();
	return 0;

}