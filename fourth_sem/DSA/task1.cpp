#include <iostream>
#include <string>
#include <vector>

#define maxLength 10001


std::vector<int> graph[maxLength];
bool isChecked[maxLength];
int components = 0;

void dfs(int n)
{
    isChecked[n] = true;
    for (int i = 0; i < graph[n].size(); i++)
    {
        int v = graph[n][i];
        
        if (!isChecked[v])
            dfs(v);
    }
}

int main()
{
    int N, M;

    // N - number of vertexes of graph.  M - number of edges of graph
    std::cin >> N >> M;

    // input of vertexes and edges
    for (int i = 0; i < M; i++)
    {
        int n1, n2;
        std::cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

    for (int i = 1; i <= N; i++)
    {
        if (!isChecked[i])
        {
            dfs(i);
            components++;
        }
    }
    std::cout << components - 1;
    return 0;
}