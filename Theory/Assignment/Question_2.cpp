#include <iostream>
using namespace std;

// create a struck
struct UniverseCoordinate {
    int s_number;
    int x_position;
    int y_position;
    bool is_snake;
};

// Function to create 2D dynamic array
UniverseCoordinate** createUniverse(int rows, int cols) {
    UniverseCoordinate** arr = new UniverseCoordinate*[rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new UniverseCoordinate[cols];
    }
    for(int i=0; i < rows ; i++){
        for (int j = 0; j < cols; j++) {
            arr[i][j].s_number = 0;        
            arr[i][j].x_position = j + 1; //as it is x and it represnt col index so we have j +1
            arr[i][j].y_position = i + 1; //as it is y and it represnt row index so we have i +1
            arr[i][j].is_snake = false;
        }
    }
    return arr;
}

// function to display the result 
void displayUniverse(UniverseCoordinate** arr, int rows, int cols) {
    cout << "\nUniverse Map:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j].is_snake)
                cout << "[S" << arr[i][j].s_number << "] ";
            else
                cout << "[--] ";
        }
        cout << endl;
    }
}

int main() {
    int rows = 2, cols = 2;
    UniverseCoordinate** UniverseData = createUniverse(rows, cols);

    // example
    UniverseData[0][0].s_number = 1;
    UniverseData[0][0].is_snake = true;

    UniverseData[1][1].s_number = 2;
    UniverseData[1][1].is_snake = true;

    displayUniverse(UniverseData, rows, cols);

    

    return 0;
}
