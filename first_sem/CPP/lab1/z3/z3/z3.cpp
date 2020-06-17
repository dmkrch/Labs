#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
	int a, b;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "a / b = " << a / b << "(int)" << '\n' << "or ";
	cout << "a / b = " << (float)a / b << "(float)";
	_getch();
	return 0;
}