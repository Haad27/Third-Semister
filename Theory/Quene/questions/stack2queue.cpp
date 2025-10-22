#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Queue using linked list
struct Queue {
    Node* front;
    Node* rear;

    Queue() {
        front = rear = NULL;
    }

    bool empty() {
        return front == NULL;
    }

    void enqueue(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = NULL;

        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue() {
        if (empty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        Node* temp = front;
        int val = temp->data;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        delete temp;
        return val;
    }

    int peek() {
        if (empty()) return -1;
        return front->data;
    }

    void reverse() {
        Node* prev = NULL;
        Node* curr = front;
        Node* next = NULL;
        rear = front; // old front becomes new rear
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        front = prev;
    }

    void display() {
        Node* temp = front;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Stack using two queues
struct StackUsingQueues {
    Queue q1, q2;

    void push(int x) {
        // enqueue into q1
        q1.enqueue(x);
        // reverse q1
        q1.reverse();
        // move q1 into q2
        while (!q1.empty()) {
            q2.enqueue(q1.dequeue());
        }
    }

    void pop() {
        if (q2.empty()) {
            cout << "Stack is empty!\n";
            return;
        }
        q2.dequeue();
    }

    int top() {
        if (q2.empty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return q2.peek();
    }

    bool empty() {
        return q2.empty();
    }

    void display() {
        q2.display();
    }
};

int main() {
    StackUsingQueues s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Stack (top first): ";
    s.display();

    cout << "Top element: " << s.top() << endl;

    s.pop();
    cout << "After pop: ";
    s.display();

   return 0;
}