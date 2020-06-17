#include <iostream>
#include <conio.h>
int main()
{
	float a = 0, b = 0, c = 0, d = 0, result = 0;

	std::cout << "enter a, b, c, d\n";
	std::cin >> a >> b >> c >> d;

	if (c >= d && a < d)
		result = a + b / c;
	else if (c < d && a >= d)
		result = a - b / c;
	else
		result = 0;

	std::cout << "Result = " << result << "\n";

	_getch();
	return 0;

}