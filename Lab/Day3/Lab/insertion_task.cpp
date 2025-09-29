#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = nullptr; // make head global for simplicity

void insertAtHead(int num)
{
    Node *newnode = new Node();
    newnode->data = num;
    newnode->next = head; // point to old head
    head = newnode;       // update head
}
void insertAtPosition(int pos, int num) {
    Node* newnode = new Node();
    newnode->data = num;
    newnode->next = nullptr;

    if (pos == 1) {
        newnode->next = head;
        head = newnode;
        return;
    }

    // Traverse to (pos-1)th node
    Node* temp = head;
    for (int i = 1; i < pos - 1 ; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Invalid position!" << endl;
        delete newnode;
        return;
    }

    // Insert node
    newnode->next = temp->next;
    temp->next = newnode;
}

void printList()
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL";
}

int main()
{
    insertAtHead(100);
    insertAtHead(200);
    insertAtHead(300);
    insertAtPosition(2, 50);
    printList(); // Expected: 300 -> 200 -> 100 -> NULL
    return 0;
}
