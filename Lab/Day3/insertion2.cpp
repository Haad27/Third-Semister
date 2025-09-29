#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;
void insert(int num)
{
    Node *newnode = new Node();
    newnode->data = num;
    newnode->next = head;
    head = newnode;
}
void insertEnd(int num)
{
    Node *last = new Node();
    last->data = num;
    last->next = NULL;

    if (head == NULL)
    {
        head = last;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = last;
}

void printList()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "The end" << endl;
}

int main()
{
    cout << "entering from the end\n";
   
    insert(400);
    insert(300);
    insert(200);
    insertEnd(500);
    insertEnd(600);
    printList();

    cout << "Linked List: ";

    return 0;
}
