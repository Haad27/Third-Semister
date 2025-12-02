#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;

    Node(int val)
    {
        data = val;
        prev = next = NULL;
    }
};

Node* head = NULL;
Node* tail = NULL;

void insert(int value)
{
    Node* newNode = new Node(value);
    if (!head)
        head = tail = newNode;
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void display()
{
    Node* temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* findNodeByPosition(int pos)
{
    Node* temp = head;
    int count = 1;
    while (temp && count < pos)
    {
        temp = temp->next;
        count++;
    }
    return temp; 
}

void swapHeadWithPosition(int pos)
{
    if (pos <= 1 || !head || !head->next) return; 

    Node* node1 = head;
    Node* node2 = findNodeByPosition(pos);

    if (!node2) return; 

    Node* next1 = node1->next;
    Node* prev2 = node2->prev;
    Node* next2 = node2->next;

    if (next1 == node2)
    {
        node1->next = next2;
        node1->prev = node2;
        node2->next = node1;
        node2->prev = NULL;

        if (next2) next2->prev = node1;
        head = node2;
        if (tail == node2) tail = node1;
        return;
    }

    if (prev2) prev2->next = node1;
    if (next2) next2->prev = node1;

    node1->prev = prev2;
    node1->next = next2;

    node2->prev = NULL;
    node2->next = next1;
    if (next1) next1->prev = node2;

    head = node2;

    if (tail == node2) tail = node1;
}

int main()
{
    insert(11);
    insert(3);
    insert(8);
    insert(2);
    insert(1);

    cout << "Original list: ";
    display();

    int pos;
    cout << "Enter position to swap with head: ";
    cin >> pos;

    swapHeadWithPosition(pos);

    cout << "List after swapping head: ";
    display();

    return 0;
}
