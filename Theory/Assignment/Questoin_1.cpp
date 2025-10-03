#include <iostream>
using namespace std;


//declaring the strcuk
struct UniverseCoordinate {
    int s_number;
    int x_position;
    int y_position;
    bool is_snake;
};
//a fucntion to display the struck 
void display(UniverseCoordinate p, int n) {
    cout << "Point " << n << " Snake ID: " << p.s_number << endl;
    cout << "Point " << n << " X position: " << p.x_position << endl;
    cout << "Point " << n << " Y position: " << p.y_position << endl;
    cout << "Point " << n << " Snake present: " << p.is_snake << endl;
}

int main() {
    //decalring anf giving values to struck
    UniverseCoordinate point1 = {1, 2, 3, true};
  
  //displaying the result 
    display(point1, 1);
   

    return 0;
}
