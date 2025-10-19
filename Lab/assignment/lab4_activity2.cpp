#include <iostream>
using namespace std;

struct Node
{
    char data;
    Node *next;
};

Node *top = NULL;

bool isEmpty()
{
    return top == NULL;
}

void push(char value)
{
    Node *newnode = new Node();
    newnode->data = value;
    newnode->next = top;
    top = newnode;
    // cout << "Inserted " << value << endl;
}

char pop()
{
    if (isEmpty())
    {
        cout << "Stack Underflow\n";
        return '\0';
    }
    Node *temp = top;
    char val = temp->data;
    top = top->next;
    delete temp;
    return val;
}



void peek()
{
    if (isEmpty())
    {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Top element: " << top->data << endl;
}

void display()
{
    if (isEmpty())
    {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Stack elements: ";
    Node *temp = top;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void reverse()
{
    Node *curr = top;
    Node *next = NULL;
    Node *prev = NULL;

    while(curr!=NULL){
        next = curr->next;
        curr->next= prev;
        prev = curr;
        curr =next;
    
    }
    top = prev;
}
int main()
{
    string sentence;
    cout <<"enter the string you want to reverse\n";
    getline(cin,sentence);

    for (int i = 0; i < sentence.length(); i++)
    {
        push(sentence[i]);
    }
    string res="";
    for (int i = 0; i < sentence.length(); i++)
    {
        res += pop();
    }
    cout <<"result :" << res;
    return 0;
}
