#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int value)
    {
        left = right = NULL;
        data = value;
    }
};
Node* buildtree()
{
    int val;
    cin >> val;
    if (val == -1)
    {
        return NULL;
    }
    Node *root = new Node(val);

    root->left=buildtree();
    root->right=buildtree();

    return;
}
void PrintTree(Node * root){
    if (root==NULL)
    {
       return;
    }
    PrintTree(root->left);
    cout << root->data;
    PrintTree(root->right);
}
int CountLeafNodes(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return CountLeafNodes(root->left) + CountLeafNodes(root->right);
}
class Solution {
public:
    int height(TreeNode* root) {
        if (!root) return 0;            // empty node has height 0
        return 1 + max(height(root->left), height(root->right));
    }

    bool isBalanced(TreeNode* root) {
        if (!root) return true;         // empty tree is balanced

        int lh = height(root->left);    // height of left subtree
        int rh = height(root->right);   // height of right subtree

        if ((lh - rh) > 1) return false;  // difference >1 → unbalanced

        return isBalanced(root->left) && isBalanced(root->right);
    }
};

int main()
{
    cout << "ënter the values";

    Node *root = buildtree();
    cout << "\nInorder Traversal: ";
    PrintTree(root);

    return 0;
}
