#include <iostream>
#include <algorithm> // for sort
#include <cstdlib>   // for rand, srand
#include <ctime>     // for time
using namespace std;

int main() {
    srand(time(0)); // seed random number generator

    const int n = 10;   // size of array
    int arr[n];

    // Generate random numbers between 0 and 50
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10;
    }

    // Print generated numbers
    cout << "Generated array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Sort the array
    sort(arr, arr + n);

    // Check for duplicates
    bool found = false;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            cout << "Duplicate element: " << arr[i] << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No duplicates found." << endl;
    }

    return 0;
}
