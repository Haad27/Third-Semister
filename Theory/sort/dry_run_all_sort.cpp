#include <iostream>
using namespace std;

// Utility to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Bubble Sort with steps
void bubble_sort(int arr[], int n) {
    cout << "Bubble Sort Steps:\n";
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
            printArray(arr, n);
        }
    }
}

// Selection Sort with steps
void selection_sort(int arr[], int n) {
    cout << "Selection Sort Steps:\n";
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
        printArray(arr, n);
    }
}

// Insertion Sort with steps
void insertion_sort(int arr[], int n) {
    cout << "Insertion Sort Steps:\n";
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            printArray(arr, n);
        }
        arr[j + 1] = key;
        printArray(arr, n);
    }
}

// Merge helper
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int l[n1], r[n2];
    for (int i = 0; i < n1; i++) l[i] = arr[left + i];
    for (int j = 0; j < n2; j++) r[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (l[i] <= r[j]) arr[k++] = l[i++];
        else arr[k++] = r[j++];
        printArray(arr, right + 1);
    }
    while (i < n1) arr[k++] = l[i++];
    while (j < n2) arr[k++] = r[j++];
}

// Merge Sort with steps
void mergesort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Quick Sort with steps
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
                printArray(arr, high + 1);
            }
        }
        swap(arr[i + 1], arr[high]);
        printArray(arr, high + 1);
        int pi = i + 1;
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// Counting Sort with steps
void countSort(int arr[], int n) {
    cout << "Counting Sort Steps:\n";
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) if (arr[i] > maxVal) maxVal = arr[i];

    int *count = new int[maxVal + 1]{0};
    for (int i = 0; i < n; i++) count[arr[i]]++;

    int index = 0;
    for (int i = 0; i <= maxVal; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
            printArray(arr, n);
        }
    }
    delete[] count;
}

// Radix Sort helper: Counting sort by digit
void countSortRadix(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
    printArray(arr, n);
}

// Radix Sort with steps
void radixSort(int arr[], int n) {
    cout << "Radix Sort Steps:\n";
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) if (arr[i] > maxVal) maxVal = arr[i];

    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countSortRadix(arr, n, exp);
}

// Main function
int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    int copyArr[n];

    // Bubble
    copy(arr, arr + n, copyArr);
    bubble_sort(copyArr, n);
    cout << endl;

    // Selection
    copy(arr, arr + n, copyArr);
    selection_sort(copyArr, n);
    cout << endl;

    // Insertion
    copy(arr, arr + n, copyArr);
    insertion_sort(copyArr, n);
    cout << endl;

    // Merge
    copy(arr, arr + n, copyArr);
    mergesort(copyArr, 0, n - 1);
    cout << "Merge Sort Completed:\n";
    printArray(copyArr, n);
    cout << endl;

    // Quick
    copy(arr, arr + n, copyArr);
    quicksort(copyArr, 0, n - 1);
    cout << "Quick Sort Completed:\n";
    printArray(copyArr, n);
    cout << endl;

    // Counting
    copy(arr, arr + n, copyArr);
    countSort(copyArr, n);
    cout << "Counting Sort Completed:\n";
    printArray(copyArr, n);
    cout << endl;

    // Radix
    copy(arr, arr + n, copyArr);
    radixSort(copyArr, n);
    cout << "Radix Sort Completed:\n";
    printArray(copyArr, n);
    cout << endl;

    return 0;
}
