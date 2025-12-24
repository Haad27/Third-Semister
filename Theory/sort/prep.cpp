#include <iostream>
#include <string>
#include <vector>

using namespace std;
void bubble(int n, int arr[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j + 1] > arr[j])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void selection(int n, int arr[])
{
    int min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        swap(arr[min], arr[i]);
    }
}
void insertion(int n, int arr[])
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j > 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int left, int mid, int right)
{
    int n1=mid-left+1;
    int n2= right-mid;

    int l1[n2],r2[n2];

    for (int i = 0; i < n1; i++)
    {
        l1[i]=arr[left+i];
    }
    for (int j = 0; j < n2; j++)
    {
        r2[j]=arr[mid+1+j];
    }
    int i =0 , j=0 , k = left;
    while (i<n1 && j<n2)
    {
        if (l1[i]<=r2[j])
        {
            arr[k++]=l1[i++];
        } if (l1[i]>=r2[j])
        {
            arr[k++]=r2[j++];
        }

    }
   while (i<n1)
   {
    arr[k++]=l1[i++];
   }
   while (j<n2)
   {
    arr[k++]=r2[j++];
   }    
}
void mergesort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergesort(arr, left, mid);
        mergesort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}
void quicksort(int arr[], int low, int high){

    if (low<high)
    {
        int pivot = arr[high];
        int i = low-1;

        for (int j = low; j < high; j++)
        {
            if (arr[j]<pivot)
            {
               i++;
               swap(arr[j],arr[i]);
            }
            
        }
        swap(arr[i+1],arr[high]);
        int pi = i+1;
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}
int main()
{

    return 0;
}
