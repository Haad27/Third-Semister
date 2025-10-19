#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

Node *head = NULL;

// Function to insert at the beginning
void insert(int num)
{
    Node *newnode = new Node();
    newnode->data = num;

    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
        newnode->prev = head; // In a circular list, prev also points to head
    }
    else
    {
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
        newnode->next = head;
        head->prev = newnode;
    }
}

// Function to insert at the end
void insert_end(int num)
{
    Node *temp = head;
    Node *last = new Node();
    last->data = num;

    if (head == NULL)
    {
        insert(num); // If the list is empty, insert at the beginning
        return;
    }

    while (temp->next != head) // Traverse until the last node
    {
        temp = temp->next;
    }

    temp->next = last;
    last->prev = temp;
    last->next = head; // Last node's next should point to head to complete the circle
    head->prev = last; // Head node's prev should point to last node
}

// Function to insert at a specific position
void insert_specific_position(int num, int pos)
{
    Node *temp = head;
    for (int i = 0; i < pos - 2; i++) // Traverse to the node before the specified position
    {
        temp = temp->next;
    }

    Node *newnode = new Node();
    newnode->data = num;
    newnode->next = temp->next; 
    temp->next = newnode;
    newnode->prev = temp;

    if (newnode->next != head) // Update the previous pointer of the next node
    {
        newnode->next->prev = newnode;
    }
    else // If inserted at the head position
    {
        head->prev = newnode;
    }
}

// Function to insert in the middle
void insert_middle(int num)
{
    Node *temp = head;
    int count = 0;

    // Count the number of nodes in the list
    do
    {
        temp = temp->next;
        count++;
    } while (temp != head);

    insert_specific_position(num, count / 2); // Insert at the middle position
}

// Function to delete the first node
void deleted()
{
    if (head == NULL) return; // Empty list

    Node *del = head;
    if (head->next == head) // Only one node
    {
        head = NULL;
    }
    else
    {
        head = head->next;
        head->prev = del->prev;
        del->prev->next = head;
    }
    delete del;
}

// Function to delete the last node
void delete_end()
{
    if (head == NULL) return; // Empty list

    Node *temp = head;
    while (temp->next != head) // Traverse to the last node
    {
        temp = temp->next;
    }

    if (temp == head) // Only one node in the list
    {
        head = NULL;
    }
    else
    {
        temp->prev->next = head; // The previous node's next should point to head
        head->prev = temp->prev; // The head node's prev should point to the second last node
    }

    delete temp;
}

// Function to delete a node at a specific position
void delete_specific(int pos)
{
    if (head == NULL) return; // Empty list

    Node *temp = head;
    for (int i = 0; i < pos - 1; i++) // Traverse to the node before the specified position
    {
        temp = temp->next;
    }

    Node *del = temp->next;
    temp->next = del->next;
    if (del->next != head) // Update the prev pointer of the next node
    {
        del->next->prev = temp;
    }
    else // If we are deleting the last node (head is involved)
    {
        head->prev = temp;
    }

    delete del;
}

// Function to delete the middle node
void delete_middle()
{
    Node *temp = head;
    int count = 0;

    // Count the number of nodes in the list
    do
    {
        temp = temp->next;
        count++;
    } while (temp != head);

    delete_specific(count / 2); // Delete at the middle position
}

// Function to display the circular doubly linked list
void display()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    Node *temp = head;
    cout << "List: ";
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head); // Loop back to the head to display the circular nature

    cout << "\nReverse: ";
    temp = head->prev; // Start from the last node
    do
    {
        cout << temp->data << " ";
        temp = temp->prev;
    } while (temp != head->prev); // Loop back to the last node

    cout << endl;
}

// Main function to test the circular doubly linked list
int main()
{
    insert(100);
    insert(200);
    insert(300);
    insert(400);
    insert_end(500);
    insert_middle(1000);
    insert_specific_position(800, 2);
    
    display();

    cout << "\n\nDeleting first node\n";
    deleted();
    display();

    cout << "\n\nDeleting last node\n";
    delete_end();
    display();

    cout << "\n\nDeleting node at position 3\n";
    delete_specific(3);
    display();

    cout << "\n\nDeleting middle node\n";
    delete_middle();
    display();

    return 0;
}
