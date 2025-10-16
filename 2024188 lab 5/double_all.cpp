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
    newnode->next = head;
    if (head != NULL)
    {
        head->prev = newnode;
    }
    head = newnode;
}

void insert_end(int num)
{
    Node *temp = head;
    Node *last = new Node();
    last->data = num;
    if (head == NULL)
    {
        insert(num);
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = last;
    last->next = NULL;
    last->prev = temp;
}
void insert_specific_position(int num, int pos)
{
    Node *temp = head;
    for (int i = 0; i < pos - 2; i++)
    {
        temp = temp->next;
    }
    Node *newnode = new Node();
    newnode->data = num;


    newnode->next = temp->next; // 
    temp->next = newnode;
    newnode->prev = temp;
    newnode->next->prev = newnode;
}
void insert_middle(int num)
{
    Node *newnode = new Node();
    Node *temp = head;
    int sum = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        sum++;
    }
    insert_specific_position(num, sum / 2);
}
void deleted()
{
    Node *del = head;
    head = head->next;
    del->next = NULL;
    head->prev = NULL; // i made a mistake on this step
    delete del;
}

void delete_end()
{
    Node *temp = head;

    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->prev->next = NULL; // this line
    delete temp;
}

void delete_specific(int pos)
{
    Node *temp = head;
    for (int i = 0; i < pos - 2; i++)
    {
        temp = temp->next;
    }
    Node *del = temp->next;
    temp->next = del->next;
    if (del->next != NULL)
    {
        del->next->prev = temp;
    }

    delete del;
}
void delete_middle()
{
    Node *newnode = new Node();
    Node *temp = head;
    int sum = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        sum++;
    }
    delete_specific(sum / 2);
}
void display()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "  ";
        if (temp->next == NULL)
            break;

        temp = temp->next;
    }
    cout << "\nreverse \n";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
}

void reverse()
{
    Node *temp = NULL;
    Node *current = head;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
        head = temp->prev;
}

int main()
{
    insert(100);
    insert(200);
    insert(300);
    insert(400);
    insert(500);
    insert(600);
    insert(700);

    display();

    // cout << "\ninsert at end\n";
    // insert_end(800);
    // display();
    // cout << "\ninsert at middle\n";
    // insert_middle(1000);
    // display();

    cout << "\ninsert at position 2 11000\n";
    insert_specific_position(11000, 2);
    display();

    // cout << "\n\n\ndeleting\n";
    // deleted();
    // display();
    // cout << "\n\n\ndeleting from end\n";

    // delete_end();
    // display();

    cout << "\n\n\ndeleting at 3 position \n";
    delete_specific(3);
    display();

    // cout << "\n\n\ndeleting at middle position \n";
    // delete_middle();
    // display();

  
}