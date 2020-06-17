#include "dynamic_lib.h"
#include <iostream>
#include <iomanip>


void set_values_to_massive_b(int** massive_a, int** massive_b, int ord)
{
	for (int m = 0; m < ord; ++m)
		for (int n = 0; n < ord; ++n)
		{
			if (massive_a[m][n] >= 0)
				massive_b[m][n] = massive_a[m][n];
			else
				massive_b[m][n] = 1;
		}
}


void output_massive(int** massive, int ord)
{
	for (int m = 0; m < ord; ++m)
	{
		for (int n = 0; n < ord; ++n)
			std::cout << std::setw(3) << massive[m][n] << " ";
		std::cout << "\n";
	}
}


void set_values_to_massive_c(int** massive_a, int** massive_b, int** massive_c, int ord)
{
	for (int m = 0; m < ord; ++m)
		for (int n = 0; n < ord; ++n)
			massive_c[m][n] = massive_a[m][n] + massive_b[m][n];
}
