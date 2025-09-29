#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *head = nullptr;

void insert(int num)
{
    Node *newnode = new Node();

    newnode->data = num;
    newnode->next = head;
    head = newnode;
}

void print()
{
    Node *temp = new Node();
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NUll";
}
void deleted(int pos)
{
    Node *newnode = new Node();
    Node *temp = head;

    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    newnode = temp->next;
    temp->next = newnode->next;
    delete newnode;
}
int main()
{
    insert(100);
    insert(200);
    insert(300);
    deleted(2);
    print();

    return 0;
}
