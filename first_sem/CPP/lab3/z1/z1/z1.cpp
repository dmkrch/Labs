#include <conio.h>
#include <iostream>
int main()
{
	int a = 0, b = 0, sum = 0, i = 1;

	while (i <= 30)
	{
		if ((i % 2) == 1)
			a = i;
		else
			a = i / 2;

		if ((i % 2) == 0)
			b = i * i * i;
		else
			b = i * i;

		sum += (a - b) * (a - b);
		++i;
	}
	std::cout << "Result is " << sum;

	_getch();
	return 0;
}
