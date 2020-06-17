#include <iostream>
#include <conio.h>

int main()
{
	int a = 10, b = 7, c = 3;
	if (a > b)
		if (b < c)
			c = b;
		else
			c = a;
	std::cout << "c = " << c;
   
}
