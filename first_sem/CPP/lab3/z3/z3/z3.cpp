#include <iostream>
#include <conio.h>
#include <math.h>
int main()
{
	const float pi = 3.1415;
	int a = 0, m = 20, i = 0;
	float b = pi / 2, h = (b - a) / m, x = 0, function = 0;

	for (; x < b; ++i)
	{
		x = a + i * h;
		function = sin(x) - cos(x);

		std::cout << i <<")\targument x = " << x << "\tand\tfunction sin(x) - cos(x) = " << function << "\n";
	}
	_getch();
	return 0;
}
