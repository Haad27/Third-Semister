#include <iostream>
#include <string>
#include <vector>

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
   Node *newnode = new Node;
    newnode->data = num;
    newnode->next = head;
    newnode->prev = NULL;
    if (head!=NULL)
    {
        head->prev = newnode ;
    }
    
    head = newnode;
}
void insert_end(int num)
{
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
    }
}

void display()
{

    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data <<" ";
        temp = temp->next;
    }
}
int main()
{
    insert(100);
    insert(200);
    insert(300);
    insert(400);
    insert(500);

    display();

    return 0;
}
