#include <iostream>
#include <vector>

using namespace std;

// defining vector of long numbers vectors
#define MATRIX vector<vector<long long>>

const int mod = 1e9 + 7;

MATRIX multiplyMatrix (MATRIX a, MATRIX b)
{
    int size = (int) a.size();
    MATRIX c (size, vector<long long>(size , 0));
    
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
                c[i][j] = (c[i][j] + a[i][k] * b[k][j] % mod) % mod;
        }
    }
    return c;
}

MATRIX twoPowerMatrix(MATRIX a, int k)
{
    int size = (int)a.size();
    MATRIX b (size, vector<long long>(size, 0));

    for (int i = 0; i < size; i ++)
        b[i][i] = 1;
    
    while (k)
    {
        if (k % 2 == 1) 
        {
            b = multiplyMatrix(b, a);
            k--;
        }
        else 
        {
            a = multiplyMatrix(a, a);
            k /= 2;
        }
    }

    return b;
}

int main()
{
    // input of N - amount of vertexes and M - amount of edges
    int N, M;
    std::cin >> N >> M;
    
    // U, V - vertexes, L - length of route
    int U, V, L;
    std::cin >> U >> V >> L;
    
    // defining input matrix
    MATRIX inputMatrix(N, vector<long long>(N, 0));

    // input of matrix
    for (int i = 0; i < M; i++)
    {
        int A, B;
        std::cin >> A >> B;
        A --;
        B --;
        if (A == B)
            inputMatrix[A][B] += 2;
        else
        {
            inputMatrix[A][B] += 1;
            inputMatrix[B][A] += 1;
        }
    }
    
    // main action - powering matrix to bin 
    inputMatrix = twoPowerMatrix(inputMatrix, L);
    
    std::cout << inputMatrix[U - 1][V - 1];
}