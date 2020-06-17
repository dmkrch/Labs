#include <stdio.h>
#include <iostream>
#include <iomanip>

void output_second_order_massive(int** massive, int ln, int cl);
void output_one_order_massive(int* new_massive, int ln);
float addition(int* new_massive, int ln);

int main()
{
	int** massive; // ln == lines		cl == columns
	int* new_massive;

	int ln;
	int cl;
	int iter = 0;
	int memory = 0;
	float result;

	std::cout << "Enter number of lines ";
	std::cin >> ln;

	std::cout << "Enter number of columns ";
	std::cin >> cl;

	massive = new int* [ln]; // allocating memory for massive
	for (int m = 0; m < ln; ++m)
		massive[m] = new int[cl];


	for (int m = 0; m < ln; ++m)
		for (int n = 0; n < cl; ++n)
		{
			std::cout << "massive [" << m << "][" << n << "] = ";
			std::cin >> massive[m][n];
		}

	for (int m = 0; m < ln; ++m) // counting how many elements should be in new_massive
		for (int n = 0; n < cl; ++n)
		{
			if (massive[m][n] % 2 == 1 && (n % 2 == 1 || n == 1))
				++memory;
		}

	new_massive = new int[memory]; // allocating memory for new_massive

	for (int m = 0; m < ln; ++m)
		for (int n = 0; n < cl; ++n)
		{
			if (massive[m][n] % 2 == 1 && (n % 2 == 1 || n == 1))
				new_massive[iter++] = massive[m][n];
		}


	output_second_order_massive(massive, ln, cl);
	output_one_order_massive(new_massive, memory);
	result = addition(new_massive, memory);

	std::cout << "Average of addition = " << result << "\n\n";
}


void output_second_order_massive(int** massive, int ln, int cl)
{
	std::cout << "\n\nYour massive is\n";
	for (int m = 0; m < ln; ++m)
	{
		for (int n = 0; n < cl; ++n)
			std::cout << massive[m][n] << " ";
		std::cout << "\n";
	}
	std::cout << "\n";

}


void output_one_order_massive(int* new_massive, int ln)
{

	if (ln != 0)
	{
		std::cout << "Your dinamic new massiv is\n";
		for (int m = 0; m < ln; ++m)
			std::cout << new_massive[m] << " ";
		std::cout << "\n\n";
	}
	else
		std::cout << "no needed elements\n\n";
}


float addition(int* new_massive, int ln)
{
	float sum = 0;

	for (int i = 0; i < ln; ++i)
		sum += new_massive[i];

	return sum / ln;
}