#include <iostream>
#include <string>
#include <vector>

using namespace std;
void selection(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
            swap(arr[i], arr[min]);
    } 
}
int main()
{
    int size = 5;
    int arr[size] = {2, 6, 1, 5, 2};
    selection(arr, size);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
