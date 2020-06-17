#include <stdio.h>
#include <stdlib.h>

#define three 3 
#define five 5
#define MAX 50

int main()
{

	int sum = 0;
	int temp_sum = 0;
	int max_five = 0;
	int counter = 0;
	int amount_of_three = 0;
	int amount_of_five = 0;
	int varient = 0;
	char ch = 0;
	char input_line[MAX];


	do
	{
		printf("Write your sum in roubles  ");
		counter = 0;
		int i = 0;

		for (i = 0; (ch = getchar()) != '\n'; ++i)
		{
			input_line[i] = ch;

			if (ch < 47 || ch > 58 || ch == '\\' || i > 3)
				++counter;
		}

		if ((ch == '\n') && (counter == 0))
		{
			input_line[i] = '\0';

			sum = atoi(input_line);

			if (sum > 7)
				break;
			else
				continue;
		}
	} while (1);


	max_five = sum / five;

	for (int i = max_five; i >= 0; --i)
	{
		temp_sum = sum - five * i;

		if (temp_sum % three == 0)
		{
			amount_of_three = temp_sum / three;
			amount_of_five = (sum - amount_of_three * three) / five;
			++varient;
			printf("%dst varient\n\tthrees: %d\n\tfives: %d\n\n", varient, amount_of_three, amount_of_five);
		}

	}
}