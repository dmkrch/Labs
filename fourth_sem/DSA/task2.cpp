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
    int amount = std::stoi(amount_input);

    std::string arr_input;
    std::getline(std::cin, arr_input);

    std::string buf;  
    std::stringstream ss(arr_input);  
    std::vector<int> arr; 

    while (ss >> buf)
        arr.push_back(std::stoi(buf));

    sort(arr.begin(), arr.end());

    if (amount == 2)
        std::cout << arr[0]*arr[1];
    else if (amount == 3)
        std::cout << std::max(std::max(arr[0]*arr[1], arr[0]*arr[2]), arr[1]*arr[2]);
    else
        std::cout << std::max(arr[0]*arr[1], arr[amount-1]*arr[amount-2]);
}