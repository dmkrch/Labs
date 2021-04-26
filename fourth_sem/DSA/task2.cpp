#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>

int main()
{
    std::string amount_input;
    std::getline(std::cin, amount_input);
    long long N = std::stoi(amount_input);

    if (N <= 0)
        std::cout << "0";

    std::string arr_input;
    std::getline(std::cin, arr_input);

    std::string buf;  
    std::stringstream ss(arr_input);  
    std::vector<long long> arr; 

    while (ss >> buf)
        arr.push_back(std::stoi(buf));

    sort(arr.begin(), arr.end());

    if (N == 3)
        std::cout << std::max(arr[0]*arr[1], std::max(arr[1]*arr[2], arr[0]*arr[2]));
    else if (N > 3)
        if (arr[N-1]*arr[N-2] > arr[0]*arr[1])
            std::cout << arr[N-1]*arr[N-2];
        else
            std::cout << arr[0]*arr[1];
    else
        std::cout << arr[0]*arr[1];
}