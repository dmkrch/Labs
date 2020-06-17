#include <iostream>
#include <conio.h>
#include <math.h>
#define M 3
#define N 5
int main()
{
	int massive[M][N]; // M - lines and N - columns
	int i = 0;
	int k = 0;
	int sum = 0;
	int multiplier = 1;
	int sort = 0;


	std::cout << "Put numbers in massive\n";
	for (i = 0; i < M; ++i) // initialization
		for (k = 0; k < N; ++k)
			std::cin >> massive[i][k];
	std::cout << "\n\n";


	for (i = 0; i < M; ++i) 
		for (k = 0; k < N; ++k)
		{
			if (i == 0 && k == 0)
			{
				multiplier *= massive[i][k];
				continue;
			}
			if (i == 0 && k == 1)
			{
				sum += massive[i][k];
				continue;
			}
			else if (sort % 2 == 0)
				multiplier *= massive[i][k];
			else if (sort % 2 == 1)
				sum += massive[i][k];
			++sort;
		}

	std::cout << "Your massive is\n";
	for (i = 0; i < M; ++i)  //Showing the massive
	{	
		for (k = 0; k < N; ++k)
			std::cout << massive[i][k] << " ";
		std::cout << "\n";
	}

	std::cout << "\nSum of odd numbers in massive is " << sum << "\nand mutiplied even numbers of massive is " << multiplier << "\n";

	_getch();
	return 0;
}