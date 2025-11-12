#include <iostream>
using namespace std;

#define SIZE 3
int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int val) {
    if ((rear + 1) % SIZE == front)
        cout << "Queue Overflow\n";
    else {
        if (front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        queue[rear] = val;
    }
}

void dequeue() {
    if (front == -1)
        cout << "Queue Underflow\n";
    else {
        cout << "Dequeued: " << queue[front] << endl;
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
    }
}

void display() {
    if (front == -1) {
        cout << "Queue is empty\n";
        return;
    }

    cout << "Queue: ";

    // Case 1: rear is ahead or equal to front (normal case)
    if (rear >= front) {
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
    } 
    // Case 2: circular wrap-around
    else {
        // print from front to end of array
        for (int i = front; i < SIZE; i++) {
            cout << queue[i] << " ";
        }
        // then print from start to rear
        for (int i = 0; i <= rear; i++) {
            cout << queue[i] << " ";
        }
    }

    cout << endl;
}
