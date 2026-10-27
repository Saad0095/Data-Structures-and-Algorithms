#include <bits/stdc++.h>
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

// Build Tree PreOrder
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

void kthLevel(Node *root, int k)
{
    if(root == NULL) return;
    if(k == 1) {
        cout << root->data << endl;
        return;
    };
    kthLevel(root->left, k-1);
    kthLevel(root->right, k-1);
}
int main()
{
    vector<int> arr = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(arr);

    kthLevel(root, 3);
    kthLevel(root, 4);
    return 0;
}