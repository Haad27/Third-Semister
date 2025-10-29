#include <iostream>
using namespace std;

// Doubly Linked List Node
struct Node
{
    int data;
    Node *prev;
    Node *next;
};

Node *head = NULL;

void insertAtHead(int num)
{
    Node *newnode = new Node;
    newnode->data = num;
    newnode->prev = NULL;
    newnode->next = head;
    if (head != NULL)
        head->prev = newnode;
    head = newnode;
}

void insertAtEnd(int num)
{
    Node *newnode = new Node;
    newnode->data = num;
    newnode->next = NULL;

    if (head == NULL)
    {
        newnode->prev = NULL;
        head = newnode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;
}

void insertAtPosition(int num, int pos)
{
    if (pos <= 1 || head == NULL)
    {
        insertAtHead(num);
        return;
    }

    Node *temp = head;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++)
        temp = temp->next;

    Node *newnode = new Node;
    newnode->data = num;
    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newnode;

    temp->next = newnode;
}

void deleteAtPosition(int pos)
{
    if (head == NULL || pos < 1)
        return;

    Node *temp = head;

    if (pos == 1)
    {
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
        delete temp;
        return;
    }

    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
        return;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
}

void insertInMiddle(int num)
{
    if (head == NULL)
    {
        insertAtHead(num);
        return;
    }

    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    int mid = count / 2;
    temp = head;
    for (int i = 0; i < mid - 1; i++)
        temp = temp->next;

    Node *newnode = new Node;
    newnode->data = num;
    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newnode;
    temp->next = newnode;
}

void deleteMiddle()
{
    if (head == NULL)
        return;

    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    int mid = count / 2;
    temp = head;
    for (int i = 0; i < mid; i++)
        temp = temp->next;

    if (temp == NULL)
        return;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
}

void deleteStart()
{
    if (head == NULL)
        return;

    Node *temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    delete temp;
}

void deleteEnd()
{
    if (head == NULL)
        return;

    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;

    delete temp;
}

// Display the list
void printList()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void printReverse()
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        // cout << temp->data << " ";
        temp = temp->next;
    }

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
}
void reverse()
{
    Node *temp = NULL;
    Node *curr = head;

    while (curr != NULL)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        curr = curr->prev;
    }

    head = temp->prev;
}
void clearList()
{
    Node *temp = head;
    while (temp != NULL)
    {
        Node *next = temp->next;
        delete temp;
        temp = next;
    }
    head = NULL;
}
bool palindrome(){
    Node *temp1=head;
    Node *temp2=head;
    while (temp2->next!=NULL)
    {
     temp2=temp2->next;
    }
    
    while (temp1 && temp2 && temp1 != temp2 && temp1->next != temp2)
    {
        if (temp1->data!=temp2->data)
        {
            return false;
        }
        temp1= temp1->next;
        temp2=temp2->prev;
    }
    return true;
    
}
void removeDuplicates() {
    if (head == NULL)
        return;

    Node* curr = head;
    while (curr->next != NULL) {
        if (curr->data == curr->next->data) {
            Node* dup = curr->next;
            curr->next = dup->next;
            if (dup->next != NULL)
                dup->next->prev = curr;
            delete dup;
        } else {
            curr = curr->next;
        }
    }
}
void sortList() {
    if (head == NULL)
        return;

    Node* temp1 = head;
    Node* temp2 = NULL;

    // Outer loop
    while (temp1 != NULL) {
        temp2 = temp1->next;

        // Inner loop
        while (temp2 != NULL) {
            if (temp1->data > temp2->data) {
                // Swap the data
                int temp = temp1->data;
                temp1->data = temp2->data;
                temp2->data = temp;
            }
            temp2 = temp2->next;
        }

        temp1 = temp1->next;
    }
}
void reverseUntil(int val)
{
    if (head == NULL || head->next == NULL)
        return;

    Node* curr = head;
    Node* temp = NULL;

    // Step 1: Find the stopNode
    while (curr != NULL && curr->data != val)
        curr = curr->next;

    if (curr == NULL) {
        cout << "Value not found in list." << endl;
        return;
    }

    Node* stopNode = curr;  // reverse until this node

    // Step 2: Reversal logic (same as full reverse)
    curr = head;
    while (curr != stopNode->next)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        curr = curr->prev;  // move forward in the reversed direction
    }

    // Step 3: Fix head and tail connections
    if (temp != NULL)
    {
        head->next = curr;      // old head (which is now the tail) → next = curr
        if (curr != NULL)
            curr->prev = head;  // connect next part back
    }

    head = temp->prev;  // update head to new head (stopNode)
}

// Main function for demonstration
int main()
{
    cout << "Insert at head:\n";
    insertAtHead(10);
    insertAtHead(20);
    insertAtHead(30);
    insertAtHead(40);
    printList();

    cout << "\nInsert at end:\n";
    insertAtEnd(50);
    insertAtEnd(60);
    insertAtEnd(70);
    printList();

    cout << "\nInsert at selected position (pos=2, value=999):\n";
    insertAtPosition(999, 2);
    printList();

    cout << "\nDelete at selected position (pos=3):\n";
    deleteAtPosition(3);
    printList();

    cout << "\nInsert at middle (55):\n";
    insertInMiddle(55);
    printList();

    cout << "\nDelete middle:\n";
    deleteMiddle();
    printList();

    cout << "\nDelete start:\n";
    deleteStart();
    printList();

    cout << "\nDelete end:\n";
    deleteEnd();
    printList();

    printReverse();
    cout << endl;
    printList();

    cout << endl
         << endl;
    reverse();
    printList();

    return 0;
}
