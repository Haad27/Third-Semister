#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

Node* BuildTree()
{
    int value;
    cin >> value;

    if (value == -1)
    {
        return NULL;
    }

    Node* root = new Node(value);

    root->left = BuildTree();   // build left subtree
    root->right = BuildTree();  // build right subtree

    return root;
}
void PrintKLevel(Node* root, int k) {
    if (!root) return;
    if (k == 1) {
        cout << root->data << " ";
        return;
    }
    PrintKLevel(root->left, k-1);
    PrintKLevel(root->right, k-1);
}

void PrintTree(Node *root)
{
    if (!root) return;

    PrintTree(root->left);
    cout << root->data << " ";
    PrintTree(root->right);
}
int CountNodes(Node* root) {
    if (!root) return 0;
    return 1 + CountNodes(root->left) + CountNodes(root->right);
}
int CountLeafNodes(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return CountLeafNodes(root->left) + CountLeafNodes(root->right);
}
int CountNonLeaf(Node* root) {
    if (!root || (!root->left && !root->right)) return 0;
    return 1 + CountNonLeaf(root->left) + CountNonLeaf(root->right);
}
bool Search(Node* root, int key) {
    if (!root) return false;
    if (root->data == key) return true;
    return Search(root->left, key) || Search(root->right, key);
}
int Sum(Node* root) {
    if (!root) return 0;
    return root->data + Sum(root->left) + Sum(root->right);
}

int main()
{
    cout << "Enter tree values (-1 for NULL):\n";

    // Example input:
    // 2 4 3 -1 -1 5 -1 -1 7 8 -1 -1 9 -1 -1

    Node* root = BuildTree();

    cout << "\nInorder Traversal: ";
    PrintTree(root);

    return 0;
}
