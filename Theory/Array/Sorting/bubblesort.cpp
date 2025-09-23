#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{

    int arr[100] = {34, 5, 2, 7, 2};
    int size = 5;

    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        for (int i = 0; i < size; i++)
        {
            cout << arr[i];
        }
    }

    return 0;
}
