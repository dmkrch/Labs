#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <stdlib.h>

int main()
{
    std::string amount_input;
    std::cin >> amount_input;
    int amount = std::stoi(amount_input);

    std::string arr_input;
    std::getline(std::cin, arr_input);

    std::string buf;  
    std::stringstream ss(arr_input);  
    std::vector<int> arr; 

    while (ss >> buf)
        arr.push_back(std::stoi(buf));

    for (int i = 0; i < amount; ++i)
        std::cout << arr[i] << " ";
}