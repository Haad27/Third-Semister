#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int start, vector<vector<int>> &graph, vector<bool> &visited)
{
    stack<int> s;

    s.push(start);

    while (s.empty() == false)
    {
        int node = s.top();
        s.pop();

        if (visited[node] == false)
        {
            visited[node] = true;
            cout << node << " ";
            // count++; to find number of nodes reachable like 2 has 1,2. 

            for (int neighbor : graph[node])
            {
                if (visited[neighbor] == false)
                {
                    s.push(neighbor);
                }
            }
        }
    }
}

int main()
{
    int n = 5;
    vector<vector<int>> graph(n);

    graph[0] = {1, 2};
    graph[1] = {0, 3};
    graph[2] = {0, 4};
    graph[3] = {1};
    graph[4] = {2};

    vector<bool> visited(n, false);

    cout << "DFS starting from node 0: ";
    dfs(0, graph, visited);

    return 0;
}
// to find the number of connected  nodes //total noes conneted
    // for (int i = 0; i < n; i++)
    // {
    //     if (!visited[i])
    //     {
    //         components++;
    //         dfs(i, graph, visited);
    //     }
    // }