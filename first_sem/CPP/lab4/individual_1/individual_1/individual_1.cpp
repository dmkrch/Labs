#include <conio.h>
#include <iostream>
#define SIZE 10
#define MAX 100

int main()
{
	int massive[SIZE];
	int massive_digit[MAX];
	int massive_new[SIZE];
	int curr_number = 0;
	int i = 0;
	int digit_del = 0;

	for (i = 0; i < MAX; ++i)
		massive_digit[i] = 0;

	std::cout << "Put numbers in massive\n";


	for (i = 0; i < SIZE; ++i)
	{
		std::cout << "i_" << i << " = ";
		std::cin >> massive[i];
	}

	for (int j = 0, i = 0; i < SIZE; ++i)
	{
		curr_number = massive[i];
		++massive_digit[massive[i]];

		if (massive_digit[massive[i]] == 1)
			massive_new[j++] = massive[i];
		else
			++digit_del;
	}

	std::cout << "\n\nYour new massive is\n";

	for (i = 0; i < SIZE - digit_del; ++i)
		std::cout << "i_" << i << " = " << massive_new[i] << "\n";

	_getch();
	return 0;
}

