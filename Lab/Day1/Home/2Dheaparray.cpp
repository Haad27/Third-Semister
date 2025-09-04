#include <iostream>
using namespace std;

int main() {
    int m = 3;
    int n = 4;
    int a = 0;

    int* arr = new int[m * n];   // allocate heap memory for 2D array

    // Fill array
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr[i * n + j] = a;
            a++;
        }
    }

    // Print array
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i * n + j] << " ";
        }
        cout << endl;
    }

    delete[] arr;  // free heap memory
    return 0;
}
