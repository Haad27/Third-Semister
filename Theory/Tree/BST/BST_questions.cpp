#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};
Node *insert(Node *root, int value)
{
    if (root == NULL)
    {
        return new Node(value);
    }
    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    return root;
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

Node *findMax(Node *root)
{
    while (root && root->right)
        root = root->right;
    return root;
}

Node *findMin(Node *root)
{
    while (root && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {

        if (root->left == NULL && root->right == NULL)
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

        Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

Node *searchNode(Node *root, int key)
{
    if (!root)
        return nullptr;

    if (root->data == key)
        return root;

    if (key < root->data)
        return searchNode(root->left, key);
    else
        return searchNode(root->right, key);
}
void minmax(Node *root)
{
    if (!root)
    {
        return;
    }
    Node *temp = root;
    while (root->left != NULL)
    {
        root->left;
    }
    int min = root->data;
    while (temp->right != NULL)
    {
        root->right;
    }
    int max = root->data;
}
bool isBST(Node *root, int minVal, int maxVal)
{
    if (!root)
    {
         return true;
    }
    if (root->data<=minVal||root->data>=maxVal)
    {
        return false;
    }

    return isBST(root->left,minVal,maxVal) && isBST(root->right,minVal,maxVal);
    
    
}

Node *inorderSuccessor(Node *root, Node *target)
{
   Node* succ = NULL;
   while (root)
   {
    if (target->data < root->data)
    {
        succ=root;
        root=root->left;
    }
    else if(target->data > root->data){
     root=root->right;
    }
    //this excude when all the above conditions fail
    else{

        if (root->right)
        {
            succ=findMin(root->right);
        }
        break;
    }
    
   }
   return succ;
}

Node *inorderPredecessor(Node *root, Node *target)
{
    Node *pred = NULL;

    while (root)
    {
        if (target->data > root->data)
        {
            pred = root; // possible predecessor
            root = root->right;
        }
        else if (target->data < root->data)
        {
            root = root->left;
        }
        else
        {
            // Node found
            if (root->left)
            {
                pred = findMax(root->left);
            }
            break;
        }
    }

    return pred;
}
int sumNodes(Node* root) {
    if (!root) return 0;
    return root->data + sumNodes(root->left) + sumNodes(root->right);
}
int countLeaves(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int height(Node *root)
{
    if (!root)
        return 0; // empty node has height 0
    return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(Node *root)
{
    if (!root)
        return true;

    int lh = height(root->left);
    int rh = height(root->right);

    if ((lh - rh) > 1)
        return false;

    return isBalanced(root->left) && isBalanced(root->right);
}
#include <queue>
// BFS using BST
void levelOrder(Node *root)
{
    if (!root)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        cout << node->data << " ";

        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }
}
// for the number of notes
int countNodes(Node *root)
{
    if (!root)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int leftSubtreeCount(Node *root)
{
    if (!root || !root->left)
        return 0;
    return countNodes(root->left);
}

int rightSubtreeCount(Node *root)
{
    if (!root || !root->right)
        return 0;
    return countNodes(root->right);
}


int main()
{
    Node *root = NULL;

    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);

    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    reverseInorder(root);
}
