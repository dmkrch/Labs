#include <iostream>
#include <stdio.h>
int main()
{
	int ln, **massive;

	std::cout << "Number of lines and columns in square matrix [x][x] ";
	std::cin >> ln;

	massive = new int *[ln]; // allocating memory

	for (int i = 0; i < ln; i++) // allocating memory
		massive[i] = new int[ln];

	std::cout << "Put numbers in massive "; // Putting numbers in massive
	for (int i = 0; i < ln; ++i)
		for (int m = 0; m < ln; ++m)
			std::cin >> massive[i][m];

	int max = massive[0][0];
	int min = max;

	for (int m = 0; m < ln; ++m) // main
		for (int n = 0; n < ln; ++n)
			if (n <= m || n >= ln - 1 - m)
			{
				if (massive[m][n] > max)
					max = massive[m][n];
				if (massive[m][n] < min)
					min = massive[m][n];
			}

	for (int i = 0; i < ln; ++i)
	{
		std::cout << "| ";
		for (int m = 0; m < ln; ++m)
			std::cout << massive[i][m] << " ";
		std::cout << "|\n";
	}

	std::cout << "\n\nThe biggest number in exact field is " << max << "\n";
	std::cout << "The minimum nubmer in exact field is " << min << "\n";
	
	for (int i = 0; i < ln; i++)  // clearing memory
		delete massive[i];

	delete[]  massive;
}