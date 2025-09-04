#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
using namespace std;

void smallest(int *arr, int size)
{
    int smallest = 1233333;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < smallest)
        {
            smallest = arr[i];
        }
    }
    cout << "The smallest number in the array is: " << smallest << endl;
}
void transverse(int *arr, int size)
{
    cout << "The array elements are: ";

        for (int i = 0; i < size / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}
void reverseArray(int *arr, int size)
{
    int start = 0;
    int end = size - 1;

    while (start < end)
    {
        // swap arr[start] and arr[end]
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

int main()
{
    const int SIZE = 20;
    int arr[SIZE];

    // Seed the random number generator
    srand(time(0));

    // Fill the array with random numbers between 1 and 100
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 100 + 1;
    }

    // Print the array
    smallest(arr, SIZE);
    transverse(arr, SIZE);

    return 0;
}
