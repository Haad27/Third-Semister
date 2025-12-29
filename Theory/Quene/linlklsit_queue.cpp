#include <iostream>
using namespace std;

struct Queue {
    int data;
    Queue* next;
};

Queue* front = NULL;
Queue* rear = NULL;

bool isEmpty() {
    if (front == NULL)
        return true;
    return false;
}

void enqueue(int num) {
    Queue* newnode = new Queue();
    newnode->data = num;
    newnode->next = NULL;

    if (isEmpty()) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
        return;
    }

    Queue* temp = front;
    front = front->next;
    delete temp;

    if (front == NULL) {
        rear = NULL;
    }
}

void peek() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
        return;
    }
    cout << front->data << endl;
}

void display() {
    Queue* temp = front;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {

    enqueue(100);
    enqueue(200);
    enqueue(300);

    dequeue();

    display();

    return 0;
}
