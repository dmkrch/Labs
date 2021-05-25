#include <iostream>
#include <algorithm>
#include <vector>

std::vector<std::vector<int>> graph;
std::vector<std::vector<long long>> lengths;

long long nodes_amount;
long long sum = 0;
const long long module = 1e7 + 7;

int dfs(int node, int root)
{
    int ways_amount = 1;
    for (int i = 0; i < graph[node].size(); i++)
    {
        int nextNode = graph[node][i];
        if (nextNode != root){
            long long next_amount = dfs(nextNode, node);
            sum = (sum + (next_amount * (nodes_amount - next_amount)
                          * lengths[node][nextNode] * 2)) % module;
            ways_amount += next_amount;
        }
    }
    return ways_amount;
}

int main()
{
    std::cin >> nodes_amount;
    
    // changing all accurences ot vector int
    graph.assign(nodes_amount + 1, std::vector<int>());
    lengths.assign(nodes_amount + 1, std::vector<long long>(nodes_amount + 1, 0));
    
    for (int i = 0; i < nodes_amount - 1; i++)
    {
        int first_node, second_node, length;
        std::cin >> first_node >> second_node >> length;
        graph[first_node].push_back(second_node);
        graph[second_node].push_back(first_node);
        lengths[first_node][second_node] = length;
    }
    
    dfs(1, 0);
    
    std::cout << sum;
    return 0;
}