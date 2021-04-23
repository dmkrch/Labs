#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <stdlib.h>

int main()
{
    std::string str;
    std::getline(std::cin, str);
    std::string buf;  
    std::stringstream ss(str);  
    std::vector<std::string> tokens; 

    while (ss >> buf)
        tokens.push_back(buf);

    int x1 = std::stoi(tokens[2]);
    int y1 = std::stoi(tokens[3]);
    int x2 = std::stoi(tokens[4]);
    int y2 = std::stoi(tokens[5]);

    if (abs(x1-x2) == abs(y1-y2))
        std::cout << "NO" << std::endl;
    else
        std::cout << "YES" << std::endl;
}