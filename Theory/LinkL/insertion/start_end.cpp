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
    tail->next = nullptr;

    Node *new_head = new Node();

    new_head->data = 0;
    new_head->next = head;
    head = new_head; // this is the main important line

    Node *new_tail = new Node();
    new_tail->data = 4;

    Node *temp = new Node();
    temp->next = head;
    while (temp != nullptr)
    {
        temp = temp->next;
    }
    tail->next = new_tail;

    display(head);

    return 0;
}
