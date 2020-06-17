#include <stdio.h>
#include <iostream>
#include <math.h>
#define MAX 200
int getline(char line[], int maxline);


int main()
{
	int L;
	int length1;
	int length2;
	int m;
	char prefix[MAX];
	char suffix[MAX];
	int result;
	int delta = 0;
	int j;


	std::cout << "Enter prefix\n";
	length1 = getline(prefix, MAX);
	std::cout << "Enter suffix\n";
	length2 = getline(suffix, MAX);
	std::cout << "Enter length of line\n";
	std::cin >> L;
	std::cout << "Enter 'm'\n";
	std::cin >> m;

	if (L - (length1 + length2) > 0)
	{
		result = pow(26, L - (length1 + length2));
		std::cout << result % m * 2;
	}

	else if (L - (length1 + length2) == 0)
	{
		result = 1;
		std::cout << result * 2;
	}

	else
	{
		for (int i = length2 - 1; i >= 0; --i)
		{
			j = i;

			for (int m = length1 - 1; j >= 0; --m, --j)
			{
				if ((prefix[m] == suffix[j]) && j != -1)
					++delta;

				else
				{
					delta = 0;
					break;
				}

				if (j - 1 == -1)
				{
					i = -1;
					break;
				}
			}
		}
		
		if (length1 + length2 - delta == L)
		{
			result = 1;
			std::cout << "Result is " << result;
		}
		else
		{
			result = 0;
			std::cout << "Result is " << result * 2;
		}
	}
}

int getline(char line[], int maxline)
{
	int c;
	int i;

	for (i = 0; i < MAX && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;

	if (c == '\n')
		line[i++] = c;
	line[i] = '\0';
	return i - 1;
}