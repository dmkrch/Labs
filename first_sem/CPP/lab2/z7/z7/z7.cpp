#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;
int main()
{
	double a, b, c, x, x1, D;
	cout << "Here is the formula:\n ax^4 + bx^2 + c\nInput a, b, and c\n";
	cin >> a >> b >> c;
	if (a == 0 && b != 0)
	{ 
		x = c * (-1) / b;
		if (x > 0) 
			cout << "\nX=" << sqrt(x) << "    X=" << (-1) * sqrt(x); 
		else 
			cout << "\nERROR"; 
	}
	else if (b == 0 && a != 0) 
	{ 
		x = sqrt(c * (-1) / a); 
		x1 = sqrt(c * (-1) / a) * (-1); 
		if (x > 0) 
			cout << "\nX=" << sqrt(x) << "    X=" << (-1) * sqrt(x); 
		if (x1 > 0) cout << "\nX=" << sqrt(x1) << "    X=" << (-1) * sqrt(x1); 
		if (x1 < 0 && x < 0) cout << "ERROR"; 
	}
	else if ((pow(b, 2) - 4 * a * c) >= 0) 
	{
		D = pow(b, 2) - 4 * a * c;
		x = (b * (-1) - sqrt(D)) / 2 * a;
		x1 = (b * (-1) + sqrt(D)) / 2 * a;
		if (D == 0 && x > 0) 
			cout << "X=" << sqrt(x) << "\t\tX=" << (-1) * sqrt(x);
		else
		{
			if (x > 0) cout << "\nX=" << sqrt(x) << "    X=" << (-1) * sqrt(x);
			if (x1 > 0) cout << "\nX=" << sqrt(x1) << "    X=" << (-1) * sqrt(x1);
			if (x1 < 0 && x < 0) cout << "ERROR";
		}
	}
	else cout << "\nThere is no such x!";
	_getch();
	return 0;
}