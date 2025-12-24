#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
// task 1
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
            // count++ for finding the associated nodes
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
// task 2
void dfs_recursion(int node, vector<vector<int>> &graph, vector<bool> &visited)
{
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : graph[node])
    {
        if (!visited[neighbor])
            dfs_recursion(neighbor, graph, visited);
        // count++ for finding the associated nodes
    }
}

int countComponentsDFS(int n, vector<vector<int>> &graph)
{
    vector<bool> visited(n, false);
    int components = 0;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, graph, visited);
            components++;
        }
    }
    return components;
}
bool dfsCycle_undirected(int start, int parent, vector<vector<int>> &graph, vector<bool> &visited)
{
    visited[start] = true;

    for (int neighbour : graph[start])
    {
        if (!visited[neighbour])
        {
            if (dfsCycle_undirected(neighbour, start, graph, visited))
                return true;
        }
        else if (neighbour != parent)
        {
            return true;
        }
    }

    return false; 
}

bool dfsCycleDirected(int node, vector<bool> &parent, vector<vector<int>> &graph, vector<bool> &visited)
{
    visited[node] = true;
    parent[node] = true;

    for (int nieghbour : graph[node])
    {
        if (visited[nieghbour] == false)
        {
            if (dfsCycleDirected(nieghbour, parent, graph, visited))
            {
                return true;
            }
            else if (parent[nieghbour])
            {
                return true;
            }
        }
        
    }
    parent[node] = false;
        return false;
}

int main()
{
    int n = 5;
    vector<vector<int>> graph(n);

    // example graph
    graph[0] = {1, 2};
    graph[1] = {0, 3};
    graph[2] = {0, 4};
    graph[3] = {1};
    graph[4] = {2};

    // ---- DFS Iterative ----
    vector<bool> visited_iter(n, false);
    cout << "DFS Iterative: ";
    dfs(0, graph, visited_iter);
    cout << endl;

    // ---- DFS Recursive ----
    vector<bool> visited_rec(n, false);
    cout << "DFS Recursive: ";
    dfs_recursion(0, graph, visited_rec);
    cout << endl;

    // ---- DFS Cycle Detection (Undirected) ----

    vector<bool> visited_cycle_und(n, false);
    bool cycleUndirected = dfsCycle_undirected(0, -1, graph, visited_cycle_und);
    cout << "Cycle in Undirected Graph: " << (cycleUndirected ? "Yes" : "No") << endl;

    // ---- DFS Cycle Detection (Directed) ----
    vector<bool> visited_cycle_dir(n, false);
    vector<bool> recStack(n, false);
    bool cycleDirected = dfsCycleDirected(0, recStack, graph, visited_cycle_dir);
    cout << "Cycle in Directed Graph: " << (cycleDirected ? "Yes" : "No") << endl;

    return 0;
}
