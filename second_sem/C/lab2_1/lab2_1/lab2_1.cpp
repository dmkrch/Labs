#include <stdio.h>
#include <iostream>

#define MAX 50
#define PI 3.14

int result_of_check();

int main()
{
	int choice = 0;
	int radius = 0;
	int angle = 0;
	float area = 0;
	float circle_length = 0;
	float area_sector = 0;
	float square_side = 0;
	float cone_capacity = 0;
	char input_line[MAX];

	while (1)
	{
		std::cout << "\n----------------------------------------\n|  #1 Enter radius of circle\t       |\n|  #2 Show a circle's area\t       |\n|  #3 Enter angle and show sector      |\n|  #4 Show a circle's length\t       |\n|  #5 Show a square's side in circle   |\n|  #6 Show a cone's capacity\t       |\n|  #7 SHOW INFO OF PROGRAM AND AUTHOR  |\n|  #8 exit\t\t\t       |\n----------------------------------------\n";
		choice = result_of_check();

		switch (choice)
		{
		case 1:
			system("cls");
			printf("Enter radius of circle ");
			scanf_s("%d", &radius);
			system("cls");
			break;

		case 2:
			if (radius > 0)
			{
				area = PI * radius * radius;
				system("cls");
				printf("Circle's area is %.2f", area);
			}
			else
			{
				system("cls");
				printf("Radius is not entered..");
			}
			break;

		case 3:
			system("cls");

			if (radius > 0)
			{
				printf("Enter angle in degrees ");
				scanf_s("%d", &angle);
				area_sector = angle * PI * radius * radius / 360.0;
				printf("\nArea sector is %.2f", area_sector);
			}
			else
			{
				system("cls");
				printf("Radius is not entered..");
			}

			break;

		case 4:
			system("cls");

			if (radius > 0)
			{
				circle_length = 2.0 * PI * radius;
				printf("\nCircle's length is %.2f", circle_length);
			}
			else
			{
				system("cls");
				printf("Radius is not entered..");
			}
			break;

		case 5:
			system("cls");
			if (radius > 0)
			{
				square_side = radius * 1.414;
				printf("\nSquare side is %.2f", square_side);
			}
			else
			{
				system("cls");
				printf("Radius is not entered..");
			}
			break;
		case 6:
			system("cls");
			if (radius > 0)
			{
				cone_capacity = radius * PI * radius * radius / 3.0;
				printf("\nCone capacity is %.2f", cone_capacity);
			}
			else
			{
				system("cls");
				printf("Radius is not entered..");
			}
			break;
		case 7:
			system("cls");
			printf("version 1.0\t\t2020-2020");
			break;
		case 8:
			return 0;
		}
	}
}

int result_of_check()
{
	int counter = 0;
	char c;
	char input_line[MAX];
	int sum = 0;

	do
	{
		counter = 0;
		int i = 0;

		for (i = 0; (c = getchar()) != '\n'; ++i)
		{
			input_line[i] = c;

			if (c < 47 || c > 58 || c == '\\' || i > 0)
				++counter;
		}

		if ((c == '\n') && (counter == 0))
		{
			input_line[i] = '\0';
			sum = atoi(input_line);

			if (sum == 0 || sum == 9)
				continue;
			else
				break;
		}
	} while (1);

	return sum;
}