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

static int idx = -1;
Node *buildTree(vector<int> arr)
{
    idx++;
    if (arr[idx] == -1)
        return NULL;
    Node *root = new Node(arr[idx]);
    root->left = buildTree(arr);
    root->right = buildTree(arr);
    return root;
}

int height(Node *root) {
    if (root == NULL) return 0;
    int left = height(root->left);
    int right = height(root->right);
    return max(left, right) + 1;
};
int count(Node *root) {
    if (root == NULL) return 0;
    int left = count(root->left);
    int right = count(root->right);
    return left + right + 1;
};
int sumOfNodes(Node *root) {
    if (root == NULL) return 0;
    int left = sumOfNodes(root->left);
    int right = sumOfNodes(root->right);
    return left + right + root->data;
};

int main()
{
    vector<int> arr = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(arr);

    cout << "Height of root: " << height(root) << endl;
    cout << "Count of nodes: " << count(root) << endl;
    cout << "Sum of nodes: " << sumOfNodes(root) << endl;
    return 0;
}