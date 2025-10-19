#include <iostream>
using namespace std;

#define MAX 6

string arr[MAX] ;
int top = -1;

bool isEmpty()
{
    return top == -1;
}

bool isFull()
{
    return top == MAX - 1;
}
int num = 0;

void push(char value)
{
    if (isFull())
    {
        cout << "Stack Overflow\n";
        return;
    }
    arr[++top] = value;
    cout << "Inserted " << value << endl;
    num++;
}

bool check()
{
    int start = 0;
    int end = num-1;
    while (start <= end)
    {
        if (arr[start] != arr[end])
        {
            start++;
            end--;
            
        }
        else if(arr[start] == arr[end])
        {
            return false;
        }
    }
    return true;
}
void display()
{
    if (isEmpty())
    {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Stack elements: ";
    for (int i = 0; i <= top; i++)
    {
        cout <<"elemtss "<<i<< arr[i] << " \n";
    }
    cout << endl;
}

int main()
{
    string sentence;
    cout << "enter the () \n";
    cin >> sentence;
    for (int i = 0; i < sentence.length(); i++)
    {
        push(sentence[i]);
    }
    if (check())
    {
        cout << "correct";
    }
    else if (!check())
    {
        cout << "wrong";
    }
}
