#include <conio.h>
#include <iostream>
int main()
{
	float a = 0, b = 0, c = 0, y = 0;
	int n = 0;

	std::cout << "Put a, b, c, n, y\n";
	std::cin >> a >> b >> c >> n;

	switch (n)
	{
		case(2): y = b * c - a * a;
			break;
		case(3): y = a - b * c;
			break;
		case(7): y = a * a + c;
			break;
		case(56): y = b * c;
			break;
		default: y = (a + b) * (a + b) * (a + b);
	}

	std::cout << "\n y is " << y << "\n";

	_getch();
	return 0;

}