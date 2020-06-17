#include <stdio.h>
#include <iostream>
#define OUT 0
#define IN 1
#define MAX 80

void getline(char line[], int maxline);
void transm_word(char temp_line[], char line_res[]);
int j = 0;


int main()
{
	int state = OUT;
	char line[MAX];
	char temp_line[MAX];
	char line_res[MAX];
	char temp_symb;
	int k = 0;

	getline(line, MAX);

	for (int i = 0; line[i] != '\0'; ++i)
	{
		if ((line[i] != ' ') && (state == OUT)) // the moment when me enter the word. Variable i is already "in" word, while state is still "OUT".
		{
			temp_symb = line[i];
			state = IN;
		}

		else if ((line[i] == ' ' || line[i] == '\t' || line[i] == '\n') && (state == IN)) // the moment when we left the word. Variable i is already outside word
		{																				  // while state is still "IN".									
			if (line[i - 1] == temp_symb)
			{
				temp_line[k] = ' ';
				transm_word(temp_line, line_res);
				k = 0;
			}
			else
				k = 0;
			state = OUT;
		}

		if (state == IN)
			temp_line[k++] = line[i];
	}

	line_res[j] = '\n';

	std::cout << "Result is\n\n";

	for (int i = 0; line_res[i] != '\n'; ++i)
		std::cout << line_res[i];
}


void getline(char line[], int maxline)
{
	int c;
	int i;

	std::cout << "Enter your line\n";

	for (i = 0; i < MAX && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;

	if (c == '\n')
		line[i++] = c;
	line[i] = '\0';
}


void transm_word(char temp_line[], char line_res[])
{
	for (int i = 0; temp_line[i] != ' '; ++i, ++j)
		line_res[j] = temp_line[i];

	line_res[j++] = ' ';
}