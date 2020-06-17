#include <iostream>
#include <stdio.h>
#define MAX 15
int fact(int n);
int getword(char word[]);
void output_word(char word[]);

int main()
{
	char word[MAX];
	int length;
	int temp[123];
	char symb;
	int result;

	for (int i = 0; i < 123; ++i)
		temp[i] = 0;

	std::cout << "Enter your word\n";
	length = getword(word);   // hello --- length = 5;

	for (int i = 0; i < length; ++i) // getting temporary massive with counted symbols
	{
		if (temp[word[i]] == 0)
		{
			symb = word[i];

			for (int j = 0; j < length; ++j)
				if (word[j] == symb)
					++temp[symb];
		}
	}

	result = fact(length);

	for (int i = 65; i < 123; ++i)
		if (temp[i] != 0)
			result /= fact(temp[i]);

	std::cout << result << " varients\n\n";
}


int fact(int n)
{
	if (n == 1)
		return 1;
	else
		return n * fact(n - 1);
}


int getword(char word[])
{
	char c;
	int i;

	for (i = 0; (c = getchar()) != '\n' && i != MAX; ++i)
		word[i] = c;

	word[i++] = '\n';
	word[i] = '\0';
	return i - 1;
}