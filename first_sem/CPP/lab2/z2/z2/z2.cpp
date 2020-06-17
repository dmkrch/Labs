#include <iostream>
#include <conio.h>
#define RIGHT 1
#define WRONG 0
int main()
{
	int d = 0;
	int state = 0;
	char sign, button;

	std::cout << "enter the number ";
	std::cin >> d;
	std::cout << "enter your sign ";
	std::cin >> sign;
	std::cout << "\n";

	if (sign == '+' || sign == '-' || sign == '*' || sign == '/')
		state = RIGHT;
	else
		state = WRONG;

	if (state == WRONG)
		do
		{
			std::cout << "\nYou have entered a wrong sign\n";
			std::cout << "enter y to rewrite the sign or other to exit\n";
			std::cin >> button;

			if (button == 'y')
			{
				std::cout << "\nenter your sign again\n";
				std::cin >> sign;
				if (sign == '+' || sign == '-' || sign == '*' || sign == '/')
					state = RIGHT;
				else
					state = WRONG;
			}
			else
				return 0;

		} 
		while (state == WRONG);

		std::cout << d << " " << sign << " 2 = ";
		if (sign == '+')
			std::cout << d + 2;
		if (sign == '-')
			std::cout << d - 2;
		if (sign == '*')
			std::cout << d * 2;
		if (sign == '/')
			std::cout << d / 2 << "\n";

		_getch();
		return 0;
}