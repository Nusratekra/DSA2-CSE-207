#include <iostream>
using namespace std;

struct node {
    int key;
    struct node* left;
    struct node* right;
};

struct node* newNode(int element) {
    struct node* temp = new node();
    temp->key = element;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* findMin(struct node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct node* search(struct node* root, int key, int& index, string path = "", int currentIndex = 0) {
    if (root == NULL) {
        return NULL;
    }

    if (root->key == key) {
        index = currentIndex;
        cout << "Found at index: " << index << " (Path: " << path << ")" << endl;
        return root;
    }


    struct node* leftResult = search(root->left, key, index, path + "left -> ", currentIndex + 1);
    if (leftResult != NULL) {
        return leftResult;
    }


    return search(root->right, key, index, path + "right -> ", currentIndex + 1);
}

struct node* insertNode(struct node* Node, int a) {
    if (Node == NULL) {
        return newNode(a);
    }
    if (a < Node->key) {
        Node->left = insertNode(Node->left, a);
    } else if (a > Node->key) {
        Node->right = insertNode(Node->right, a);
    }
    return Node;
}


void preOrder(struct node* root) {
    if (root != NULL) {
        cout << " " << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

struct node* deleteNode(struct node* root, int t) {
    if (root == NULL) {
        cout << "Value " << t << " is not found for deletion.\n";
        return NULL;
    }

    if (t < root->key) {
        root->left = deleteNode(root->left, t);
    } else if (t > root->key) {
        root->right = deleteNode(root->right, t);
    } else {

        if (root->left == NULL) {
            struct node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            delete root;
            return temp;
        }


        struct node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void displayMenu() {
    cout << "Menu:\n";
    cout << "1. Insert a node\n";
    cout << "2. Search for a node\n";
    cout << "3. Delete a node\n";
    cout << "4. Display tree (pre-order)\n";
    cout << "5. Exit\n";
}

int main() {
    struct node* root = NULL;
    int choice, value, index;

    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                root = insertNode(root, value);
                cout << "Value inserted.\n";
                break;

            case 2:
                cout << "Enter the value to search for: ";
                cin >> value;
                index = -1;
                if (search(root, value, index) != NULL) {
                    // Output handled in search function
                } else {
                    cout << "Not Found\n";
                }
                break;

            case 3:
                cout << "Enter the value to delete: ";
                cin >> value;
                root = deleteNode(root, value);
                break;

            case 4:
                cout << "Binary tree in pre-order:\n";
                preOrder(root);
                cout << endl;
                break;

            case 5:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}
