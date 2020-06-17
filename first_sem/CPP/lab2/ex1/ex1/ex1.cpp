#include <iostream>
#include <conio.h>
int main()
{
	char sign;
	int x = 0, y = 0, z = 0;

	std::cout << "Put x and y ";
	std::cin >> z >> y;
sign:	std::cout << "Put ur sugn ";
	std::cin >> sign;

	if (sign == '-')
		x = y - z;
	else if (sign == '+')
		x = y + z;
	else if (sign == '*')
		x = y * z;
	else
	{
		std::cout << "Wrong sign\n";
		goto sign;
	}
	std::cout << x;
	//std::cout << "y " << sign << " x is " << x;
}