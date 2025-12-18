#include <iostream>
using namespace std;

void CountSort(int A[], int n)
{
    int max = A[0];
    for (int j = 1; j < n; j++)
    {
        if (A[j] > max)
        {
            max = A[j];
        }
    }

    int* Count = new int[max + 1]{0};

    for (int i = 0; i < n; i++)
    {
        Count[A[i]]++;
    }

    int index = 0;
    for (int i = 0; i <= max; i++)
    {
        while (Count[i] > 0)
        {
            A[index++] = i;
            Count[i]--;
        }
    }

    delete[] Count;
}

int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void CountSortRadix(int arr[], int n, int exp)
{
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void RadixSort(int arr[], int n)
{
    int max = getMax(arr, n);
    for (int exp = 1; max / exp > 0; exp *= 10)
        CountSortRadix(arr, n, exp);
}

int main()
{
    int arr1[] = {2, 1, 4, 5, 3, 2, 6, 7, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    CountSort(arr1, n1);
    cout << "Counting Sort:\n";
    for (int i = 0; i < n1; i++)
        cout << arr1[i] << " ";
    cout << endl;

    int arr2[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    RadixSort(arr2, n2);
    cout << "Radix Sort:\n";
    for (int i = 0; i < n2; i++)
        cout << arr2[i] << " ";

    return 0;
}
