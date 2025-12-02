#include <iostream>
#include <string>
using namespace std;

struct Person {
    string name;
    string address;
    string phone;
};

struct Node {
    Person data;
    Node* next;
    Node* prev;
};

Node* head = NULL;

void insertPerson(string name, string address, string phone) {
    Node* newnode = new Node;
    newnode->data.name = name;
    newnode->data.address = address;
    newnode->data.phone = phone;
    newnode->next = NULL;
    
    // If list is empty
    if (head == NULL) {
        newnode->prev = NULL;
        head = newnode;
        return;
    }
    
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newnode;
    newnode->prev = temp;
}

Node* findPerson(string name) {
    Node* temp = head;
    
    while (temp != NULL) {
        if (temp->data.name == name) {
            return temp;
        }
        temp = temp->next;
    }
    
    return NULL;
}

void displayAll() {
    if (head == NULL) {
        cout << "Address book is empty!" << endl;
        return;
    }
    
    Node* temp = head;
    int count = 1;
    
    cout << "\n=== ADDRESS BOOK ===" << endl;
    while (temp != NULL) {
        cout << "Record #" << count << ":" << endl;
        cout << "Name: " << temp->data.name << endl;
        cout << "Address: " << temp->data.address << endl;
        cout << "Phone: " << temp->data.phone << endl;
        cout << "-------------------" << endl;
        temp = temp->next;
        count++;
    }
}

void sortBruteForce() {
    if (head == NULL || head->next == NULL) return;
    
    Node* temp1 = head;
    
    while (temp1 != NULL) {
        Node* temp2 = temp1->next;
        
        while (temp2 != NULL) {
            if (temp1->data.name > temp2->data.name) {
                Person tempData = temp1->data;
                temp1->data = temp2->data;
                temp2->data = tempData;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
}

void deletePerson(string name) {
    Node* temp = head;
    
    while (temp != NULL) {
        if (temp->data.name == name) {
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            } else {
                head = temp->next;
            }
            
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            
            delete temp;
            cout << "Person deleted successfully!" << endl;
            return;
        }
        temp = temp->next;
    }
    
    cout << "Person not found!" << endl;
}

int main() {
    int choice;
    
    do {
        cout << "\n=== ADDRESS BOOK MENU ===" << endl;
        cout << "1. Add Person" << endl;
        cout << "2. Find Person" << endl;
        cout << "3. Display All" << endl;
        cout << "4. Sort" << endl;
        cout << "5. Delete Person" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1: {
                string name, address, phone;
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter address: ";
                getline(cin, address);
                cout << "Enter phone: ";
                getline(cin, phone);
                
                insertPerson(name, address, phone);
                cout << "Person added successfully!" << endl;
                break;
            }
            
            case 2: {
                string name;
                cout << "Enter name to find: ";
                getline(cin, name);
                
                Node* found = findPerson(name);
                if (found != NULL) {
                    cout << "\nPerson Found:" << endl;
                    cout << "Name: " << found->data.name << endl;
                    cout << "Address: " << found->data.address << endl;
                    cout << "Phone: " << found->data.phone << endl;
                } else {
                    cout << "Person not found!" << endl;
                }
                break;
            }
            
            case 3: {
                displayAll();
                break;
            }
            
            case 4: {
                sortBruteForce();
                cout << "Address book sorted successfully!" << endl;
                break;
            }
            
            case 5: {
                string name;
                cout << "Enter name to delete: ";
                getline(cin, name);
                deletePerson(name);
                break;
            }
            
            case 6: {
                cout << "Exiting program..." << endl;
                break;
            }
            
            default: {
                cout << "Invalid choice! Please try again." << endl;
                break;
            }
        }
    } while (choice != 6);
    
    return 0;
}