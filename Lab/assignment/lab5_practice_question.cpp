#include <iostream>
using namespace std;

struct Node
{
    string data;   
    Node *next;
};

Node *front = NULL;
Node *rear = NULL;

bool isEmpty()
{
    return front == NULL;
}

void Enqueue(string value)
{
    Node *newnode = new Node();
    newnode->data = value;
    newnode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newnode;
        return;
    }
    rear->next = newnode;
    rear = newnode;
}

void Dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return;
    }
    Node *temp = front;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    delete temp;
}

void Display()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return;
    }

    Node *temp = front;
    cout << "Queue elements: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


int LengthOfString()
{
    int totalLength = 0;
    while (!isEmpty())
    {
        totalLength += front->data.length();
        Dequeue();
    }
    return totalLength;
}

int main()
{
    int n;
    cout << "Enter number of strings to enqueue: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        string str;
        cout << "Enter string " << i + 1 << ": ";
        getline(cin, str);
        Enqueue(str);
    }

    Display();

    int len = LengthOfString();
    cout << "Total number of characters (after dequeuing all): " << len << endl;

    Display(); 
}
