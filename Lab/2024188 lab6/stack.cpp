#include <iostream>
using namespace std;

#define MAX 5

int arr[MAX];
int top = -1;

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == MAX - 1;   
}
void push(int value) {
    if (isFull()) {
        cout << "Stack Overflow\n";
        return;
    }
    arr[++top] = value;
    cout << "Inserted " << value << endl;
}

void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow\n";
        return;
    }
    cout << "Popped " << arr[top--] << endl;
}

void peek() {
    if (isEmpty()) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Top element: " << arr[top] << endl;
}

void display() {
    if (isEmpty()) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Stack elements: ";
    for (int i = 0; i <= top; i++) {  // ✅ should go up to <= top
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    peek();
    pop();
    display();
}
