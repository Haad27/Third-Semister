#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = NULL;

// Insert at start
void insertStart(int num) {
    Node* newnode = new Node;
    newnode->data = num;
    newnode->next = head;
    newnode->prev = NULL;
    if (head != NULL) {
        head->prev = newnode;
    }
    head = newnode;
}

// Insert at end
void insertEnd(int num) {
    Node* newnode = new Node;
    newnode->data = num;
    newnode->next = NULL;
    if (head == NULL) {
        newnode->prev = NULL;
        head = newnode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

// Insert at given position (1-based index)
void insertAtPos(int num, int pos) {
    if (pos == 1) {
        insertStart(num);
        return;
    }
    Node* newnode = new Node;
    newnode->data = num;
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) return; // invalid pos

    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newnode;
    }
    temp->next = newnode;
}

// Insert at middle
void insertMiddle(int num) {
    if (head == NULL) {
        insertStart(num);
        return;
    }
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        temp = temp->next;
        count++;
    }
    int mid = count / 2 + 1; // middle pos
    insertAtPos(num, mid);
}

// Delete at start
void deleteStart() {
    if (head == NULL) return;
    Node* temp = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    delete temp;
}

// Delete at end
void deleteEnd() {
    if (head == NULL) return;
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    delete temp;
}

// Delete at given position
void deleteAtPos(int pos) {
    if (head == NULL) return;
    if (pos == 1) {
        deleteStart();
        return;
    }
    Node* temp = head;
    for (int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) return;
    if (temp->next != NULL) temp->next->prev = temp->prev;
    if (temp->prev != NULL) temp->prev->next = temp->next;
    delete temp;
}

// Delete middle
void deleteMiddle() {
    if (head == NULL) return;
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        temp = temp->next;
        count++;
    }
    int mid = count / 2 + 1;
    deleteAtPos(mid);
}

// Print forward
void printForward() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Print backward
void printBackward() {
    if (head == NULL) return;
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main() {
    cout << "Insert at head:\n";
    insertStart(10);
    insertStart(20);
    insertStart(30);
    printForward(); cout << "\n";

    cout << "Insert at end:\n";
    insertEnd(40);
    insertEnd(50);
    insertEnd(60);
    printForward(); cout << "\n";

    cout << "Insert at position 3 (999):\n";
    insertAtPos(99, 3);
    printForward(); cout << "\n";

    cout << "Insert at middle (5555):\n";
    insertMiddle(55);
    printForward(); cout << "\n";

    cout << "Delete at position 2:\n";
    deleteAtPos(2);
    printForward(); cout << "\n";

    cout << "Delete start:\n";
    deleteStart();
    printForward(); cout << "\n";

    cout << "Delete end:\n";
    deleteEnd();
    printForward(); cout << "\n";

    cout << "Delete middle:\n";
    deleteMiddle();
    printForward(); cout << "\n";

    cout << "Print backward:\n";
    printBackward();

    return 0;
}
