#include <stdio.h>
#include <math.h>
#include <iostream>

#define MAX 50

int fact(int a);

int main()
{
	double ideal_sin = 0;
	double actual_sin = 0;
	double epsilon = 0;
	double n = 1;
	double x = 0;

	do
	{
		printf("enter x: ");
		scanf_s("%lf", &x);
	} while (x > 15 || x < -4);

	do
	{
		printf("enter epsilon: ");
		scanf_s("%lf", &epsilon);
	} while (epsilon >= 1 || epsilon < 0.1);


	ideal_sin = sin(x);

	while (fabs(ideal_sin - actual_sin) >= epsilon)
	{
		actual_sin += pow(-1.0, n - 1.0) * pow(x, 2.0 * n - 1.0) / fact(2.0 * n - 1.0);
		++n;
	}

	std::cout << "ideal_sin = " << ideal_sin << " and actual_sin = " << actual_sin << "  n = " << n << "\n";

}

int fact(int a)
{
	if (a > 1)
		return (a * fact(a - 1));
	else if (a == 0)
		return 1;
	else if (a < 0)
		return 0;
	else
		return 1;
}