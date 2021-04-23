#include <iostream>
#include <vector>

int main()
{
    std::string S;
    std::cin >> S;

    std::vector<int> numberOfChanges(S.length() + 1);

    // amount of requests
    int Q;
    std::cin >> Q;

    // input of int pairs (our Q's)
    for (int i = 0; i < Q; i++)
    {
        int L;
        int R;
        
        std::cin >> L >> R;
        if (R < L) 
            std::swap(L, R);

        numberOfChanges[L-1]++;
        numberOfChanges[R]--;
    }

    for (int i = 1; i < numberOfChanges.size(); i++)
        numberOfChanges[i] += numberOfChanges[i-1];
        
    // doing q requests to make to upper method in them
    for (int i = 0; i < S.length(); ++i)
    {
        if (numberOfChanges[i] % 2 == 1)
            if (isupper(S[i]))
                S[i] = tolower(S[i]);
            else
                S[i] = toupper(S[i]);
    }

    std::cout << S;
}