#include <iostream>
using namespace std;

int main() {
    int arr[100] = {4, -3, 5, -7, 2};
    int size = 5;

    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            // Shift elements to the right
            for (int j = size; j > i; j--) {
                arr[j] = arr[j - 1];
            }
            // Insert 0 before the negative number
            arr[i] = 0;
            size++;
            i++; // Skip over the inserted 0 and the negative
        }
    }

    // Print final array
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
