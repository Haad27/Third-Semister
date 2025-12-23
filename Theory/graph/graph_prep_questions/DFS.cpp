#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

void dfs(int start, vector<vector<int>> graph, vector<bool> flag)
{
    stack<int> s;

    s.push(start);

    while (s.empty() == false)
    {
        int num = s.top();
        s.pop();

        if (flag[num] == false)
        {
            flag[num] = true;
            cout << num;
            for (int nieghbor : graph[num])
            {

                if (flag[nieghbor] == false)
                {
                    s.push(nieghbor);
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

    cout << "BFS starting from node 0: ";
    dfs(0, graph, visited);

    return 0;
}
