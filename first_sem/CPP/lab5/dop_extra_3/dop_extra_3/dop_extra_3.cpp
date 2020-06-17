#include <stdio.h>
#include <iostream>
int divisor(int);

int main()
{
	int n;
	int result = 0;


	std::cout << "Enter n ";
	std::cin >> n;

	for (int i = 1; i <= n; ++i)
		result += divisor(i);

	std::cout << "\nResult is " << result << "\n\n";
}

int divisor(int number)
{
	int div = 0;

	for (int i = 1; i <= number; ++i)  // finding minimum divisor of number
	{
		if (number % i == 0)  // checking if divisor is integer number
		{
			div = number / i; // setting divisor

			if (div % 2 == 1) // checking if divisor is odd number
				return div;
		}
	}
}

