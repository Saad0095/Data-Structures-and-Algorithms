#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

Node *lca(Node *root, int first, int second)
{
    if (first < root->data && second < root->data)
        return lca(root->left, first, second);
    if (first > root->data && second > root->data)
        return lca(root->right, first, second);
    return root;
}

int main()
{
    Node *root = new Node(6);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(0);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    cout << "Least common ancestor: " << lca(root, 2, 8)->data << endl;
}
