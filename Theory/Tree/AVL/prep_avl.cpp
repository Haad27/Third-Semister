#include <iostream>
#include <string>
#include <vector>

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
int getHieght(Node *root)
{
    if (!root)
    {
        return 0;
    }
    return root->height;
}
int getbalance(Node *root)
{
    if (!root)
    {
        return 0;
    }
    return getHieght(root->left) - getHieght(root->right);
}
Node *rightrotate(Node *y)
{
    Node *x = y->left;
    Node *td = x->right;

    x->right = y;
    y->left = td;

    y->height = 1 + max(getHieght(y->left), getHieght(y->right));
    x->height = 1 + max(getHieght(x->left), getHieght(x->right));

    return x;
}
Node *leftrotate(Node *x)
{
    Node *y = x->right;
    Node *td = y->left;

    y->left = x;
    x->right = td;

    x->height = 1 + max(getHieght(x->left), getHieght(x->right));
    y->height = 1 + max(getHieght(y->left), getHieght(y->right));

    return y;
}
Node *insert(Node *root, int value)
{

    if (!root)
    {
        return new Node(value);
    }
    if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    else if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else
        return root;

    root->height = 1 + max(getHieght(root->left), getHieght(root->right));
    int balance = getbalance(root);
    // LL
    if (balance > 1 && root->left->data > value)
    {
        return rightrotate(root);
    }
    // RR
    if (balance < -1 && root->right->data < value)
    {
        return leftrotate(root);
    }
    // lr
    if (balance > 1 && root->left->data < value)
    {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }
    if (balance < -1 && root->right->data > value)
    {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }
    return root;
}

Node *findMin(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
Node *delete_node(Node *root, int value)
{
    if (!root)
        return NULL;
    if (value < root->data)
    {
        root->left = delete_node(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = delete_node(root->right, value);
    }
    // case 0
    else
    {
        if (root->right == NULL && root->left == NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // if two child
        Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }
    return root;

    root->height = 1 + max(getHieght(root->left), getHieght(root->right));
    int balance = getbalance(root);

    // ll
    if (balance > 1 && getbalance(root->left) >= 0)
    {
        return rightrotate(root);
    }
    if (balance < -1 && getbalance(root->right) <= 0)
    {
        return leftrotate(root);
    }
    if (balance > 1 && getbalance(root->left) < 0)
    {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }
    if (balance < -1 && getbalance(root->right) > 0)
    {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }

    return root;
}
void inorder(Node *root)
{
    if (!root)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void printHeightBalance(Node *root)
{
    if (!root)
        return;

    printHeightBalance(root->left);

    cout << "Node " << root->data
         << ": Height = " << root->height
         << ", Balance = " << getbalance(root) << endl;

    printHeightBalance(root->right);
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
int sumNodes(Node *root)
{
    if (!root)
        return 0;

    return root->data + sumNodes(root->left) + sumNodes(root->right);
}

void printLeaves(Node *root)
{
    if (!root)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        cout << root->data;
    }
    printLeaves(root->left);
    printLeaves(root->right);
}

int countNodes(Node *root)
{
    if (!root)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countLeaves(Node *root)
{
    if (!root)
        return 0;
   if ( root->left==NULL && root->right==NULL)
   {
    return 1;
   }
   return countLeaves(root->left)+countLeaves(root->right);
}
int countInternalNodes(Node *root)
{
   
    if(!root)return 0;
    if(!root || root->left==NULL && root->right==NULL) return 0;

    return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
}

void printLevel(Node *root, int level)
{
    if (!root)
        return;
    if (level==1)
    {
        cout << root->data;
    }
    printLevel(root->left,level-1);
    printLevel(root->right,level-1);
    
}

int findMax(Node *root)
{
    while (root->right)
        root = root->right;
    return root->data;
}
int findMinValue(Node *root)
{
    while (root->left)
        root = root->left;
    return root->data;
}

int main()
{
    Node *root = NULL;
    root = insert(root, 34);
    root = insert(root, 44);
    root = insert(root, 54);
    root = insert(root, 24);
    root = insert(root, 14);
    root = insert(root, 4);

    inorder(root);
    cout << "\n";
    root = delete_node(root, 44);
    inorder(root);

    cout << "\n\nHeight and Balance of all nodes:\n";
    printHeightBalance(root);
    return 0;
}
