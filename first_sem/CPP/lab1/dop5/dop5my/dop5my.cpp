#include <iostream>
#include <conio.h>
#include <math.h>
#define PI 3.1415
int main()
{
	float lenght = 0, S = 0;
	do
	{
		std::cout << "Enter the lenght of circle ";
		std::cin >> lenght;
	} while (lenght < 0);
	S = lenght * lenght / (4 * PI);
	std::cout << "Square is " << S;
	_getch();
	return 0;
}