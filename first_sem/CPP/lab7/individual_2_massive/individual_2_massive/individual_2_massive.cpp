#include <stdio.h>
#include <iostream>

int main()
{
	char massive[8];
	char c;
	int length = 0;

	for (int i = 0; i < 8; ++i)
		massive[i] = 0;

	std::cout << "Enter your number in binary reversed code ";
	
	for (int i = 0; i < 8 && (c = getchar()) != '\n'; ++i, ++length)
		massive[i] = c;

	if (massive[0] == '0')
		massive[0] = '+';
	else
	{
		massive[0] = '-';

		for (int i = 1; i < 8; ++i)
		{
			if (massive[i] == '0')
				massive[i] = '1';
			else
				massive[i] = '0';
		}
	}

	std::cout << "Your number in straight form code ";
	for (int i = 0; i < length; ++i)
		std::cout << massive[i];
	std::cout << "\n\n";
}