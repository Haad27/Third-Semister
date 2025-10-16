#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

Node *head = NULL;

void insert(int num)
{
    Node *newnode = new Node();
    newnode->data = num;

    if (head == NULL)
    {
        newnode->prev = newnode;
        newnode->next = newnode;
        head = newnode;
    }
    else
    {
        Node *last = head->prev;

        newnode->next = head;
        newnode->prev = last;
        last->next = newnode;
        head->prev = newnode;
        head = newnode;
    }
}
void insert_end(int num)
{
    Node *newnode = new Node();
    newnode->data = num;

    if (head == NULL)
    {
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
void insert_specific(int num, int pos)
{
    if (head == NULL)
    {
        cout << "List empty\n";
        return;
    }
    Node *temp = head;

    for (int i = 0; i < pos - 1 && temp->next != head; i++)
    {
        temp = temp->next;
    }
    Node *newnode = new Node();
    newnode->data = num;

    newnode->next = temp->next;
    newnode->prev = temp;
    newnode->next->prev = newnode;
    temp->next = newnode;
}
void insert_middle(){
    Node * temp= head;
    int sum =0;
    while (temp!=head)
    {
        temp= temp ->next;
        sum ++;
    
    }
    temp = head;
    for (int i = 0; i < sum/2; i++)
    {
        temp = temp -> next;
    }
    Node * newnode = new Node ();
    
    
    
}
void display()
{
    Node *temp = head;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << "\nreverse\n";

    temp = head->prev;
    do
    {
        cout << temp->data << " ";
        temp = temp->prev;
    } while (temp != head->prev);
}
int main()
{
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert_end(60);
    insert_end(70);
    insert_specific(100, 3);

    display();

    return 0;
}
