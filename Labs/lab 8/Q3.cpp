#include <iostream>
#include <algorithm>
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

int height(Node *root)
{
    if (root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    if (left == -1 || right == -1 || abs(left - right) > 1)
        return -1;

    return max(left, right) + 1;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << (height(root) != -1
                 ? "The tree is height-balanced."
                 : "The tree is not height-balanced.")
         << endl;
}
