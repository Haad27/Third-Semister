#include <iostream>
using namespace std;

// Node structure for doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Global head pointer
Node* head = nullptr;

// Function to insert node at the end
void insertEnd(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
        newNode->prev = nullptr;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Function to split a doubly linked list into two halves
Node* split(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* second = slow->next;
    slow->next = nullptr;
    if (second)
        second->prev = nullptr;

    return second;
}

// Merge two sorted doubly linked lists
Node* merge(Node* first, Node* second) {
    if (!first)
        return second;
    if (!second)
        return first;

    if (first->data <= second->data) {
        first->next = merge(first->next, second);
        if (first->next)
            first->next->prev = first;
        first->prev = nullptr;
        return first;
    } else {
        second->next = merge(first, second->next);
        if (second->next)
            second->next->prev = second;
        second->prev = nullptr;
        return second;
    }
}

// Merge sort function
Node* mergeSort(Node* node) {
    if (!node || !node->next)
        return node;

    Node* second = split(node);

    node = mergeSort(node);
    second = mergeSort(second);

    return merge(node, second);
}

// Function to print the doubly linked list
void printList(Node* node) {
    while (node) {
        cout << node->data;
        if (node->next)
            cout << " -> ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(8);
    insertEnd(17);
    insertEnd(5);
    insertEnd(13);
    insertEnd(4);

    cout << "Original List: ";
    printList(head);

    head = mergeSort(head);

    cout << "Sorted List:   ";
    printList(head);

    return 0;
}
