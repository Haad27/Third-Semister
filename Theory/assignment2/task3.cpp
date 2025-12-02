#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;

    Node(int val)
    {
        data = val;
        prev = next = NULL;
    }
};

Node *head = NULL;
Node *tail = NULL;

void insert(int value)
{
    Node *newNode = new Node(value);
    if (head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
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

void swapNodes(int a, int b)
{
    if (a == b)
        return; 

    Node *node1 = NULL;
    Node *node2 = NULL;
    Node *current = head;

    while (current)
    {
        if (current->data == a)
            node1 = current;
        if (current->data == b)
            node2 = current;
        current = current->next;
    }

    if (!node1 || !node2)
        return; 

    Node *prev1 = node1->prev;
    Node *next1 = node1->next;
    Node *prev2 = node2->prev;
    Node *next2 = node2->next;
//case 1
    if (node1->next == node2)
    {
        node1->next = next2;
        node1->prev = node2;
        node2->next = node1;
        node2->prev = prev1;
        if (next2)
            next2->prev = node1;
        if (prev1)
            prev1->next = node2;
    }
    //case2
    else if (node2->next == node1)
    { 
        node2->next = next1;
        node2->prev = node1;
        node1->next = node2;
        node1->prev = prev2;
        if (next1)
            next1->prev = node2;
        if (prev2)
            prev2->next = node1;
    }
    //case 3 
    else
    { 
        if (prev1)
            prev1->next = node2;
        if (next1)
            next1->prev = node2;
        if (prev2)
            prev2->next = node1;
        if (next2)
            next2->prev = node1;

        node1->prev = prev2;
        node1->next = next2;
        node2->prev = prev1;
        node2->next = next1;
    }

    if (head == node1)
        head = node2;
    else if (head == node2)
        head = node1;

    if (tail == node1)
        tail = node2;
    else if (tail == node2)
        tail = node1;
}

int main()
{
    insert(3);
    insert(1);
    insert(8);
    insert(5);
    insert(4);
    insert(2);
    insert(9);
    insert(6);
    insert(7);

    cout << "Original list: ";
    display();
    cout << endl;
    swapNodes(3, 7);
    display();
    cout << endl;

    swapNodes(1, 8);
    display();
    cout << endl;

    swapNodes(5, 2);
    display();
    cout << endl;

    return 0;
}