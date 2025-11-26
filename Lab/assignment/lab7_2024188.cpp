#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

long long qsComparisons = 0, qsSwaps = 0;
long long msComparisons = 0, msOperations = 0;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        msComparisons++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
        msOperations++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        msOperations++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        msOperations++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int partitionFirst(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;

    for (int j = low + 1; j <= high; j++) {
        qsComparisons++;
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            qsSwaps++;
            i++;
        }
    }

    swap(arr[low], arr[i - 1]);
    qsSwaps++;
    return i - 1;
}

int partitionLast(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        qsComparisons++;
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
            qsSwaps++;
        }
    }

    swap(arr[i + 1], arr[high]);
    qsSwaps++;
    return i + 1;
}

int partitionMiddle(int arr[], int low, int high) {
    int mid = (low + high) / 2;
    swap(arr[mid], arr[high]);
    qsSwaps++;
    return partitionLast(arr, low, high);
}

void quickSort(int arr[], int low, int high, int type) {
    if (low < high) {
        int pi;
        if (type == 1) {
            pi = partitionFirst(arr, low, high);
        } else if (type == 2) {
            pi = partitionLast(arr, low, high);
        } else {
            pi = partitionMiddle(arr, low, high);
        }
        quickSort(arr, low, pi - 1, type);
        quickSort(arr, pi + 1, high, type);
    }
}

void generateRandom(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1;
    }
}

void generateSorted(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
}

void generateNearlySorted(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    for (int i = 0; i < 4; i++) {
        int a = rand() % n;
        int b = rand() % n;
        swap(arr[a], arr[b]);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void testQuickSort(int arr[], int n) {
    int temp[n];
    for (int type = 1; type <= 3; type++) {
        for (int i = 0; i < n; i++) {
            temp[i] = arr[i];
        }

        qsComparisons = 0;
        qsSwaps = 0;
        quickSort(temp, 0, n - 1, type);
      
        string pivot;
        if (type == 1) {
            pivot = "First";
        } else if (type == 2) {
            pivot = "Last";
        } else {
            pivot = "Middle";
        }

        cout << "QuickSort " << pivot << " Pivot: ";
        printArray(temp, n);
        cout << "QS Comparisons: " << qsComparisons << "  Swaps: " << qsSwaps << endl;
    }
}

void testMergeSort(int arr[], int n) {
    int temp[n];
    for (int i = 0; i < n; i++) {
        temp[i] = arr[i];
    }

    msComparisons = 0;
    msOperations = 0;
    mergeSort(temp, 0, n - 1);

    cout << "MergeSort: ";
    printArray(temp, n);
    cout << "MS Comparisons: " << msComparisons << "  Merge ops: " << msOperations << endl;
}

int main() {
    srand(time(0));
    int n = 20;
    int arr[n];

    generateRandom(arr, n);
    cout << "Random Input: ";
    printArray(arr, n);
    testQuickSort(arr, n);
    testMergeSort(arr, n);

    generateSorted(arr, n);
    cout << "\nSorted Input: ";
    printArray(arr, n);
    testQuickSort(arr, n);
    testMergeSort(arr, n);

    generateNearlySorted(arr, n);
    cout << "\nNearly Sorted Input: ";
    printArray(arr, n);
    testQuickSort(arr, n);
    testMergeSort(arr, n);

    return 0;
}
