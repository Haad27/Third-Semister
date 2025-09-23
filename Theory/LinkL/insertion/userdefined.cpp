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

    int place;
    int number;

    cout << "enter the number you want to insert\n";
    cin >> number;
    cout << "enter the position";
    cin >> place;

    Node *Temp = new Node();
    Node *target = new Node();

    Temp = head;

    for (int i = 0; i < place-1; i++)
    {
        Temp = Temp->next;
    }

    target->data = number;

    
    target->next = Temp->next;
    Temp->next = target;

    display(head);

    return 0;
}
