#include <conio.h>
#include <iostream>
int main()
{
	int h1 = 0, min1 = 0, h2 = 0, min2 = 0, H = 0, M = 0;

	std::cout << "enter current time\nhours: ";
	std::cin >> h1;
	std::cout << "minutes:";
	std::cin >> min1;
	std::cout << "\nend time\nhours: ";
	std::cin >> h2;
	std::cout << "minutes:";
	std::cin >> min2;

	if ((h2 - h1) > 0)
	{
		h1 = h1 * 60 + min1;
		h2 = h2 * 60 + min2;
		H = (h2 - h1) / 60;
		M = (h2 - h1) % 60;
	}
	else
	{
		h1 = 23 - h1;
		min1 = 60 - min1;
		h2 = h2 * 60 + min2;
		h2 = h2 + h1 * 60 + min1;
		H = h2 / 60;
		M = h2 % 60;
	}

	std::cout << "\ntime of work: " << H << " hours and " << M << " minutes\n";
	
	_getch();
	
	return 0;
}
