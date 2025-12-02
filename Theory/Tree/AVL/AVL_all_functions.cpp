#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;

    Node(int value)
    {
        data = value;
        left = right = NULL;
        height = 1;
    }
};

int getHeight(Node *n)
{
    if (!n)
        return 0;
    return n->height;
}

int getBalance(Node *n)
{
    if (!n)
        return 0;
    return getHeight(n->left) - getHeight(n->right);
}
//y is at top and it has to ome to the middle
//x has to come to the top
//t2 is bottim which will remian at the bottom
//y-x-t2 and after rotation we will get x-y-t2 as tree not linear
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right; //null if it is both on left bec that will be single roation ll or rr requires two rotations

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node *insert(Node *root, int value)
{
    if (root == NULL)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        return root; // No duplicates

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));//one bec leaf intially as heiaght 0

    int balance = getBalance(root);

    // Left Left
    if (balance > 1 && value < root->left->data)
        return rightRotate(root);

    // Right Right
    if (balance < -1 && value > root->right->data)
        return leftRotate(root);

    // Left Right
    if (balance > 1 && value > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left
    if (balance < -1 && value < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node *findMin(Node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    else {

        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }


    if (!root)
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);

    // Left Left
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node *searchNode(Node *root, int key)
{
    if (!root)
        return NULL;

    if (root->data == key)
        return root;

    if (key < root->data)
        return searchNode(root->left, key);
    else
        return searchNode(root->right, key);
}

void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void reverseInorder(Node *root)
{
    if (!root)
        return;
    reverseInorder(root->right);
    cout << root->data << " ";
    reverseInorder(root->left);
}

int main()
{
    Node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    inorder(root);
    cout << endl;

    preorder(root);
    cout << endl;

    postorder(root);
    cout << endl;

    reverseInorder(root);
    cout << endl;

    root = deleteNode(root, 30);

    inorder(root);
    cout << endl;
}
