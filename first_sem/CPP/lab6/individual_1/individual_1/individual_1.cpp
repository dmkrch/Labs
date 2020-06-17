#include <stdio.h>
#include <iostream>
#define MAX 80
int getline(char line[], int maxline);
int amount_of_brackets(char line[]);

int main()
{
	char line[MAX];
	int result;
	int maxline = MAX;

	int length = getline(line, maxline);

	result = amount_of_brackets(line);
		
	std::cout << "Number of brackets = " << result << "\n\n";
	system("pause");
	return 0;
}

int getline(char line[], int maxline)
{
	int c;
	int i;

	std::cout << "Enter your line\n";

	for (i = 0; i < MAX && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;

	if (c == '\n')
		line[i++] = c;
	line[i] = '\0';
	return i;
}

int amount_of_brackets(char line[])
{
	int res = 0;
	for (int i = 0; line[i] != '\n'; ++i)
	{
		if (line[i] == '(' || line[i] == ')' || line[i] == '[' || line[i] == ']' || line[i] == '{' || line[i] == '}' || line[i] == '<' || line[i] == '>')
			++res;
	}
	return res;
}