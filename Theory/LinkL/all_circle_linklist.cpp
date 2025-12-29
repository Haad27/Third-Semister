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

    if (head == NULL) {
        newnode->next = newnode;
        newnode->prev = newnode;
        head = newnode;
        return;
    }

    Node *last = head->prev;
    newnode->next = head;
    newnode->prev = last;
    last->next = newnode;
    head->prev = newnode;
    head = newnode;
}

void insertend(int num) {
    Node *newnode = new Node;
    newnode->data = num;

    if (head == NULL) {
        newnode->next = newnode;
        newnode->prev = newnode;
        head = newnode;
        return;
    }

    Node *last = head->prev;
    newnode->next = head;
    newnode->prev = last;
    last->next = newnode;
    head->prev = newnode;
}

void selectedinsert(int num, int pos) {
    if (pos == 1) {
        insert(num);
        return;
    }

    Node *temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;

    Node *newnode = new Node;
    newnode->data = num;
    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next->prev = newnode;
    temp->next = newnode;
}

void selecteddel(int pos) {
    if (head == NULL) return;

    Node *temp = head;

    if (pos == 1) {
        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }
        Node *last = head->prev;
        head = head->next;
        head->prev = last;
        last->next = head;
        delete temp;
        return;
    }

    for (int i = 1; i < pos && temp->next != head; i++)
        temp = temp->next;

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}

void insertmiddle(int num) {
    if (head == NULL) {
        insert(num);
        return;
    }

    int count = 1;
    Node *temp = head;
    while (temp->next != head) {
        count++;
        temp = temp->next;
    }

    int mid = count / 2;
    temp = head;
    for (int i = 0; i < mid - 1; i++)
        temp = temp->next;

    Node *newnode = new Node;
    newnode->data = num;
    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next->prev = newnode;
    temp->next = newnode;
}

void deletemiddle() {
    if (head == NULL) return;

    int count = 1;
    Node *temp = head;
    while (temp->next != head) {
        count++;
        temp = temp->next;
    }

    int mid = count / 2;
    temp = head;
    for (int i = 0; i < mid; i++)
        temp = temp->next;

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    if (temp == head)
        head = temp->next;

    delete temp;
}

void deletestart() {
    if (head == NULL) return;

    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    Node *last = head->prev;
    Node *temp = head;
    head = head->next;
    head->prev = last;
    last->next = head;
    delete temp;
}

void deleteend() {
    if (head == NULL) return;

    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    Node *last = head->prev;
    last->prev->next = head;
    head->prev = last->prev;
    delete last;
}

void print() {
    if (head == NULL) return;

    Node *temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insertend(40);
    insertend(50);
    selectedinsert(99, 2);
    selecteddel(3);
    insertmiddle(77);
    deletemiddle();
    deletestart();
    deleteend();
    print();
    return 0;
}
