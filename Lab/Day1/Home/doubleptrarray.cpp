#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int m = 3;
    int c=0;
    int n = 2;
    int **arr = new int *[m];
    for (int i = 0; i < m; i++)
    {
        arr[i] = new int[n];
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = c;
            c++;
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
