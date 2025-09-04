#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> numbers;

    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    // Insert in the middle
    auto it = numbers.begin();
    advance(it, 1);
    numbers.insert(it, 15);

    // Remove element
    numbers.remove(30);

    cout << "List: ";
    for (int n : numbers) cout << n << " "; // 10 15 20
}
