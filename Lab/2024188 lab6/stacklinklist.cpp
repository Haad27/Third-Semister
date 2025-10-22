#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *top = NULL;  
Node *top2=NULL;
bool isEmpty() {
    return top == NULL;
}

void push(int value) {
    Node *newnode = new Node();
    newnode->data = value;
    newnode->next = top;  
    top = newnode;      
    cout << "Inserted " << value << endl;
}

int pop() {
    if (isEmpty()) {
        cout << "Stack Underflow\n";
        return -1;
    }
    Node *temp = top;
    int value = top->data;
    cout << "Popped " << top->data << endl;
    top = top->next;  
    delete temp;  
    return  value;
}

void peek() {
    if (isEmpty()) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Top element: " << top->data << endl;
}

void display() {
    if (isEmpty()) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Stack elements: ";
    Node *temp = top;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void queue(){
   Node* next=NULL;
   Node*prev=NULL;
   Node* curr = top;

   while (curr!=NULL)
   {
    next=curr->next;
    curr->next = prev;
    prev=curr;
    curr=next;
   }
   top = prev;
   
}
void fill(){
    
}
int main() {
    push(10);
    push(20);
    push(30);
    // display();
    // peek();
    // pop();
    display();
    queue();
    display();
    pop();
    display();
    return 0;
}
