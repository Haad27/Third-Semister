#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node *next;
};
int main()
{
    Node *head = new Node();
    Node *first = new Node();
    Node *second = new Node();
    Node *third = new Node();
    Node *tail = new Node();

    head->data = 1;
    head->next = first;

    first->data = 2;
    first->next = second;

    second->data = 3;
    second->next = third;

    third->data = 4;
    third->next = tail;

    tail->data = 5;
    tail->next = nullptr;

    int number;
    cout << "enter the data tou need to find \n";
    cin >> number;

    int count = 1;
    while (head != nullptr)
    {
        if (head->data == number)
        {
            cout << "found at " << head << "at the number== " << count;
            ;
            break;
        }

        head = head->next;
        count++;
    }

    return 0;
}
