#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int row = 3;
    int col = 3;
    int **arr = new int *[row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[col];
    }
    int num;
    cout <<"enter the number you want the table of \n";
    cin >> num;
    int sum =num;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = sum;
            sum=sum+num;
        }
    }
    int sum2=1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout <<num<<" * " << sum2<<" = "<< arr[i][j]<<" ";
            cout <<endl;
            sum2++;
        }
        cout << endl;
    }

    return 0;
}
