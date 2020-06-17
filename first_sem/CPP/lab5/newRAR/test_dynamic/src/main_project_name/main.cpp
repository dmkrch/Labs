#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "dynamic_lib_project_name/dynamic_lib.h"


int main()
{
	int** massive_a;
	int** massive_b;
	int** massive_c;
	int ord;


	std::cout << "Enter the order of quadrant matrix ";
	std::cin >> ord;


	massive_a = new int* [ord]; // allocating memory for A massive
	for (int i = 0; i < ord; ++i)
		massive_a[i] = new int[ord];

	massive_b = new int* [ord]; // allocating memory for B massive
	for (int i = 0; i < ord; ++i)
		massive_b[i] = new int[ord];

	massive_c = new int* [ord]; // allocating memory for C massive
	for (int i = 0; i < ord; ++i)
		massive_c[i] = new int[ord];

	for (int m = 0; m < ord; ++m) // input elements in A massive
		for (int n = 0; n < ord; ++n)
		{
			std::cout << "massive_A [" << m << "][" << n << "] = ";
			std::cin >> massive_a[m][n];
		}


	set_values_to_massive_b(massive_a, massive_b, ord);
	set_values_to_massive_c(massive_a, massive_b, massive_c, ord);

	std::cout << "\nYour massive A is\n";
	output_massive(massive_a, ord);
	std::cout << "\nYour massive B is\n";
	output_massive(massive_b, ord);
	std::cout << "\nYour massive C is\n";
	output_massive(massive_c, ord);
}

