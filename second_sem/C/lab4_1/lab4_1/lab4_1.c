#include <stdio.h>
#include <stdlib.h>
#define MAX 100

bool getline(char** line);
int gettext(char*** text);
void output_text(char** text, int lines);
void delete_symbol(char** text, int column_index);
int get_line_length(char* text);

int main()
{
	char** text = nullptr;
	int lines = 0;
	char curr_symbol = 0;

	lines = gettext(&text); // \n\n\n - 4 lines

	int alphabet[52];

	for (int i = 0; i < 52; ++i)
		alphabet[i] = 0;

	for (int i = 0; i < lines - 1; ++i)
		for (int k = 0; text[i][k] != '\0'; ++k)
		{
			curr_symbol = text[i][k];

			if (curr_symbol > 64 && curr_symbol < 91)
			{
				if (alphabet[curr_symbol - 65] == 0)
					++alphabet[curr_symbol - 65];
				else
				{
					delete_symbol(&text[i], k);
					--k;
				}
			}
			else if (curr_symbol > 96 && curr_symbol < 123)
			{
				if (alphabet[curr_symbol - 71] == 0)
					++alphabet[curr_symbol - 71];
				else
				{
					delete_symbol(&text[i], k);
					--k;
				}
			}
			else
				continue;
		}

	output_text(text, lines);

	return 0;
}

bool getline(char** line)
{
	char c;
	int i = 0;

	for (i = 1; (c = getchar()) != EOF && c != '\n'; ++i)
	{
		char* temp = (char*)malloc(i * sizeof(char));

		for (int k = 0; k < i - 1; ++k)
			*(temp + k) = *(*line + k);

		*line = temp;


		*(*line + i - 1) = c;
	}

	if (c == '\n')
	{
		char* temp = (char*)malloc((i + 1) * sizeof(char));

		for (int k = 0; k < i - 1; ++k)
			*(temp + k) = *(*line + k);

		*line = temp;


		*(*line + i - 1) = c;
		*(*line + i) = '\0';
	}

	if (c == EOF)
	{
		return false;
	}

	return true;
}

int gettext(char*** text)
{
	bool choice = true;
	int i = 0;

	while (1)
	{
		if (choice == true)
		{

			char** temp = (char**)malloc((i + 1) * sizeof(char*)); // allocating memory to temp , then copy and then text = temp

			for (int k = 0; k < i; ++k)
				*(temp + k) = *(*text + k);

			*text = temp;

			choice = getline(*text + i);
		}
		else
			break;

		++i;
	}

	return i;
}

void output_text(char** text, int lines)
{
	for (int i = 0; i < lines - 1; ++i)
	{
		for (int k = 0; text[i][k] != '\0'; ++k)
			printf("%c", text[i][k]);
	}
}

void delete_symbol(char** text, int column_index)
{
	char* temp = nullptr;
	int line_length = 0;

	temp = (char*)malloc((get_line_length(*text) - 1) * sizeof(char)); // allocation memory for temp array

	int iter_temp = 0;
	int iter_text = 0;

	while (iter_text < get_line_length(*text))
	{
		if (iter_text != column_index)
			*(temp + iter_temp) = *(*text + iter_text);

		else
			--iter_temp;


		++iter_temp;
		++iter_text;
	}


	*text = temp;
}

int get_line_length(char* text)
{
	int i = 0;

	while (text[i] != '\0')
		++i;

	return i + 1;
}