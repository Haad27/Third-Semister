#include <iostream>
using namespace std;

int main() {
    int arr[9] = {1,2,3,4,5,6,7,8,9};

    int index = 0;
    for (int i = 0; i < 9; i++) {
        if (arr[i] % 2 == 0) {
            swap(arr[i], arr[index]);
            index++;
        }
    }

    for (int i = 0; i < index; i++) {
        for (int j = i + 1; j < index; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i = index; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i = 0; i < 9; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
