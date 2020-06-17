#include <stdio.h>
#include <iostream>
int main()
{
	int** massive;
	int** massive_ln;
	int** massive_cl;

	int ln;
	int cl;

	std::cout << "Number of lines in matrix "; // Getting number of lines and columns of massive
	std::cin >> ln;
	std::cout << "Number of columns in matrix ";
	std::cin >> cl;

	massive = new int* [ln]; // Allocating memory for massive
	for (int i = 0; i < ln; ++i)
		massive[i] = new int[cl];


	massive_ln = new int* [ln]; // Allocating memory for transparented massive of lines
	for (int i = 0; i < ln; ++i)
		massive_ln[i] = new int[cl];


	massive_cl = new int* [ln]; // Allocating memory for transparented massive of columns
	for (int i = 0; i < ln; ++i)
		massive_cl[i] = new int[cl];



	std::cout << "Put numbers in matrix\n\n"; // Inputting numbers 
	for (int i = 0; i < ln; ++i)
		for (int j = 0; j < cl; ++j)
			std::cin >> massive[i][j];


	std::cout << "\n\nYour two dimensial matrix is\n"; // Showing the massive
	for (int i = 0; i < ln; ++i)
	{
		for (int j = 0; j < cl; ++j)
			std::cout << massive[i][j] << " ";
		std::cout << "\n";
	}

	std::cout << "\n\nTransparented matrix according to second diagonal is\n"; // Showing the transporated massive
	for (int i = cl - 1; i >= 0; --i)
	{
		for (int j = ln - 1; j >= 0; j--)
			std::cout << massive[j][i] << " ";
		std::cout << "\n";
	}
	std::cout << "\nMassive of lines:\n";

	int j = 0;
	int line = 0;

	for (int i = 0; i < ln; ++i)
		for (j = 0, line = cl - 1; j < cl; ++j)
			massive_ln[i][j] = line--;

	std::cout << "\n\nYour two dimensial matrix of lines is\n"; // Showing the massive of lines
	for (int i = 0; i < ln; ++i)
	{
		for (int j = 0; j < cl; ++j)
			std::cout << massive_ln[i][j] << " ";
		std::cout << "\n";
	}

	int col = 0;

	for (int i = 0; i < ln; ++i)
		for (j = 0, col = ln - 1 - i; j < cl; ++j)
			massive_ln[i][j] = col;

	std::cout << "\n\nYour two dimensial matrix of columns is\n"; // Showing the massive of columns
	for (int i = 0; i < ln; ++i)
	{
		for (int j = 0; j < cl; ++j)
			std::cout << massive_ln[i][j] << " ";
		std::cout << "\n";
	}
}