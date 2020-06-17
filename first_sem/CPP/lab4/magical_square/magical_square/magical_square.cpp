#include <stdio.h>
#include <iostream>
#include <iomanip>


void output_square(int** massive, int line);
void put_numbers(int** massive, int up_lim, int right_lim, int low_lim, int left_lim, int f_number, int line, int set_m, int set_n, int number_limit);
void set_values_on_A_quadrant(int& up_lim, int& right_lim, int& low_lim, int& left_lim, int& f_number, int& line, int& set_m, int& set_n, int& number_limit);
void set_values_on_B_quadrant(int& up_lim, int& right_lim, int& low_lim, int& left_lim, int& f_number, int& line, int& set_m, int& set_n, int& number_limit);
void set_values_on_C_quadrant(int& up_lim, int& right_lim, int& low_lim, int& left_lim, int& f_number, int& line, int& set_m, int& set_n, int& number_limit);
void set_values_on_D_quadrant(int& up_lim, int& right_lim, int& low_lim, int& left_lim, int& f_number, int& line, int& set_m, int& set_n, int& number_limit);
void some_actions_in_a_quadrant(int** massive, int line);
void actions_with_double_odd(int** massive, int line);
void swap(int*, int*);
int verification(int** massive, int line);



int main()
{

	int** massive;
	int** massive_a;
	int line;
	int i = 0;
	int f_number;
	int up_lim;
	int right_lim;
	int low_lim;
	int left_lim;
	int set_m;
	int set_n;
	int number_limit;


	std::cout << "Enter the order of magical square ";
	do
	{
		if (i++ > 0)
			std::cout << "Enter the correct order ";
		std::cin >> line;
	} while (line < 3);


	massive = new int* [line]; // allocating memory
	for (int i = 0; i < line; ++i)
		massive[i] = new int[line];

	for (int i = 0; i < line; ++i)
		for (int j = 0; j < line; ++j)
			massive[i][j] = 0;



	if (line % 2 == 0 && line % 4 != 0) // for even-order magical square, except ones, that can be divided by 4  (6, 10, 14, 18, 22, 26...
	{
		set_values_on_A_quadrant(up_lim, right_lim, low_lim, left_lim, f_number, line, set_m, set_n, number_limit);
		put_numbers(massive, up_lim, right_lim, low_lim, left_lim, f_number, line, set_m, set_n, number_limit);

		set_values_on_B_quadrant(up_lim, right_lim, low_lim, left_lim, f_number, line, set_m, set_n, number_limit);
		put_numbers(massive, up_lim, right_lim, low_lim, left_lim, f_number, line, set_m, set_n, number_limit);

		set_values_on_C_quadrant(up_lim, right_lim, low_lim, left_lim, f_number, line, set_m, set_n, number_limit);
		put_numbers(massive, up_lim, right_lim, low_lim, left_lim, f_number, line, set_m, set_n, number_limit);

		set_values_on_D_quadrant(up_lim, right_lim, low_lim, left_lim, f_number, line, set_m, set_n, number_limit);
		put_numbers(massive, up_lim, right_lim, low_lim, left_lim, f_number, line, set_m, set_n, number_limit);

		some_actions_in_a_quadrant(massive, line);
	}

	else if (line % 2 == 1) // for odd-order magical square  (1, 3, 5, 7, 9, 11...2n+1)
	{
		set_values_on_A_quadrant(up_lim, right_lim, low_lim, left_lim, f_number, line, set_m, set_n, number_limit);
		put_numbers(massive, up_lim, right_lim, low_lim, left_lim, f_number, line, set_m, set_n, number_limit);
	}

	else // for double odd magical square  (4, 8, 12, 16, 20...4n)
		actions_with_double_odd(massive, line);


	output_square(massive, line); // outputting square
}



void put_numbers(int** massive, int up_lim, int right_lim, int low_lim, int left_lim, int f_number, int line, int set_m, int set_n, int number_limit) // function for putting numbers into certain positions
{


	for (int number = f_number, n = set_n, m = set_m; number <= number_limit; ++number)
	{

		massive[m][n] = number;
		m -= 1;
		n += 1;


		if (m == up_lim && n < right_lim) // upper limit
		{
			int i = 1;
			do
				m = low_lim - i++;
			while (massive[m][n] != 0);
		}


		else if (n == right_lim && m >= up_lim + 1) // right limit
		{
			int i = left_lim;

			do
				n = i++;
			while (massive[m][n] != 0);
		}


		else if (n == right_lim && m == up_lim) // right up angle
		{
			m += 2;
			n -= 1;
		}

		if (massive[m][n] != 0) // for same element
		{
			m += 2;
			n -= 1;
		}
	}
}



void set_values_on_A_quadrant(int& up_lim, int& right_lim, int& low_lim, int& left_lim, int& f_number, int& line, int& set_m, int& set_n, int& number_limit)
{
	if (line % 2 == 1)
	{
		left_lim = 0;
		up_lim = -1;
		right_lim = line;
		low_lim = line;
		f_number = 1;
		set_m = 0;
		set_n = line / 2;
		number_limit = line * line;
	}
	else
	{
		left_lim = 0;
		up_lim = -1;
		right_lim = line / 2;
		low_lim = line / 2;
		f_number = 1;
		set_m = 0;
		set_n = right_lim / 2;
		number_limit = line * line / 4;
	}
}

void set_values_on_B_quadrant(int& up_lim, int& right_lim, int& low_lim, int& left_lim, int& f_number, int& line, int& set_m, int& set_n, int& number_limit)
{
	left_lim = line / 2;
	up_lim = line / 2 - 1;
	right_lim = line;
	low_lim = line;
	f_number = line * line / 4 + 1;
	set_m = line / 2;
	set_n = (3 * line - 2) / 4;
	number_limit = f_number + line * line / 4 - 1;
}

void set_values_on_C_quadrant(int& up_lim, int& right_lim, int& low_lim, int& left_lim, int& f_number, int& line, int& set_m, int& set_n, int& number_limit)
{
	left_lim = line / 2;
	up_lim = -1;
	right_lim = line;
	low_lim = line / 2;
	f_number = line * line / 2 + 1;
	set_m = 0;
	set_n = (3 * line - 2) / 4;
	number_limit = line * line * 3 / 4;
}

void set_values_on_D_quadrant(int& up_lim, int& right_lim, int& low_lim, int& left_lim, int& f_number, int& line, int& set_m, int& set_n, int& number_limit)
{
	left_lim = 0;
	up_lim = line / 2 - 1;
	right_lim = line / 2;
	low_lim = line;
	f_number = line * line * 3 / 4 + 1;
	set_m = line / 2;
	set_n = right_lim / 2;
	number_limit = line * line;
}


void swap(int* a, int* b) // a and b are two adresses of certain elements. Swapping values of theese adresses
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


void some_actions_in_a_quadrant(int** massive, int line) // extra actions to swap some elements after placing digits in quadrants A, B, C, D
{
	int m;
	int n;
	int* a;
	int* b;


	for (m = 0; m < line / 4; ++m) // swapping a1 quadrant
		for (n = 0; n < line / 4; ++n)
		{
			a = &massive[m][n];
			b = &massive[m + (line / 2)][n];
			swap(a, b);
		}

	a = &massive[m][n]; // swapping central element a2
	b = &massive[m + line / 2][n];
	swap(a, b);

	for (m = line / 4 + 1; m < line / 2; ++m) // swapping a3 quadrant
		for (n = 0; n < line / 4; ++n)
		{
			a = &massive[m][n];
			b = &massive[m + (line / 2)][n];
			swap(a, b);
		}

	if (line != 6) // swapping certain elements in C quadrant
	{
		for (m = 0; m < line / 2; ++m)
			for (n = 3 * (line + 2) / 4; n < line; ++n)
			{
				a = &massive[m][n];
				b = &massive[m + line / 2][n];
				swap(a, b);
			}
	}

	int left = n / 4, right = n / 4; //also some actions with A2 and B2
	for (int i = 1; i < n / 4; i++)
		if (i & 1)
		{
			left -= 2;
			a = &massive[n / 4][left];
			b = &massive[3 * n / 4][left];
			swap(a, b);
		}
		else
		{
			right++;
			a = &massive[n / 4][right];
			b = &massive[3 * n / 4][right];
			swap(a, b);
		}

}

void actions_with_double_odd(int** massive, int line) // some actions to put numbers into double odd magical square
{
	int iter = 0;
	int decr = line * line + 1;

	for (int m = 0; m < line; ++m)
		for (int n = 0; n < line; ++n)
		{
			++iter;
			if ((m < line / 4 && n < line / 4) || (m >= line / 4 * 3 && n < line / 4) || (m < line / 4 && n >= line / 4 * 3) || (m >= line / 4 * 3 && n >= line / 4 * 3) || (m >= line / 4 && m < line / 4 * 3 && n >= line / 4 && n < line / 4 * 3))
				massive[m][n] = iter;
		}

	for (int m = 0; m < line; ++m)
		for (int n = 0; n < line; ++n)
		{
			--decr;
			if (massive[m][n] == 0)
				massive[m][n] = decr;
		}
}


int verification(int** massive, int line) // checking sum in lines, columns and diagonals, if it is equal to magical constant
{
	int magic_const = line * (line * line + 1) / 2;
	int tank = 0;
	int status = 0;

	for (int m = 0; m < line; ++m) // checking lines
	{
		for (int n = 0; n < line; ++n)
			tank += massive[m][n];

		if (tank == magic_const)
			tank = 0;
		else
			return 0;
	}

	for (int m = 0; m < line; ++m) // checking columns
	{
		for (int n = 0; n < line; ++n)
			tank += massive[n][m];

		if (tank == magic_const)
			tank = 0;
		else
			return 0;
	}

	for (int m = 0, j = line - 1; m < line; ++m, --j) // checking diagonals
		tank += massive[m][m] + massive[j][j];

	if (tank == 2 * magic_const)
		tank = 0;
	else
		return 0;

	return 1;
}


void output_square(int** massive, int line) // function for outputting square
{
	int verificat = 0;

	std::cout << "\n\nYour magical square is:\n";
	for (int i = 0; i < line; ++i)
	{
		std::cout << "\n";
		for (int j = 0; j < line; ++j)
			std::cout << std::setw(3) << massive[i][j] << " ";
	}
	std::cout << "\n\n";

	verificat = verification(massive, line);
	if (verificat == 1)
		std::cout << "Verification is succesful\n\n";
	else
		std::cout << "Verification is failed.\n\n";
}