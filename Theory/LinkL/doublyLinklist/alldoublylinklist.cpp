#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev;
    Node *next;
};

Node *head = NULL;

void insert(int num) {
    Node *newnode = new Node;
    newnode->data = num;
    newnode->next = head;
    newnode->prev = NULL;
    if (head != NULL)
        head->prev = newnode;
    head = newnode;
}

void insertend(int num) {
    Node *newnode = new Node;
    newnode->data = num;
    newnode->next = NULL;
    if (head == NULL) {
        newnode->prev = NULL;
        head = newnode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
}

void selectedinsert(int num, int pos) {
    Node *temp = head;
    for (int i = 0; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) return;
    Node *newnode = new Node;
    newnode->data = num;
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newnode;
    temp->next = newnode;
}

void selecteddel(int pos) {
    if (head == NULL) return;
    Node *temp = head;
    for (int i = 0; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) return;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    delete temp;
}

void insertmiddle(int num) {
    if (head == NULL) {
        insert(num);
        return;
    }
    Node *temp = head;
    int count = 0;
    while (temp->next != NULL) {
        count++;
        temp = temp->next;
    }
    int mid = count / 2;
    temp = head;
    for (int i = 0; i < mid; i++)
        temp = temp->next;
    Node *newnode = new Node;
    newnode->data = num;
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newnode;
    temp->next = newnode;
}

void deletemiddle() {
    if (head == NULL) return;
    Node *temp = head;
    int count = 0;
    while (temp->next != NULL) {
        count++;
        temp = temp->next;
    }
    int mid = count / 2;
    temp = head;
    for (int i = 0; i < mid; i++)
        temp = temp->next;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    delete temp;
}

void deletestart() {
    if (head == NULL) return;
    Node *temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    delete temp;
}

void deleteend() {
    if (head == NULL) return;
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;
    delete temp;
}

void print() {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    cout << "Insert at head:\n";
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    print();

    cout << "\nInsert at end:\n";
    insertend(50);
    insertend(60);
    insertend(70);
    print();

    cout << "\nInsert at selected position (pos=2, value=999):\n";
    selectedinsert(999, 2);
    print();

    cout << "\nDelete at selected position (pos=3):\n";
    selecteddel(3);
    print();

    cout << "\nInsert at middle (55):\n";
    insertmiddle(55);
    print();

    cout << "\nDelete middle:\n";
    deletemiddle();
    print();

    cout << "\nDelete start:\n";
    deletestart();
    print();

    cout << "\nDelete end:\n";
    deleteend();
    print();

    return 0;
}
