#include <iostream>
using namespace std;

int main() {
    const int SIZE = 5;
    int *arr = new int[SIZE];  // pointer array (dynamic memory)

    cout << "Enter " << SIZE << " numbers:\n";
    for (int i = 0; i < SIZE; i++) {
        cin >> arr[i];
    }

    int highest = 0;

    // Find the highest number
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] > highest) {
            highest = arr[i];
        }
    }

    cout << "The highest number is: " << highest << endl;

    delete[] arr; // free memory
    return 0;
}
