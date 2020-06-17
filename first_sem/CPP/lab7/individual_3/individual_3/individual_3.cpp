#include <stdio.h>
#include <iostream>
#define MAX 15
#define A_code 65
#define Z_code 90
#define PLUS_code 43
#define MINUS_code 45

void input(int*);
void output(int* C);
void addition(int*, int*, int*, int);
void subtraction(int* A, int* B, int* C, int base);
int get_signs(int*, int*);
int verification(int*, int*);
int recurs_verif(int*, int*, int);
int m = 0;

int main()
{
	int A[MAX];
	int B[MAX];
	int C[MAX + 1];
	int base = 2;
	int c;
	int signs;
	int ver;

	for (int i = 0; i < MAX; ++i)
		C[i] = 0;

	std::cout << "Enter your first bin number with sign ";
	input(A);
	std::cout << "Enter your second bin number with sign ";
	input(B);

	signs = get_signs(A, B);

	switch (signs)
	{
	case 1:
		addition(A, B, C, base);
		std::cout << "\The sum is 0 ";
		output(C);
		break;
	case 2:
		addition(A, B, C, base);
		std::cout << "\The sum is 1 ";
		output(C);
		break;
	case 3:
		ver = verification(A, B);
		if (ver == 1)
		{
			subtraction(A, B, C, base);
			std::cout << "\The sum is 0 ";
			output(C);
		}
		else
		{
			subtraction(B, A, C, base);
			std::cout << "\The sum is 1 ";
			output(C);
		}
		break;
	case 4:
		ver = verification(A, B);
		if (ver == 1)
		{
			subtraction(A, B, C, base);
			std::cout << "\The sum is 1 ";
			output(C);
		}
		else
		{
			subtraction(B, A, C, base);
			std::cout << "\The sum is 0 ";
			output(C);
		}
		break;
	default:
		std::cout << "\nERROR WITH SIGNS!\n";
	}
}

void input(int* arr) // inputting number to massive according to their int equalent
{
	int i;
	int k = 0;
	int length = 0;
	char temp[MAX];
	char symbol;
	char c;

	for (i = 0; i < MAX; ++i)
		arr[i] = 0;

	for (i = 0; (c = getchar()) != '\n'; ++i, ++k, ++length)
		temp[k] = c;

	for (i = MAX - length, k = 0; k < length; ++i, ++k)
	{
		symbol = temp[k];
		if (symbol >= A_code && symbol <= Z_code)
			arr[i] = symbol - 55;
		else if (symbol == PLUS_code || symbol == MINUS_code)
			if (symbol == PLUS_code)
				arr[i] = PLUS_code;
			else
				arr[i] = MINUS_code;
		else
			arr[i] = symbol - 48;
	}
}

void addition(int* A, int* B, int* C, int base) // creates C massive with summed numbers
{
	int delta = 0;
	for (int i = 0; i < MAX; ++i)
		if (A[i] == PLUS_code || A[i] == MINUS_code)
		{
			A[i] = 0;
			break;
		}

	for (int i = 0; i < MAX; ++i)
		if (B[i] == PLUS_code || B[i] == MINUS_code)
		{
			B[i] = 0;
			break;
		}

	for (int i = MAX - 1; i >= 0; --i)
	{
		if ((A[i] + B[i] + delta) >= base)
		{
			C[i + 1] = A[i] + B[i] - base + delta;
			delta = 1;
		}
		else
		{
			C[i + 1] = A[i] + B[i] + delta;
			delta = 0;
		}
	}
}

void subtraction(int* A, int* B, int* C, int base) // creating C massive with subtracted numbers
{
	for (int i = MAX - 1; i >= 0; --i)
	{
		if (A[i] - B[i] < 0)
		{
			--A[i - 1];
			C[i + 1] = A[i] + base - B[i];
		}
		else
			C[i + 1] = A[i] - B[i];
	}
}

int get_signs(int* A, int* B) // case 1: both+     case 2: both-       case 3: first+  second-        case 4: first-  second+
{
	for (int i = 0; i < MAX; ++i)
		if (A[i] == PLUS_code)
		{
			for (int i = 0; i < MAX; ++i)
				if (B[i] == PLUS_code)
					return 1;
				else if (B[i] == MINUS_code)
					return 3;
		}
		else if (A[i] == MINUS_code)
		{
			for (int i = 0; i < MAX; ++i)
				if (B[i] == PLUS_code)
					return 4;
				else if (B[i] == MINUS_code)
					return 2;
		}
}

int verification(int* A, int* B) // if A > B returns 1 ;  else returns 0
{
	int len_A;
	int len_B;
	int len;
	int k;
	int state;

	for (int i = 0; i < MAX; ++i)
		if (A[i] == PLUS_code || A[i] == MINUS_code)
		{
			len_A = MAX - 1 - i;
			break;
		}

	for (int i = 0; i < MAX; ++i)
		if (A[i] == PLUS_code || A[i] == MINUS_code)
		{
			A[i] = 0;
			break;
		}

	for (int i = 0; i < MAX; ++i)
		if (B[i] == PLUS_code || B[i] == MINUS_code)
		{
			len_B = MAX - 1 - i;
			break;
		}

	for (int i = 0; i < MAX; ++i)
		if (B[i] == PLUS_code || B[i] == MINUS_code)
		{
			B[i] = 0;
			break;
		}

	if (len_A == len_B)
	{
		state = recurs_verif(A, B, 0);
		if (state == 1)
			return 1;
		else
			return 0;
	}
	else if (len_A > len_B)
		return 1;
	else
		return 0;
}

int recurs_verif(int* A, int* B, int m) // one more verification to check biggest number
{
	if (m == MAX)
		return 1;
	if (A[m] > B[m])
		return 1;
	else if (A[m] == B[m])
		return recurs_verif(A, B, m + 1);
	else
		return 0;
}


void output(int* C)
{
	int state = 1;
	int i = 0;
	int to_del = 0;

	if (C[0] == 0)
	{
		while (state == 1)
		{
			if (C[i++] == 0)
				++to_del;
			else
				state = 0;
		}
	}
	else
		to_del = 0;

	for (int i = to_del; i < MAX + 1; ++i)
	{
		if (C[i] < 10)
			std::cout << C[i];
		else
			std::cout << (char)(C[i] + 55);
	}
	std::cout << "\n\n";
	system("pause");
}