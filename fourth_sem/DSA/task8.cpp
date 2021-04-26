#include <iostream>

int main()
{
    std::string input_line;
    std::cin >> input_line;
    int length = (int)input_line.length();

    bool isSymbolRepeats = true;

    for (int i = 0, j = length-1; i <= j; i++, j--) 
    {
        if (input_line[i] != input_line[j]) 
        {
            std::cout << length;
            return 0;
        }
        if (isSymbolRepeats && input_line[i] != input_line[0])
            isSymbolRepeats = false;
    }

    if (isSymbolRepeats)
        std::cout << "-1";
    else
        std::cout << length-1;
    
    return 0;
}    