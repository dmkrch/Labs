#include <stdio.h>
#include <iostream>
#define MAX 15
#define TRUE 1
#define FALSE 0
int decimal_to_three(int, int*);
void modif(int*, int);

int main()
{
	int number;
	int massive[MAX];
	int length;

	std::cout << "Enter the number ";
	std::cin >> number;

	length = decimal_to_three(number, massive);

	modif(massive, length);
}


int decimal_to_three(int number, int* numb_mass)
{
	int result;
	int total = 0;
	int temp;
	int number_temp;
	int number_temp_two;
	int k = 0;

	number_temp_two = number;

	while (number_temp_two != 0)
	{
		if (number_temp_two / 3 != 0)
		{
			number_temp_two /= 3;
			++total;
		}
		else
			number_temp_two /= 3;
	}

	for (int i = total; i >= 0; --i)
	{
		temp = number;
		number_temp = number;

		for (int k = 0; k < i; ++k)
			number_temp /= 3;

		for (int k = 0; k < i + 1; ++k)
			temp /= 3;

		numb_mass[k++] = number_temp - temp * 3;
	}
	return k;
}

void modif(int* massive, int length)
{
	int state = TRUE;
	int to_del = 0;

	for (int i = 0; state == TRUE; ++i)
	{
		if (massive[i] == 1 && massive[i + 1] == 0)
		{
			std::cout << "\n";
			massive[i] = 0;
			massive[i + 1] = 3;
			i = -1;
		}

		else if (massive[i] == 2 && massive[i + 1] == 0)
		{
			massive[i] = 1;
			massive[i + 1] = 3;
			i = -1;
		}
		else if (massive[i] == 3 && massive[i + 1] == 0)
		{
			massive[i] = 2;
			massive[i + 1] = 3;
			i = -1;
		}
		else
		{
			if (i == length)
				state = FALSE;
		}
	}

	state = TRUE;
	int i = 0;

		if (massive[0] == 0)
		{
			while (state == TRUE)
			{
				if (massive[i++] == 0)
					++to_del;
				else
					state = FALSE;
			}
		}
		else
			to_del = 0;


		std::cout << "Your number in special order ";
		for (int i = 0; i < length - to_del; ++i)
			std::cout << massive[i + to_del];
		std::cout << "\n\n";
}