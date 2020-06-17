#include <stdio.h>
#include <iostream>
#define MAX 20

int get_word(char word[]);
void check_annagram(char word_one[], char word_two[], int length_one);
void output_word(char word[]);

int main()
{
	char word_one[MAX];
	char word_two[MAX];
	int length_one;
	int length_two;


	std::cout << "Enter your first word\n";
	length_one = get_word(word_one);
	std::cout << "\nEnter your second word\n";
	length_two = get_word(word_two);


	if (length_one == length_two)
		check_annagram(word_one, word_two, length_one);
	else
		std::cout << "\nThe words are not annagrams\n\n";

	system("pause");
	return 0;
}


int get_word(char word[])
{
	char c;
	int i = 0;

	while ((c = getchar()) != '\n')
		word[i++] = c;

	word[i++] = '\n';
	word[i] = '\0';
	return i;
}


void check_annagram(char word_one[], char word_two[], int length)
{
	int temp = 0;
	int j = length - 2;

	for (int i = 0; i < length - 1; ++i, --j)
		if (word_one[i] != word_two[j])
			++temp;

	if (temp == 0)
	{
		std::cout << "\nThe words ";
		output_word(word_one);
		std::cout << " and ";
		output_word(word_two);
		std::cout << " are annagrams\n\n";
	}
	else
		std::cout << "\nThe words are not annagrams\n\n";
}


void output_word(char word[])
{
	for (int i = 0; word[i] != '\n'; ++i)
		std::cout << word[i];
}