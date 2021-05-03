#include <iostream>

int main()
{
    long long X;
    std::cin >> X;

    if (X % 10 != 0)
        std::cout << X % 10;
    else
        std::cout << "NO";
}