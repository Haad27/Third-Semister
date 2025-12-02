#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

Node* insert(Node* root, int value) {
    if (root == NULL) return new Node(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

void fillInorder(Node* root, int arr[], int &idx) {
    if (!root) return;
    fillInorder(root->left, arr, idx);
    arr[idx++] = root->data;
    fillInorder(root->right, arr, idx);
}

int kthSmallest(Node* root, int k) {
    int arr[100], idx = 0;
    fillInorder(root, arr, idx);
    if (k > idx) return -1;
    return arr[k - 1];
}

int rankOf(Node* root, int key) {
    int arr[100], idx = 0, rank = 0;
    fillInorder(root, arr, idx);
    for (int i = 0; i < idx; i++)
        if (arr[i] < key) rank++;
    return rank;
}

double findMedian(Node* root) {
    int arr[100], idx = 0;
    fillInorder(root, arr, idx);
    if (idx % 2 == 1) return arr[idx / 2];
    return (arr[idx/2] + arr[idx/2 - 1]) / 2.0;
}


Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left && !root->right) {
            delete root; return NULL;
        }
        if (!root->left) {
            Node* t = root->right;
            delete root; return t;
        }
        if (!root->right) {
            Node* t = root->left;
            delete root; return t;
        }
        Node* t = findMin(root->right);
        root->data = t->data;
        root->right = deleteNode(root->right, t->data);
    }
    return root;
}

int main() {

    Node* root = NULL;
    int values[] = {15,10,20,8,12,16,25,11,13,17};

    for (int x : values) root = insert(root, x);

    cout << "kthSmallest 4 => " << kthSmallest(root, 4) << "\n";
    cout << "kthSmallest 7 => " << kthSmallest(root, 7) << "\n";

    cout << "rank 16 => " << rankOf(root, 16) << "\n";
    cout << "rank 10 => " << rankOf(root, 10) << "\n";

    cout << "findMedian => " << findMedian(root) << "\n";

    root = deleteNode(root, 20);

    cout << "After deleting 20:\n";
    cout << "findMedian => " << findMedian(root) << "\n";

    return 0;
}
