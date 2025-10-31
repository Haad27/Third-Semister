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

void reverseElement(int k){
    if (k==0 || isEmpty())
    {
        return ;
    }

    int val = dequeue();
    reverseElement(k-1);
    enqueue(val);
    
}
void revservetilldigit(int k){
    if (k>count || k<-1)
    {
        return ;
    }

    reverseElement(k);
    for (int i = 0; i < count-k; i++)
    {
        int val = dequeue();
        enqueue(val);
    }
    
}
void recursion(){
    if (isEmpty())
    {
        return;
    }
    int value = dequeue();
    recursion();
    enqueue(value);
}
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    cout << "Original queue: ";
    display();

    int k;
    cout << "Enter K: ";
    cin >> k;

    revservetilldigit(k);

    cout << "Queue after reversing first " << k << " elements: ";
    display();

    return 0;
}
