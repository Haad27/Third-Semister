#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *front = NULL;
Node *rear = NULL;
int count = 0; 

bool isEmpty() {
    return front == NULL;
}

void enqueue(int value) {
    Node *newnode = new Node();
    newnode->data = value;
    newnode->next = NULL;

    if (rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
    count++;
}

int dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty!\n";
        return -1;
    }

    Node *temp = front;
    int value = temp->data;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    delete temp;
    count--;
    return value;
}

void display() {
    Node *temp = front;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void stack(){
    if (isEmpty())
    {
        return;
    }
    
    int value = dequeue();
    stack();
    enqueue(value);
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    stack();
    dequeue();
    display();
}