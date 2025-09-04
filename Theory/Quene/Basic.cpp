#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<string> line;

    // FIFO - First In First Out
    line.push("Alice");
    line.push("Bob");
    line.push("Charlie");

    cout << "Front: " << line.front() << endl; // Alice
    cout << "Back: " << line.back() << endl;   // Charlie

    line.pop(); // Alice served
    cout << "Now front: " << line.front() << endl; // Bob
}
