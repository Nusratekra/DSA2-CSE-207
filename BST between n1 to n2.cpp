#include <iostream>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        value = val;
        left = right = nullptr;
    }
};

TreeNode* insertNode(TreeNode* currentNode, int key) {
    if (currentNode == nullptr) {
        return new TreeNode(key);
    }
    if (currentNode->value == key) {
        return currentNode;
    }
    if (key < currentNode->value) {
        currentNode->left = insertNode(currentNode->left, key);
    } else {
        currentNode->right = insertNode(currentNode->right, key);
    }
    return currentNode;
}

void printValuesInRange(TreeNode* root, int lowerBound, int upperBound, int& count) {
    if (root == nullptr) {
        return;
    }
    if (root->value > lowerBound) {
        printValuesInRange(root->left, lowerBound, upperBound, count);
    }
    if (root->value >= lowerBound && root->value <= upperBound) {
        cout << root->value << " ";
        count++;
    }
    if (root->value < upperBound) {
        printValuesInRange(root->right, lowerBound, upperBound, count);
    }
}

int main() {
    TreeNode* root = nullptr;
    int numberOfNodes, value, lowerBound, upperBound;

    cout << "Enter the number of nodes: ";
    cin >> numberOfNodes;

    cout << "\nEnter values to be inserted: \n";
    for (int i = 0; i < numberOfNodes; i++) {
        cin >> value;
        root = insertNode(root, value);
    }

    cout << "Enter the range (lowerBound, upperBound): \n";
    cin >> lowerBound >> upperBound;

    cout << "Nodes within the range [" << lowerBound << ", " << upperBound << "] are: ";

    int count = 0;
    printValuesInRange(root, lowerBound, upperBound, count);

    if (count == 0) {
        cout << "No nodes found in the specified range." << endl;
    } else {
        cout << endl;
    }

    return 0;
}
