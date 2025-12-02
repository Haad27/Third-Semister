#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void detectAndRemoveLoop() {
    Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            cout << "Cycle detected!\n";

            Node* ptr1 = head;
            Node* ptr2 = slow;

            int pos = 1;
            while (ptr1 != ptr2) {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
                pos++;
            }

            cout << "Loop starts at node with value: " << ptr1->data << endl;
            cout << "Position in list: " << pos << endl;

            Node* temp = ptr1;
            while (temp->next != ptr1) {
                temp = temp->next;
            }

            temp->next = NULL;  
   
            int from = 0;
            Node* tempFrom = head;
            while (tempFrom != temp) {
                tempFrom = tempFrom->next;
                from++;
            }
            from++; 

            cout << "loop removed from Node #" << from << " > Node #" << pos << "\n";
            return;
        }
    }

    cout << "No cycle detected.\n";
}

int main() {
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

    // Creating cycle
    n5->next = n3;

    detectAndRemoveLoop();

    return 0;
}
