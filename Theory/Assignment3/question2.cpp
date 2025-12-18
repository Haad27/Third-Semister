#include <iostream>
#include <string>
using namespace std;

struct Incident
{
    int incident_id;
    string desc;
    Incident* next;

    Incident(int id, string d)
    {
        incident_id = id;
        desc = d;
        next = NULL;
    }
};

struct Node
{
    int data;
    Node* left;
    Node* right;
    int height;
    Incident* incident_head;

    Node(int value)
    {
        data = value;
        left = right = NULL;
        height = 1;
        incident_head = NULL;
    }
};

int getHeight(Node* n)
{
    if (!n)
        return 0;
    return n->height;
}

int getBalance(Node* n)
{
    if (!n)
        return 0;
    return getHeight(n->left) - getHeight(n->right);
}

Node* rightRotate(Node* y)
{
    Node* x = y->left;
    Node* t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x)
{
    Node* y = x->right;
    Node* t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node* insert(Node* root, int value)
{
    if (root == NULL)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    if (balance > 1 && value < root->left->data)
        return rightRotate(root);

    if (balance < -1 && value > root->right->data)
        return leftRotate(root);

    if (balance > 1 && value > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && value < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node* minValueNode(Node* node)
{
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        if ((root->left == NULL) || (root->right == NULL))
        {
            Node* temp = root->left ? root->left : root->right;

            Incident* curr = root->incident_head;
            while (curr != NULL)
            {
                Incident* tempIncident = curr;
                curr = curr->next;
                delete tempIncident;
            }

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
            {
                *root = *temp;
            }
            delete temp;
        }
        else
        {
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            
            Incident* tempIncidents = root->incident_head;
            root->incident_head = temp->incident_head;
            temp->incident_head = tempIncidents;
            
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node* searchNode(Node* root, int key)
{
    if (!root || root->data == key)
        return root;

    if (key < root->data)
        return searchNode(root->left, key);

    return searchNode(root->right, key);
}

void addIncident(Node* loc, int id, string d)
{
    Incident* n = new Incident(id, d);
    n->next = loc->incident_head;
    loc->incident_head = n;
    cout << "Incident added successfully to Location " << loc->data << endl;
}

void deleteIncident(Node* loc, int id)
{
    if (!loc)
    {
        cout << "Location not found!" << endl;
        return;
    }

    Incident* cur = loc->incident_head;
    Incident* prev = NULL;

    while (cur && cur->incident_id != id)
    {
        prev = cur;
        cur = cur->next;
    }

    if (!cur)
    {
        cout << "Incident not found!" << endl;
        return;
    }

    if (!prev)
        loc->incident_head = cur->next;
    else
        prev->next = cur->next;

    delete cur;
    cout << "Incident deleted successfully!" << endl;
}

void displayIncidents(Incident* head)
{
    if (!head)
    {
        cout << "   No incidents recorded." << endl;
        return;
    }

    while (head)
    {
        cout << "   Incident ID: " << head->incident_id << " | " << head->desc << endl;
        head = head->next;
    }
}

void inorder(Node* root)
{
    if (!root)
        return;

    inorder(root->left);
    cout << "Location ID: " << root->data << endl;
    displayIncidents(root->incident_head);
    cout << endl;
    inorder(root->right);
}

void displayMenu()
{
    cout << "\n=== Emergency Response Management System ===" << endl;
    cout << "1. Add a new location" << endl;
    cout << "2. Remove a location" << endl;
    cout << "3. Add a new incident to a location" << endl;
    cout << "4. Delete an incident from a location" << endl;
    cout << "5. Display all locations and incidents" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice (1-6): ";
}

int main()
{
    Node* root = NULL;
    int choice, locId, incidentId;
    string description;

    while (true)
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter location ID to add: ";
                cin >> locId;
                if (searchNode(root, locId))
                {
                    cout << "Location ID already exists!" << endl;
                }
                else
                {
                    root = insert(root, locId);
                    cout << "Location " << locId << " added successfully!" << endl;
                }
                break;

            case 2:
                cout << "Enter location ID to remove: ";
                cin >> locId;
                if (searchNode(root, locId))
                {
                    root = deleteNode(root, locId);
                    cout << "Location " << locId << " and all its incidents removed successfully!" << endl;
                }
                else
                {
                    cout << "Location not found!" << endl;
                }
                break;

            case 3:
                cout << "Enter location ID: ";
                cin >> locId;
                Node* loc = searchNode(root, locId);
                if (loc)
                {
                    cout << "Enter incident ID: ";
                    cin >> incidentId;
                    cin.ignore();
                    cout << "Enter incident description: ";
                    getline(cin, description);
                    addIncident(loc, incidentId, description);
                }
                else
                {
                    cout << "Location not found!" << endl;
                }
                break;

            case 4:
                cout << "Enter location ID: ";
                cin >> locId;
                loc = searchNode(root, locId);
                if (loc)
                {
                    cout << "Enter incident ID to delete: ";
                    cin >> incidentId;
                    deleteIncident(loc, incidentId);
                }
                else
                {
                    cout << "Location not found!" << endl;
                }
                break;

            case 5:
                if (!root)
                {
                    cout << "No locations in the system!" << endl;
                }
                else
                {
                    cout << "\n=== All Locations and Incidents ===" << endl;
                    inorder(root);
                }
                break;

            case 6:
                cout << "Exiting system. Goodbye!" << endl;
                
                // Clean up all memory
                while (root != NULL)
                {
                    root = deleteNode(root, root->data);
                }
                return 0;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}