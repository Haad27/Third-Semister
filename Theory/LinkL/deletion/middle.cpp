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
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

int main()
{

    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();
    Node *fourth = new Node();
    Node *tail = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;
    fourth->data = 4;
    fourth->next = tail;

    tail->data = 5;
    tail->next = nullptr;

    Node *temp = new Node();
    temp = head;
    int sum = 0;
    while (temp != 0)
    {
        temp = temp->next;
        sum++;
    }
  temp = head;
    for (int i = 0; i < (sum/2)-1; i++)
    {
         temp= temp ->next;
    }
    Node * todelete = new Node();

    todelete= temp->next;
    temp->next=todelete->next;
    delete todelete;


    display(head);
    
    return 0;
}
