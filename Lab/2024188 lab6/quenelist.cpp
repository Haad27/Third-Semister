#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *front = NULL;
Node *rear = NULL;

bool isEMpty()
{
    return front == NULL;
}
void equeue(int value)
{
    Node *newnode = new Node();
    newnode->next = NULL;
    newnode->data = value;
    if (rear == NULL)
    {
        front = rear = newnode;
        return;
    }
    newnode->next = rear;
    rear = newnode;
}

void dequene()
{
    if (isEMpty())
    {
        cout << "isempty";
        return;
    }

    Node *temp = front;
    front = front->next;
    delete temp;
}
void peek()
{
    if (isEMpty())
    {
        cout <<"the list is empty";
        return;
    }
    
    cout << front->data;
}
void display()
{
    Node *temp = front;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    equeue(10),
    equeue(20);
    equeue(30);
    dequene();
    display();
}