#include <iostream>
#include <conio.h>
#include <math.h>
int main()
{
	float x1 = 0, x2 = 0, k = 0, m = 0, result = 0;

	std::cout << "put x1, x2, m\n";
	std::cin >> x1 >> x2 >> m;

	k = pow(cos(x1 * x1), 3) + sin(pow(x2, 3)) * sin(pow(x2, 3));
	
	if (k >= 1)
		result = k * k - exp(m);
	else
		result = pow(k, 3) + pow(m, 0.2);
	std::cout << "Result = " << result << "\n";

	_getch();
	return 0;
}