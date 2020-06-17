#include <stdio.h>
#include <iostream>
#include <math.h>
#define MAX 10

void output_numb(int);
void three_to_decimal(int&);
void decimal_to_seven(int);
int get_digit(int, int);

int main()
{
	int number;
	int massive[MAX];

	std::cout << "Enter your number in 3-dim system\n";
	std::cin >> number;

	three_to_decimal(number);
	std::cout << number << "\n";
	decimal_to_seven(number);
}

void output_numb(int digit)
{
	if (digit == 10)
		digit = 'A';
	else if (digit == 11)
		digit = 'B';
	else if (digit == 12)
		digit = 'C';
	else if (digit == 13)
		digit = 'D';
	else if (digit == 14)
		digit = 'E';
	else if (digit == 15)
		digit = 'F';
	else if (digit == 16)
		digit = 'G';


	if (digit < 10)
		std::cout << digit;
	else
		std::cout << (char)digit;
}


void decimal_to_seven(int number)
{
	int result;
	int total = 0;
	int temp;
	int number_temp;
	int number_temp_two;

	number_temp_two = number;

	while (number_temp_two != 0)
	{
		if (number_temp_two / 17 != 0)
		{
			number_temp_two /= 17;
			++total;
		}
		else
			number_temp_two /= 17;
	}

	std::cout << "\nYour number in 17-dim = ";
	for (int i = total; i >= 0; --i)
	{
		temp = number;
		number_temp = number;

		for (int k = 0; k < i; ++k)
			number_temp /= 17;

		for (int k = 0; k < i + 1; ++k)
			temp /= 17;

		result = number_temp - temp * 17;
		output_numb(result);
	}
	std::cout << "\n\n";
}


void three_to_decimal(int& number)
{
	int i;
	int temp = number;
	int result = 0;
	int digit;

	for (i = -1; temp != 0; ++i)
		temp /= 10;

	for (; i >= 0; --i)
	{
		digit = get_digit(number, i + 1);
		result += pow(3, i) * digit;
	}

	number = result;
}


int get_digit(int number, int digit)
{
	int result;

	number /= pow(10, digit - 1);
	result = number - number / 10 * 10;

	return result;
}