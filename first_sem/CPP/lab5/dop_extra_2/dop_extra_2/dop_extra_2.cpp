#include <stdio.h>
#include <iostream>
#include <math.h>

int function(int n, int i, int k);
int main()
{
	int k;
	int n;
	int t;
	int x;
	int sum = 0;
	int temp;


	std::cout << "Enter k ";
	std::cin >> k;

	std::cout << "Enter n ";
	std::cin >> n;

	std::cout << "Enter t ";
	std::cin >> t;

	for (int i = 0; i <= n * (k - 1); ++i)
		sum += function(n, i, k);
	
	temp = pow(10, t);

	sum = sum % temp;
	std::cout << --sum << "\n";
}

int function(int n, int r, int k)
{
	if (n == 0 && r == 0)
		return 1;

	else if ((n > 0) && (r >= 0 && r < n * (k - 1) + 1))
	{
		int temp = 0;
		for (int i = 0; i <= k - 1; ++i)
			temp += function(n - 1, r - i, k);
	}

	else
		return 0;
}
