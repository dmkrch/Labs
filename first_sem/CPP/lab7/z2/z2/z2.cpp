#include <stdio.h>
#include <iostream>
#include <math.h>

#define TRUE 1
#define FALSE 0

int decimal_to_bin(int*, int);		    // transforms decimal number to bin equalent and add it to massive
void alloc_mem(int**, int);				// allocates memory to massive according to the entered number
int arr_to_int(int*, int);				// transforms massive to int equalent
int verification(int*, int*, int, int);	// checking if dec_massive is suffix of bin_massive
void output(int*, int);				    // output of massive

int main()
{
	int number;
	int state = TRUE;
	int curr_number = 0;
	int* bin_massive = nullptr;
	int* dec_massive;
	int size;
	int size_bin;
	int lim;
	unsigned long long arr;
	int iter = 0;
	int suffix;

	std::cout << "Enter n "; 
	std::cin >> number;

	for (int i = 1; state == TRUE; ++i) // 1 1
	{
		curr_number = i;

		alloc_mem(&dec_massive, curr_number);            
		size = decimal_to_bin(dec_massive, curr_number); 
		arr = arr_to_int(dec_massive, size);             
		alloc_mem(&bin_massive, arr);                    
		size_bin = decimal_to_bin(bin_massive, arr);	

		suffix = verification(dec_massive, bin_massive, size, size_bin);
		if (suffix == TRUE)
			++iter;

		if (iter == number)
		{
			std::cout << "\nThis is decimal massive  ";
			output(dec_massive, size);

			std::cout << "\nand this is bin massive  ";
			output(bin_massive, size_bin);
			std::cout << "\n";
			state = FALSE;
		}
	}
}


void alloc_mem(int** massive, int number)
{
	unsigned long long temp = number;
	int i;

	for (i = 0; temp > 0; ++i)
		temp /= 2;

	*massive = new int[i];
}


int decimal_to_bin(int* numb_mass, int number)
{
	int result;
	int total = 0;
	int temp = number;
	int number_temp;
	int number_temp_two;
	int k = 0;

	number_temp_two = number;

	while (number_temp_two != 0)
	{
		if (number_temp_two / 2 != 0)
		{
			number_temp_two /= 2;
			++total;
		}
		else
			number_temp_two /= 2;
	}

	for (int i = total; i >= 0; --i)
	{
		temp = number;
		number_temp = number;

		for (int k = 0; k < i; ++k)
			number_temp /= 2;

		for (int k = 0; k < i + 1; ++k)
			temp /= 2;

		numb_mass[k++] = number_temp - temp * 2;
	}
	return k;
}


int arr_to_int(int* massive, int size)
{
	unsigned long long number = 0;
	int k;

	for (int i = 0; i < size; ++i)
		number += massive[i] * pow(10, size - 1 - i);

	return number;
}


int verification(int* dec_massive, int* bin_massive, int size_dec, int size_bin)
{
	int temp = 0;

	for (int j = size_dec - 1, k = size_bin - 1; j >= 0; --j, --k)
		if (dec_massive[j] != bin_massive[k])
			++temp;

	if (temp == 0)
		return TRUE;
	else
		return FALSE;
}


void output(int* dec_massive, int size)
{
	for (int i = 0; i < size; ++i)
		std::cout << dec_massive[i];
}