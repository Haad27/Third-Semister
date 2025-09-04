#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    // Input matrix dimensions (for simplicity, both same size for addition)
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int A[10][10], B[10][10], C[10][10];

    // Input matrix A
    cout << "Enter elements of matrix A:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> A[i][j];
        }
    }

    // Input matrix B
    cout << "Enter elements of matrix B:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> B[i][j];
        }
    }

    // Matrix Addition
    cout << "\nMatrix Addition (A + B):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    // Matrix Multiplication
    // For multiplication, we assume square matrices (rows == cols)
    cout << "\nMatrix Multiplication (A * B):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = 0;
            for (int k = 0; k < cols; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
