#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<string> books;

    // LIFO - Last In First Out
    books.push("Math");
    books.push("Physics");
    books.push("Chemistry");

    cout << "Top book: " << books.top() << endl; // Chemistry

    books.pop(); // remove Chemistry
    cout << "After popping, top book: " << books.top() << endl; // Physics
}
