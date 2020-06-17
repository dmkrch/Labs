#include <stdio.h>
#include <iostream>
#define MAX 100
void getline(char line[], int maxline);


int main()
{
	char line[MAX];
	char line_new[MAX];

	getline(line, MAX);

	for (int i = 0, j = 0; line[i] != '\0'; ++i, ++j)
	{

		if (line[i] == 'c' || line[i] == 'C') // for c-element
		{
			if (line[i] == 'c')
				if (line[i + 1] == 'e' || line[i + 1] == 'i' || line[i + 1] == 'y')
					line_new[j] = 's';
				else
					line_new[j] = 'k';
			else
				if (line[i + 1] == 'e' || line[i + 1] == 'i' || line[i + 1] == 'y')
					line_new[j] = 'S';
				else
					line_new[j] = 'K';
		}

		else if (line[i] == 'q' || line[i] == 'Q')  // qu && q
			if (line[i] == 'q')
				if ((line[i + 1]) == 'u')
				{
					line_new[j++] = 'k';
					line_new[j] = 'v';
					++i;
				}
				else
					line_new[j] = 'k';
			else
				if ((line[i + 1]) == 'u')
				{
					line_new[j++] = 'K';
					line_new[j] = 'v';
					++i;
				}
				else
					line_new[j] = 'K';


		else if (line[i] == 'x' || line[i] == 'X') // for x-element
			if (line[i] == 'x')
			{
				line_new[j++] = 'k';
				line_new[j] = 's';
			}
			else
			{
				line_new[j++] = 'K';
				line_new[j] = 's';
			}


		else if (line[i] == 'w' || line[i] == 'W') // for w-element
			if (line[i] == 'w')
				line_new[j] = 'v';
			else
				line_new[j] = 'V';


		else if ((line[i] == 'p' || line[i] == 'P') && line[i + 1] == 'h') // for 'ph' element
			if (line[i] == 'p')
			{
				line_new[j] = 'f';
				++i;
			}
			else
			{
				line_new[j] = 'F';
				++i;
			}


		else if ((line[i] == 'y' || line[i] == 'Y') && line[i + 1] == 'o' && line[i + 2] == 'u') // for 'you' element
			if (line[i] == 'y')
			{
				line_new[j] = 'u';
				i += 2;
			}
			else
			{
				line_new[j] = 'U';
				i += 2;
			}


		else if ((line[i] == 'o' || line[i] == 'O') && line[i + 1] == 'o') // for 'oo' element
			if (line[i] == 'o')
			{
				line_new[j] = 'u';
				++i;
			}
			else
			{
				line_new[j] = 'U';
				++i;
			}


		else if ((line[i] == 'e' || line[i] == 'E') && line[i + 1] == 'e') // for 'ee' element
			if (line[i] == 'e')
			{
				line_new[j] = 'i';
				++i;
			}
			else
			{
				line_new[j] = 'I';
				++i;
			}
	

		else if ((line[i] == 't' || line[i] == 'T') && line[i + 1] == 'h') // for 'th' element
		{
			if (line[i] == 't')
				line_new[j] = 'z';
			else
				line_new[j] = 'Z';
			++i;
		}
		
		else // if no combinationo of elements
			line_new[j] = line[i];

			if (line[i + 1] == '\0')
				line_new[j + 1] = '\0';
	}

	for (int i = 0, j = 0; line_new[i] != '\0'; ++i, ++j) // for same elements
	{
		if (line_new[i] == line_new[i + 1])
		{
			if ((line_new[i] >= 'b' && line_new[i] <= 'd') || (line_new[i] >= 'f' && line_new[i] <= 'h') || (line_new[i] >= 'j' && line_new[i] <= 'n') || (line_new[i] >= 'p' && line_new[i] <= 't') || (line_new[i] >= 'v' && line_new[i] <= 'x') || (line_new[i] == 'z'))
				line[j] = line_new[i++];
		}
		else
			line[j] = line_new[i];


		if (line_new[i + 1] == '\0')
			line[j + 1] = '\0';
	}

	for (int i = 0; line[i] != '\0'; ++i)
		std::cout << line[i];
}


void getline(char line[], int maxline)
{
	int c;
	int i;

	std::cout << "Enter your line\n";

	for (i = 0; (c = getchar()) != EOF; ++i)
		line[i] = c;

	if (c == EOF)
		line[i] = '\0';
}
