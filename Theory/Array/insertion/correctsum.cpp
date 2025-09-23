#include <iostream>
using namespace std;

int digitSum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int arr[100] = {12, 7, 8, 15, 10};
    int size = 5;

    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0) {  // check if odd
            // shift elements right from the end to i+1
            for (int j = size; j > i + 1; j--) {
                arr[j] = arr[j - 1];
            }
            // insert digit sum after the odd number
            arr[i + 1] = digitSum(arr[i]);

            size++; // array size increased
            i++;    // skip the inserted value
        }
    }

    // print result
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
