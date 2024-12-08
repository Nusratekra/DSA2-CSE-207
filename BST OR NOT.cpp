#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

int maxValue(Node* node) {
    if (node == NULL)
        return INT_MIN;
    return max({node->data, maxValue(node->left), maxValue(node->right)});
}

int minValue(Node* node) {
    if (node == NULL)
        return INT_MAX;
    return min({node->data, minValue(node->left), minValue(node->right)});
}

bool isBST(Node* node) {
    if (node == NULL)
        return true;

    if (node->left != NULL && maxValue(node->left) >= node->data)
        return false;

    if (node->right != NULL && minValue(node->right) <= node->data)
        return false;

    return isBST(node->left) && isBST(node->right);
}

int main() {
    Node* root = NULL;
    int n1, n2, n3, n4, n5, n6, n7;

    cout << "Enter the value of root node: ";
    cin >> n1;
    root = new Node(n1);

    cout << "Enter the value of " << n1 << " left node: ";
    cin >> n2;
    root->left = new Node(n2);

    cout << "Enter the value of " << n1 << " right node: ";
    cin >> n3;
    root->right = new Node(n3);

    cout << "Enter the value of " << n2 << " left node: ";
    cin >> n4;
    root->left->left = new Node(n4);

    cout << "Enter the value of " << n2 << " right node: ";
    cin >> n5;
    root->left->right = new Node(n5);

    cout << "Enter the value of " << n3 << " left node: ";
    cin >> n6;
    root->right->left = new Node(n6);

    cout << "Enter the value of " << n3 << " right node: ";
    cin >> n7;
    root->right->right = new Node(n7);

    if (isBST(root)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}
