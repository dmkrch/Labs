#include <iostream>
#include <conio.h>
int main()
{
	int i = 0;
	int m = 0;
	int number = 0;
	int tank = 0;
	int k = 0;
	int extra = 0;
	int length = 0;
	int number_copy = 0;
	int result = 0;


	std::cout << "Enter the number of needed digit: "; // row is:  1 4 9 16 25 36 49 64 81 100 121 144 169..
	std::cin >> k;


	for (i = 1; i < k * k + 1; ++i)
	{
		number = i * i;

		for (extra = number, length = 0; extra > 0;) // finding the length of current number
		{
			++length;
			extra /= 10;
		}

		for (m = 1; m <= length; ++m) // finding limit according to var "k"
		{
			number_copy = number / pow(10, (length - m));

			++tank;

			if (tank == k)
				m = (length + 1);
		}

		if (tank == k) // outputting needed digit
		{
			result = number_copy % 10;
			std::cout << "The " << k << " digit of row is " << result << "\n";
		}
	}
}