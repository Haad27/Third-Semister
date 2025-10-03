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
void insert(int num)
{
    Node *newnode = new Node;
    newnode->data = num;
    newnode->next = head;
    head = newnode;
}
void insertend(int num)
{
    Node *last = new Node;
    last->data = num;
    last->next = NULL;
    if (head == NULL)
    {
        head = last;
    }
    else
    {
        Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = last;
    }
}
void selectedinsert(int num, int pos)
{
    Node *temp = head;
    Node *newnode = new Node;
    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    newnode = temp->next;
    newnode->data = num;
}
void selecteddel(int pos)
{
    Node *temp = head;
    if (head == NULL)
    {
        insert(99999);
    }

    Node *newnode = new Node;
    for (int i = 0; i < pos - 2 && head->next != NULL; i++)
    {
        temp = temp->next;
    }

    newnode = temp->next;
    temp->next = newnode->next;
    delete newnode;
}
void print()
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void insertmiddle(int num)
{
     if (head==NULL)
    {
        insert(200000);
    }
    Node *temp = head;
    Node *newnode = new Node;
    newnode->data = num;
    newnode->next = NULL;
    int sum = 0;
    while (temp ->next!= NULL)
    {
        temp = temp->next;
        sum++;
    }
    Node *temp1 = head;

    for (int i = 0; i < sum/2; i++)
    {
        temp1 = temp1->next;
    }

    newnode->next=temp1->next;
    temp1->next = newnode;
}
void deletemiddle()
{
    if (head==NULL)
    {
        insert(200000);
    }
    
    Node *temp = head;
    Node *newnode = new Node;
    int sum = 0;
    while (temp ->next!= NULL)
    {
        temp = temp->next;
        sum++;
    }
    Node *temp1 = head;

    for (int i = 0; i < (sum/2)-1; i++)
    {
        temp1 = temp1->next;
    }

    newnode = temp1->next;
    temp1->next = newnode->next;
    delete newnode;
}
void deletestart(){
    Node * newnode=new Node;

    if (head ==NULL)
    {
        insert(600000);
    }
    
    newnode = head;
    head = head->next;
    delete newnode;
}
void deleteend(){
    Node * temp = head;
    while (temp->next->next!= NULL)
    {
        temp=temp->next;
    }

    temp->next=NULL;

    
}



int main()
{
 
    cout << "Insert at head: \n";
    insert(10); 
    insert(20); 
    insert(30); 
    insert(40); 
    print(); 
    cout << "\n\n";

    cout << "Insert at end: \n";
    insertend(50); 
    insertend(60); 
    insertend(70); 
    print(); cout << "\n\n";

    cout << "Insert at selected position (pos=2, value=999): \n";
    selectedinsert(999, 2); 
    print(); cout << "\n\n";

    cout << "Delete at selected position (pos=3): \n";
    selecteddel(3); 
    print(); cout << "\n\n";

    cout << "Insert at middle (55): \n";
    insertmiddle(55); 
    print(); cout << "\n\n";

    cout << "Delete middle: \n";
    deletemiddle(); 
    print(); cout << "\n\n"; cout << "Delete start: \n";
    deletestart(); 
    print(); cout << "\n\n"; cout << "Delete end: \n";
    deleteend(); 
    print(); cout << "\n\n";

    return 0; 
}


