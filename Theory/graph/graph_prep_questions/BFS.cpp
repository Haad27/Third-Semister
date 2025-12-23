#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, vector<vector<int>> graph, vector<bool> flag)
{
    queue<int> q;

    q.push(start);
    flag[start] = true;

    while (q.empty() == false)
    {
        int num = q.front();
        q.pop();

        cout << num;

        for (int neighbor : graph[num])
        {
            if (flag[neighbor] == false)
            {
                flag[neighbor] = true;
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

    vector<bool> flag(n, false);

    bfs(0, graph, flag);
    return 0;
}
