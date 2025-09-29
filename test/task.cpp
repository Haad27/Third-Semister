#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct Node
{
    int reg;
    string name;
    Node *next;
};
Node *head = NULL;

void insertEnd(int regs, string names)
{

    Node *last = new Node;
    last->name = names;
    last->reg = regs;
    last->next = NULL;
    if (head == NULL)
    {
        head = last;
        return;
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
void insertposition(int pos , int reg , string name)
{
    Node * newnode = new Node;
    newnode->name=name;
    newnode->reg= reg;
    Node * temp = head;

    for (int i = 0; i < pos-1; i++)
    {
        temp = temp-> next;
    }

    newnode->next= temp->next;
    temp->next=newnode;


}
void print()
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->name << " ";
        cout << temp->reg << " ";
        temp = temp->next;
        cout << endl;
    }
}
int main()
{

    insertEnd(2024, "haad");
    insertEnd(2024, "haad");
    insertEnd(2024, "haad");
    insertposition(2,202444,"ali");
    print();
    return 0;
}
