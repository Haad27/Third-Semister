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

Node* findMin(Node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
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
    return root;
}

void inorder(Node *root, int& count, int k, int& result) {
    if (!root || count >= k) return;
    
    inorder(root->left, count, k, result);
    count++;
    if (count == k) {
        result = root->data;
        return;
    }
    inorder(root->right, count, k, result);
}

int kthSmallest(Node* root, int k) {
    int count = 0;
    int result = -1;
    inorder(root, count, k, result);
    return result;
}

void inorderRank(Node* root, int value, int& count, int& rank) {
    if (!root) return;
    
    inorderRank(root->left, value, count, rank);
    count++;
    if (root->data == value) {
        rank = count;
        return;
    }
    inorderRank(root->right, value, count, rank);
}

int Rank(Node* root, int value) {
    int count = 0;
    int result = -1;
    inorderRank(root, value, count, result);
    return result;
}

int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

double findMedian(Node* root) {
    int n = countNodes(root);
    if (n % 2 == 1) {
        return kthSmallest(root, (n + 1) / 2);
    } else {
        int mid1 = kthSmallest(root, n / 2);
        int mid2 = kthSmallest(root, n / 2 + 1);
        return (mid1 + mid2) / 2.0;
    }
}

int main() {
    Node *root = NULL;

    // Insert operations
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 12);
    root = insert(root, 16);
    root = insert(root, 25);
    root = insert(root, 11);
    root = insert(root, 13);
    root = insert(root, 17);

    // Perform operations
    cout << "kthSmallest 4 => " << kthSmallest(root, 4) << endl;
    cout << "kthSmallest 7 => " << kthSmallest(root, 7) << endl;
    cout << "rank 16 => " << Rank(root, 16) << endl;
    cout << "rank 10 => " << Rank(root, 10) << endl;
    cout << "findMedian => " << findMedian(root) << endl;

    // Delete 20
    root = deleteNode(root, 20);
    cout << "After deleting 20:" << endl;
    cout << "findMedian => " << findMedian(root) << endl;

    return 0;
}