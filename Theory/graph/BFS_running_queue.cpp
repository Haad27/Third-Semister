#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, vector<vector<int>> graph, vector<bool> visited)
{
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (q.empty() == false)
    {
        int node = q.front();
        q.pop();

        cout << node << " ";
         //count++; to find number of nodes reachable

        for (int neighbor : graph[node])
        {
            if (visited[neighbor] == false)
            {
                visited[neighbor] = true;
                q.push(neighbor);
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

    cout << "BFS starting from node 0: ";
    bfs(0, graph, visited);

    return 0;
}
