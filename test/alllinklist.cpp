#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *head = NULL;
void insert(int num){
      Node * newnode = new Node;
      newnode->data= num;
      newnode->next= head;
       head= newnode;
}
void insertend(int num)
{
    Node *last = new Node;
    last->data = num;
    last->next= NULL;
    if (head == NULL)
    {
         head=last;
    }
    else
    {
        Node *temp = head;

        while (temp->next!=NULL)
        {
            temp = temp->next;
        }
         temp->next=last;
    }
}
void selectedinsert(int num , int pos){
    Node * temp = head;
    Node * newnode = new Node;
    for (int i = 0; i < pos-1; i++)
    {
        temp = temp->next;
    }
    newnode=temp->next;
    newnode->data= num;
}
void selecteddel( int pos){
    Node * temp = head;
    if (head==NULL)
    {
    insert(99999);
    }
    
    Node * newnode = new Node;
    for (int i = 0; i < pos-1 && head->next != NULL; i++)
    {
        temp = temp->next;
    }
    
    newnode=temp->next;
    temp->next=newnode->next;
    delete newnode;
    
}
void print()
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data<<" ";
        temp = temp->next;
    }
}

int main()
{
    insert(100);
    insert(200);
    insert(300);
    insert(400);
    insertend(500);
    insertend(600);
    // selectedinsert(999,2);
    selecteddel(3);
    print();

    return 0;
}
