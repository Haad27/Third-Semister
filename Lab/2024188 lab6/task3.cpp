#include <iostream>
using namespace std;

struct Node
{
    char data;
    Node *next;
};

Node *front = NULL;
Node *rear = NULL;

bool isEMpty()
{
    return front == NULL;
}
void equeue(char value)
{
    Node *newnode = new Node();
    newnode->next = NULL;
    newnode->data = value;
    if (rear == NULL)
    {
        front = rear = newnode;
        return;
    }
    rear->next = newnode;
    rear = newnode;
}

void dequene()
{
    if (isEMpty())
    {
        cout << "isempty";
        return;
    }

    Node *temp = front;
    front = front->next;
    delete temp;
}
void peek()
{
    if (isEMpty())
    {
        cout << "the list is empty";
        return;
    }

    cout << front->data;
}
void display()
{
    Node *temp = front;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    string sentence;
    cout << "enter the string";
    getline(cin, sentence);
    for (int i = 0; i < sentence.length(); i++)
    {
        equeue(sentence[i]);
    }

    display();

    dequene();
    cout << "\nnow we deqeue\n";
    display();
}