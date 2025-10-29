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
    newnode->next = head; // point new node's next to old head
    newnode->prev = NULL; // new node is now the first, so prev = NULL

    if (head != NULL)
    {
        head->prev = newnode; // fix old head's prev pointer
    }

    head = newnode; // update head
}
void between(int num, int pos)
{
    Node *newnode = new Node();
    newnode->data = num;
    Node *temp = head;
    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    newnode->next=temp->next;
    newnode->prev = temp;
}
void display()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    insert(100);
    insert(200);
    insert(300);
    insert(400);

    cout << "Doubly Linked List: ";
    between(4000,2);
    display();


    return 0;
}
