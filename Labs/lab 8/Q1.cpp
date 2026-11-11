#include <iostream>
#include <vector>
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

int treeIndex = -1;

Node *buildTree(vector<int> values)
{
    treeIndex++;

    if (values[treeIndex] == -1)
        return NULL;

    Node *root = new Node(values[treeIndex]);
    root->left = buildTree(values);
    root->right = buildTree(values);
    return root;
}

bool search(Node *root, int value)
{
    if (root == NULL)
        return false;

    if (root->data == value)
        return true;

    return search(root->left, value) || search(root->right, value);
}

void preorder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    int num;
    vector<int> values = {1, 2, 4, -1, -1, 5, -1, -1,
                          3, 6, -1, -1, 7, -1, -1};
    Node *root = buildTree(values);

    cout << "Preorder traversal: ";
    preorder(root);

    cout << "\nPostorder traversal: ";
    postorder(root);
    
    cout << "\nEnter number to search: ";
    cin >> num;
    cout << "\nSearch " << num << ": "
         << (search(root, num) ? "Found" : "Not found") << endl;

    return 0;
}
