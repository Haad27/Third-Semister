#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5, 3};  
    int n = sizeof(arr)/sizeof(arr[0]);

    int expectedSum = (n - 1) * (n) / 2; 
    int actualSum = 0;

    for (int i = 0; i < n; i++) {
        actualSum += arr[i];
    }

    int duplicate = actualSum - expectedSum;
    cout << "The duplicated element is " << duplicate << endl;

    return 0;
}
