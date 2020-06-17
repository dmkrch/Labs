#include <stdio.h>
#include <iostream>
float left_triangle_method();
float right_triangle_method();
float central_triangle_method();
float trapezium_method();


int main()
{
	std::cout << left_triangle_method() << "\n\n";
	std::cout << right_triangle_method() << "\n\n";
	std::cout << central_triangle_method() << "\n\n";
	std::cout << trapezium_method() << "\n\n";
	return 0;
}


float left_triangle_method()
{
	int n;
	float sum = 0;
	float a = 0.4;
	float b = 1.2;
	float h;
	float result;
	float x;

	std::cout << "Enter n for left-triangle method\n";
	std::cin >> n;

	h = (b - a) / n;

	for (int i = 0; i < n; ++i) // calculating sum 
	{
		x = a + i * h;
		sum += cos(x * x) / (x + 1);
	}

	result = h * sum;
	return result;
}


float right_triangle_method()
{
	int n;
	float sum = 0;
	float a = 0.4;
	float b = 1.2;
	float h;
	float result;
	float x;

	std::cout << "Enter n for right-triangle method\n";
	std::cin >> n;

	h = (b - a) / n;

	for (int i = 1; i <= n; ++i) // calculating sum 
	{
		x = a + i * h;
		sum += cos(x * x) / (x + 1);
	}

	result = h * sum;
	return result;
}

float central_triangle_method()
{
	int n;
	float sum = 0;
	float a = 0.4;
	float b = 1.2;
	float h;
	float result;
	float x;

	std::cout << "Enter n for central-triangle method\n";
	std::cin >> n;

	h = (b - a) / n;

	for (int i = 0; i < n; ++i) // calculating sum 
	{
		x = a + i * h + h / 2;
		sum += cos(x * x) / (x + 1);
	}

	result = h * sum;
	return result;
}

float trapezium_method()
{
	int n;
	float sum = 0;
	float a = 0.4;
	float b = 1.2;
	float h;
	float result;
	float x;

	std::cout << "Enter n for central-triangle method\n";
	std::cin >> n;

	h = (b - a) / n;

	x = a;
	sum += cos(x * x) / (x + 1) / 2;
	x = a + n * h;
	sum += cos(x * x) / (x + 1) / 2;

	for (int i = 1; i < n; ++i) // calculating sum 
	{
		x = a + i * h + h / 2;
		sum += cos(x * x) / (x + 1);
	}

	result = h * sum;
	return result;
}


