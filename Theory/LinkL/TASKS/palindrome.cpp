#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void insert(Node *&head, int val)
{
    Node *newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool isPalindrome(Node *head)
{
    if (head == NULL || head->next == NULL)
        return true;

    // Step 1: Find the middle node
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse the second half
    Node *prev = NULL;
    Node *curr = slow;
    Node *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // Step 3: Compare both halves
    Node *first = head;
    Node *second = prev; // head of reversed second half
    while (second != NULL)
    {
        if (first->data != second->data)
            return false;
        first = first->next;
        second = second->next;
    }

    return true;
}

int main()
{
    Node *head = NULL;

    // Example: Palindrome list
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 2);
    insert(head, 1);

    cout << "Linked List: ";
    display(head);

    if (isPalindrome(head))
        cout << "It is a palindrome." << endl;
    else
        cout << "It is not a palindrome." << endl;

    return 0;
}
