#include <iostream>
#include <algorithm>
#include <cstdlib> // for abs()
using namespace std;

void pairClosestToZero(int arr[], int n) {
    if (n < 2) {
        cout << "Not enough elements." << endl;
        return;
    }

    sort(arr, arr + n);

    int left = 0, right = n - 1;
    int minSum = INT_MAX;
    int minLeft = left, minRight = right;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (abs(sum) < abs(minSum)) {
            minSum = sum;
            minLeft = left;
            minRight = right;
        }

        if (sum < 0)
            left++;
        else
            right--;
    }

    cout << "The two elements whose sum is closest to zero are: "
         << arr[minLeft] << " and " << arr[minRight]
         << " (Sum = " << arr[minLeft] + arr[minRight] << ")" << endl;
}

int main() {
    int arr[] = {1, 60, -10, 70, -80, 85};
    int n = sizeof(arr) / sizeof(arr[0]);

    pairClosestToZero(arr, n);

    return 0;
}
