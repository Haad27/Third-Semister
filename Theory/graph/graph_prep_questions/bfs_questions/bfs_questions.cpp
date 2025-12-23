#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
//task 1
int count =0;
void bfs_count(int start, vector<vector<int>> graph, vector<bool> flag)
{
    queue<int> q;

    q.push(start);
    flag[start] = true;

    while (q.empty() == false)
    {
        int num = q.front();
        q.pop();

        cout << num;
        count++;
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
//task2
bool isConnected(int n , vector <vector<int>> graph){
   vector<bool> flag (n,false);
   bfs(n,graph,flag);
   
   for (int i = 0; i < n; i++)
   {
       if (flag[n]==false)
       {
       return false;
       }
       
   }
   return true;
}
//task4
void bfsMatrix(int start , vector<vector<int>>&matrix, vector < bool > flag){
    queue<int> q;

    q.push(start);
    flag[start]=true;


    while (q.empty()==false)
    {
        int num = q.front();
        q.pop();

        cout << num <<" ";

        for (int neighbor = 0; neighbor < matrix.size(); neighbor++)
        {
            if (matrix[num][neighbor]==1 && flag[neighbor]==false)
            {
               q.push(neighbor); 
               flag[neighbor]=true;
            }
            
        }
        
    }
    

}
//task5
void bfsShortestPath(int start, vector<vector<int>>& graph, int n)
{
    vector<int> dist(n, -1);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node])
        {
            if (dist[neighbor] == -1)
            {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << "Dist from " << start << " to " << i << " = " << dist[i] << endl;
}

int main()
{

    int n = 6;
    vector<vector<int>> graph(n);

    graph[0] = {1};
    graph[1] = {0, 2};
    graph[2] = {1};
    graph[3] = {4};
    graph[4] = {3};
    graph[5] = {};

    vector<bool> flag(n, false);

    bfs_count(0, graph, flag);
    cout <<endl<< count;
    //task3
    cout << "\nbfs components";
    for (int i = 0; i < n; i++)
    {
        if (flag[i]==false)
        {
            bfs(i,graph,flag);
            cout<<endl;
        }
        
    }
    // task 4 
     int n2 = 6;

    // adjacency matrix
    vector<vector<int>> matrix =
    {
        {0, 1, 0, 0, 0, 0}, // 0
        {1, 0, 1, 0, 0, 0}, // 1
        {0, 1, 0, 0, 0, 0}, // 2
        {0, 0, 0, 0, 1, 0}, // 3
        {0, 0, 0, 1, 0, 0}, // 4
        {0, 0, 0, 0, 0, 0}  // 5
    };

    vector<bool> flag2(n2, false);

    cout << "BFS using adjacency matrix: ";
    bfsMatrix(0, matrix, flag2);




    return 0;
}
