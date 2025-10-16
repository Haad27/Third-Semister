#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Stack
{
    char data;
    Stack *next;
};

Stack *top = NULL;

bool isEmpty()
{
   return top==NULL;
}

void isnert(char num)
{
    Stack *newstruct = new Stack();

    newstruct->data = num;
    newstruct->next = top;
    top = newstruct;
}
void peek()
{
    cout << top->data;
}
char pop()
{
    Stack *temp = top;
    top = top->next;
    return temp->data;
    delete temp;
}
void reverse()
{
    Stack *next = NULL;
    Stack *con = top;
    Stack *prev = NULL;
    while (con != NULL)
    {
        next = con->next;
        con->next = prev;
        prev = con;
        con = next;
    }
    top = prev;
}
void display()
{
    Stack *temp = top;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    string x;
    cout << "enter the world tou wanrt to reverse\n";
    cin >> x;

    for (int i = 0; i < x.length(); i++)
    {
        isnert(x[i]);
    }
       string revered="";
    while (!isEmpty())
    {
        revered+=pop();
    }

    cout << revered;
    // pop();
    // display();
    // reverse();
    // cout << endl;
    // display();
    return 0;
}
