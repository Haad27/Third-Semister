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
    if (!root) return new Node(value);
    if (value < root->data) root->left = insert(root->left, value);
    else if (value > root->data) root->right = insert(root->right, value);
    return root;
}

void fillInorder(Node* root, int arr[], int &idx) {
    if (!root) return;
    fillInorder(root->left, arr, idx);
    arr[idx++] = root->data;
    fillInorder(root->right, arr, idx);
}

Node* buildBalancedBST(int arr[], int start, int end) {
    if (start > end) return NULL;
    int mid = (start + end) / 2;

    Node* root = new Node(arr[mid]);
    root->left = buildBalancedBST(arr, start, mid - 1);
    root->right = buildBalancedBST(arr, mid + 1, end);
    return root;
}

Node* balanceTree(Node* root) {
    int arr[100], idx = 0;
    fillInorder(root, arr, idx);
    return buildBalancedBST(arr, 0, idx - 1);
}

int height(Node* root) {
    if (!root) return 0;
    int hl = height(root->left);
    int hr = height(root->right);
    return 1 + (hl > hr ? hl : hr);
}

Node* predecessor(Node* root, int key) {
    Node* pred = NULL;
    while (root) {
        if (key > root->data) {
            pred = root;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return pred;
}

Node* successor(Node* root, int key) {
    Node* succ = NULL;
    while (root) {
        if (key < root->data) {
            succ = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return succ;
}

bool isBSTUtil(Node* root, int minV, int maxV) {
    if (!root) return true;
    if (root->data <= minV || root->data >= maxV) return false;
    return isBSTUtil(root->left, minV, root->data) &&
           isBSTUtil(root->right, root->data, maxV);
}

bool isBST(Node* root) {
    return isBSTUtil(root, -1000000, 1000000);
}

int main() {

    Node* root = NULL;
    for (int i = 1; i <= 10; i++)
        root = insert(root, i);

    cout << "heightBefore => " << height(root) << endl;

    root = balanceTree(root);

    cout << "heightAfter => " << height(root) << endl;

    cout << "predecessor 6 => " << predecessor(root, 6)->data << endl;
    cout << "successor 6 => " << successor(root, 6)->data << endl;

    cout << "isBST => " << (isBST(root) ? "true" : "false") << endl;

    return 0;
}
