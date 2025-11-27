#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

void check()
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            cout << "Cycle detected!\n";

            Node *ptr1 = head;
            Node *ptr2 = slow;
            int count1 = 1;
            while (ptr1 != ptr2)
            {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
                count1++;
            }
            cout << "Cycle starts at node with value: " << ptr1->data << endl;
            cout << "the Node number is:  " << count1 << endl;

            Node* loop_start = ptr1; 
            Node* temp = head;
            int count2 = 1;
            while (temp->next != loop_start)
            {
                temp = temp->next;
                count2++;
            }
            temp->next = NULL; 

            cout << "Loop removed from node : " << count2 << " to Node " << count1 << endl;

            return;
        }
    }
}

int main()
{

    // Example list to test
    Node *n1 = new Node{11, NULL};
    Node *n2 = new Node{3, NULL};
    Node *n3 = new Node{8, NULL};
    Node *n4 = new Node{2, NULL};
    Node *n5 = new Node{1, NULL};

    head = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    // point of cycle
    n5->next = n3;

    check();

    return 0;
}