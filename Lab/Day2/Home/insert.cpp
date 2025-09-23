#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Insert a node at the beginning
void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

// Insert a node at the end
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (head == NULL) {   // if list is empty
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;  // start with empty list

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);

    cout << "After inserting at end: ";
    printList(head);

    insertAtBeginning(head, 5);
    insertAtBeginning(head, 1);

    cout << "After inserting at beginning: ";
    printList(head);

    return 0;
}
