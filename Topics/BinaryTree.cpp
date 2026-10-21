#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val = 0) : data(val)
    {
        left = right = NULL;
    };
};

static int idx = -1;
Node *buildTree(vector<int> preOrder)
{
    idx++;
    if (preOrder[idx] == -1)
        return NULL;

    Node *root = new Node(preOrder[idx]);
    root->left = buildTree(preOrder);
    root->right = buildTree(preOrder);
    return root;
};

int main()
{
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(preOrder);
    cout << root->data << "\n";
    cout << root->left->data << "\n";
    cout << root->right->data << "\n";
    return 0;
}