#include <iostream>
#include <conio.h>
#include <iomanip>
#include <math.h>
int main()
{
	float n, m, x, K, Y;
	n = m = x = K = Y = 0;

	std::cout << "Enter x, K, n, m\n";
	std::cin >> x >> K >> n >> m;

	Y = 1.29 + K / fabs(n + m) + tan(x) * tan(x);

	std::cout << "Y is " << std::setprecision(3) << Y << std::endl;
	_getch();

	return 0;
}
