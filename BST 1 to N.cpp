#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value)
{
    struct Node* newNode = new Node();
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

vector<struct Node*> generateBSTs(int start, int end)
{
    vector<struct Node*> trees;

    if(start > end)
    {
        trees.push_back(NULL);
        return trees;
    }
    for(int rootValue = start; rootValue <= end; rootValue++)
    {
        vector<struct Node*> leftSubtrees = generateBSTs(start, rootValue - 1);

        vector<struct Node*> rightSubtrees = generateBSTs(rootValue + 1, end);

        for(int leftIndex = 0; leftIndex < leftSubtrees.size(); leftIndex++)
        {
            struct Node* leftSubtree = leftSubtrees[leftIndex];
            for(int rightIndex = 0; rightIndex < rightSubtrees.size(); rightIndex++)
            {
                struct Node* rightSubtree = rightSubtrees[rightIndex];

                struct Node* rootNode = createNode(rootValue);

                rootNode->left = leftSubtree;
                rootNode->right = rightSubtree;
                trees.push_back(rootNode);
            }
        }
    }
    return trees;
}

void preorderTraversal(struct Node* node) {
    if (node == NULL)
    {
        return;
    }

    cout << node->value << " ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

int main()
{
    int limit;
    cout << "Enter the last limit (n): ";
    cin >> limit;

    vector<struct Node*> allTrees = generateBSTs(1, limit);

    for(int i = 0; i < allTrees.size(); i++)
    {
        cout << "BST " << i + 1 << ": ";
        preorderTraversal(allTrees[i]);
        cout << endl;
    }

    return 0;
}
