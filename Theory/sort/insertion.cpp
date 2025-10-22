#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int size = 5;
    int arr[size] = {2, 6, 1, 5, 2};
    int key;
    for (int i = 1; i < size; i++)
    {
        key=arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
