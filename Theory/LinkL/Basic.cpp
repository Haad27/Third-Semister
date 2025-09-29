#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

void display(Node *n)
{
    while (n != nullptr)
    {
        cout << n->data << endl;
        n = n->next;
    }
}
void insert(Node* head, int num) {
    Node* newnode = new Node;
    newnode->data = num;
    newnode->next = nullptr;

    if (head == nullptr) {   // if list is empty
        head = newnode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

int main()
{
    Node *head = new Node();
    Node *second = new Node();
    Node *tail = new Node();
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = tail;

    tail->data = 3;
    tail->next= nullptr;

    display(head);

    return 0;
}
