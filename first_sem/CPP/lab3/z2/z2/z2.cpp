#include <conio.h>
#include <iostream>
#include <math.h>
int main()
{
	float sum = 0;
	const float limit = 0.001;
	int n = 0;

	do
	{
		++n;
		sum += pow(0.5, n) + pow(1.0 / 3, n);
	} 
	while ((pow(0.5, n) + pow(1.0 / 3, n)) >= limit);

	std::cout << "Result is " << sum << "\nn = " << n << "\n";

	_getch();
	return 0;

}