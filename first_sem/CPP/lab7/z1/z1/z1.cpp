#include <stdio.h>
#include <iostream>
#define div1 11
#define div2 31
#define div3 113
int main()
{
	int number;
	int number_copy;
	int divisor;

	std::cout << "Enter your nubmer ";
	std::cin >> number;

	number_copy = number;

	while (number_copy > 0)
		number_copy -= div1;
	if (number_copy == 0)
		std::cout << "\ncan be divided by 11";
	else
		std::cout << "\ncan't be divided by 11";

	number_copy = number;

	while (number_copy > 0)
		number_copy -= div2;
	if (number_copy == 0)
		std::cout << "\ncan be divided by 31";
	else
		std::cout << "\ncan't be divided by 31";


	number_copy = number;

	while (number_copy > 0)
		number_copy -= div3;
	if (number_copy == 0)
		std::cout << "\ncan be divided by 113\n";
	else
		std::cout << "\ncan't be divided by 113\n";
}