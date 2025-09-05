#include <iostream>
using namespace std;

class Node {
public:
    int data;      // data of the node
    Node* next;    // pointer to next node

    // Constructor
    Node(int value) {
        data = value;
        next = NULL;
    }
};

int main() {
    // Create nodes manually
    Node* head = new Node(10);   // first node
    Node* second = new Node(20); // second node
    Node* third = new Node(30);  // third node

    // Link them together
    head->next = second;
    second->next = third;

    // Traverse the linked list
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}
