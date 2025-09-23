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

    Node *middle = new Node();
    middle->data = 100;
    int sum = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        temp = temp->next;
        sum++;
    }
    temp = head;
    for (int i = 0; i < sum / 2; i++)
    {
        temp = temp->next;
    }
     
    middle->next=temp->next;
    temp-> next = middle;




    display(head);

    return 0;
}
