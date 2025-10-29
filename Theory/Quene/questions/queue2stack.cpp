#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Stack using linked list
struct Stack {
    Node* top;

    Stack() {
        top = NULL;
    }

    bool empty() {
        return top == NULL;
    }

    void push(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (empty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        Node* temp = top;
        int val = temp->data;
        top = top->next;
        delete temp;
        return val;
    }

    int peek() {
        if (empty()) return -1;
        return top->data;
    }

    // Reverse stack using linked list pointers
    void reverse() {
        Node* prev = NULL;
        Node* curr = top;
        Node* next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        top = prev;
    }

    void display() {
        Node* temp = top;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Queue using two stacks
struct QueueUsingStacks {
    Stack s1, s2;

    void enqueue(int x) {
        // Step 1: Push to s1
        s1.push(x);

        // Step 2: Reverse s1 so front is at bottom
        s1.reverse();

        // Step 3: Move s1 to s2 (so s2 acts as queue)
        while (!s1.empty()) {
            s2.push(s1.pop());
        }
    }

    void dequeue() {
        if (s2.empty()) {
            cout << "Queue is empty!\n";
            return;
        }
        s2.pop();
    }
 
    int front() {
        if (s2.empty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return s2.peek();
    }

    bool empty() {
        return s2.empty();
    }

    void display() {
        // Reverse temporarily for correct front-to-rear view
        s2.reverse();
        s2.display();
        s2.reverse(); // restore
    }         
};

int main() {
    QueueUsingStacks q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Queue (front first): ";
    q.display();

    cout << "Front element: " << q.front() << endl;

    q.dequeue();
    cout << "After dequeue: ";
    q.display();

   return 0;
}