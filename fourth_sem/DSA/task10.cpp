
#include <vector>
#include <iostream>

int main()
{
    std::string s;
    std::cin >> s;
    int n = (int)s.size();
    std::vector<int> prefix(n+1);
    int sum = 0;
    for (int ix = 0; ix < n; ix++)
    {
        prefix[1] = 0;
        int len = 0;
        int max = 0;
        for (int i = 1; i < n; i++)
        {
            while(true)
            {
                if (s[i] == s[len])
                {
                    len++;
                    break;
                }
                if (len == 0)
                {
                    break;
                }
                len = prefix[len];
            }
            prefix[i + 1] = len;
            max = std::max(max, len);
        }
        sum += (int)s.size() - max;
        s.erase(s.begin());
    }
    printf("%d", sum);
    return 0;
}