#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *top = NULL;  

bool isEmpty() {
    return top == NULL;
}

void push(int value) {
    Node *newnode = new Node();
    newnode->data = value;
    newnode->next = top;  
    top = newnode;      
    cout << "Inserted " << value << endl;
}

void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow\n";
        return;
    }
    Node *temp = top;
    cout << "Popped " << top->data << endl;
    top = top->next;  
    delete temp;    
}

void peek() {
    if (isEmpty()) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Top element: " << top->data << endl;
}

void display() {
    if (isEmpty()) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Stack elements: ";
    Node *temp = top;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
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
    return 0;
}
