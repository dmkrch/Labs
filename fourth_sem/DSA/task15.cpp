#include <iostream>
#include <vector>

int main()
{
	long long N;
    long counter = 0;
    long long max = 0;

	std::cin >> N;

    std::vector<long long> A;

	for (long long i = 0; i < N; i++)
		std::cin >> A[i+1];

	for (long long i = 0; i < N; i++)
		if (A[i+1] > max)
			max = A[i+1];

	A[0] = max;

	for (long long i = 0; i < N; i++)
		if (A[i] > A[i+1])
			counter += A[i] - A[i+1];

	std::cout << counter;
}