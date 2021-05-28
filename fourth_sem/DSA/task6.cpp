#include <iostream>
#include <cstdlib>
#include <algorithm>

int compare(const void* x1, const void* x2)
{
    long long a = *((long long*)x1 + 2), b = *((long long*)x2 + 2);
    if(a < b) 
        return 1;
    if(a > b) 
        return -1;

    return 0;
}

int main()
{
    long long N, M;
    std::cin >> N >> M;

    long long req[M][3] = {0};

    for (int i = 0; i < M; i++)
    {
        std::cin >> req[i][0] >> req[i][1] >> req[i][2];
        req[i][0]--; 
        req[i][1]--;
    }

    qsort(req, M, sizeof(long long) * 3, compare);

	long long** ss = new long long*[N+1];
    long long nums[N+1];

    for(int i = 0; i < N+1; i++)
    {
		nums[i] = -1;
		ss[i] = NULL;
	}

    for(int i = 0; i < M; i++)
    {
        long long L = req[i][0], R = req[i][1], V = req[i][2];
        long long *a = new long long(L);
            
        for(int j = L; j <= R;)
        {
            if(ss[j] == NULL)
            {
            	nums[j] = V;
            	ss[j] = a;
            	*ss[j] = j+1;
            	j++;
			}
			else
			{
				j = *ss[j];
			}
		}	
    }


    for(int i = 0; i < N; i++)
    {
        std::cout << nums[i] << ' ';
    }
    return 0;
}