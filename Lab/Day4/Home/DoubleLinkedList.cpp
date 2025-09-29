#include <iostream>
using namespace std;

// Doubly Linked List Node
struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = nullptr;

// Insert at end
void insertEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (head == nullptr) { 
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp; // link back
}

// Print forward
void printForward() {
    Node* temp = head;
    cout << "Forward: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Print backward
void printBackward() {
    if (head == nullptr) return;

    Node* temp = head;
    // go to last node
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    cout << "Backward: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->prev;
    }
    cout << "NULL\n";
}

int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);

    printForward();   // 10 -> 20 -> 30 -> 40 -> NULL
    printBackward();  // 40 -> 30 -> 20 -> 10 -> NULL

    return 0;
}
