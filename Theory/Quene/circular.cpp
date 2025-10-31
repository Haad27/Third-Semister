#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct CircularQueue {
    Node* front;
    Node* rear;
    int size;
    int capacity;
};

CircularQueue q;

// 🔹 Initialize queue
void init(int k) {
    q.front = q.rear = NULL;
    q.size = 0;
    q.capacity = k;
}

bool enQueue(int value) {
    if (q.size == q.capacity)
        return false;

    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (q.front == NULL) { 
        q.front = q.rear = newNode;
        q.rear->next = q.front;
    } else {
        q.rear->next = newNode;
        q.rear = newNode;
        q.rear->next = q.front;
    }

    q.size++;
    return true;
}

bool deQueue() {
    if (q.front == NULL)
        return false;

    if (q.front == q.rear) { 
        delete q.front;
        q.front = q.rear = NULL;
    } else {
        Node* temp = q.front;
        q.front = q.front->next;
        q.rear->next = q.front;
        delete temp;
    }

    q.size--;
    return true;
}
int Front() {
    if (q.front == NULL)
        return -1;
    return q.front->data;
}
int Rear() {
    if (q.rear == NULL)
        return -1;
    return q.rear->data;
}
bool isEmpty() {
    return q.size == 0;
}
bool isFull() {
    return q.size == q.capacity;
}

// 🔹 Display queue
void display() {
    if (q.front == NULL) {
        cout << "Queue is empty!\n";
        return;
    }

    Node* temp = q.front;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != q.front);
    cout << endl;
}

// 🔹 Main function
int main() {
    init(5);

    enQueue(10);
    enQueue(20);
    enQueue(30);
    enQueue(40);

    cout << "Queue: ";
    display();

    cout << "Front: " << Front() << endl;
    cout << "Rear: " << Rear() << endl;

    deQueue();
    cout << "After dequeue: ";
    display();

    enQueue(50);
    cout << "After enqueue 50: ";
    display();

    return 0;
}
