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

    cout << "enter the position";
    cin >> place;
    Node *Temp = new Node();
    Node *todelete = new Node();

    Temp = head;
    if (place == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    else
    {
        for (int i = 0; i < place - 2; i++)
        {
            Temp = Temp->next;
        }
        todelete = Temp->next;
        Temp->next = todelete->next;
        delete todelete;
    }
    display(head);

    return 0;
}
