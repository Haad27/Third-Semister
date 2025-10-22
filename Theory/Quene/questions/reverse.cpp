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
    rear->next = newnode; 
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
       if (front == NULL)
        rear = NULL;
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

void reverse(){
    Node * next=NULL;
    Node*prev= NULL;
    Node*curr = front;

    while (curr!=NULL)
    {
        next = curr->next;
        curr->next= prev;
        prev= curr;
        curr=next;
    }
    front = prev;
    
}
int main()
{
    equeue(10),
    equeue(20);
    equeue(30);
    dequene();
    display();
    reverse();
    cout<<endl;
    display();
}