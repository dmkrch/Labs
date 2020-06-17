#include <iostream>
#include <conio.h>
#include <math.h>
#define G 9.806
int main()
{
	G = 10;
	float height = 0, time = 0;
	do
	{
		std::cout << "Put the height ";
		std::cin >> height;
	} 
	while (height < 0);
	time = sqrt(2 * height / G);
	std::cout << "time of falling " << time;
	std::cout << G;
	_getch();
	return 0;
}

