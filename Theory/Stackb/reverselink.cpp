#include <iostream>
using namespace std;

struct Stack
{
    int data;  // Changed from char to int
    Stack *next;
};

Stack *top = NULL;

void insert(int num)  // Changed parameter to int
{
    Stack *newstruct = new Stack();
    newstruct->data = num;
    newstruct->next = top;
    top = newstruct;
}

void reverse()
{
    Stack *next = NULL;
    Stack *con = top;
    Stack *prev = NULL;
    
    cout << "Starting reverse process...\n";
    
    while (con != NULL)
    {
        cout << "\nProcessing node with data: " << con->data << endl;
        
        next = con->next;
        cout << "next = " << (next ? next->data : -1) << endl;
        
        con->next = prev;
        cout << "Changed current->next to point to " << (prev ? prev->data : -1) << endl;
        
        prev = con;
        cout << "prev now points to " << prev->data << endl;
        
        con = next;
        cout << "con now points to " << (con ? con->data : -1) << endl;
        
        cout << "Current state: ";
        if (prev) {
            Stack *temp = prev;
            while (temp) {
                cout << temp->data << " → ";
                temp = temp->next;
            }
            cout << "NULL";
        }
        cout << endl;
    }
    
    top = prev;
    cout << "\nFinal: top now points to " << (top ? top->data : -1) << endl;
}

void display()
{
    Stack *temp = top;
    cout << "Stack: ";
    while (temp != NULL)
    {
        cout << temp->data << " → ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    // Insert numbers 10, 20, 30, 40
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    
    cout << "Original stack:\n";
    display();
    
    reverse();
    
    cout << "\nReversed stack:\n";
    display();
    
    return 0;
}