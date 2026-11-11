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

bool mirror(Node *left, Node *right)
{
    if (left == NULL || right == NULL)
        return left == right;

    return left->data == right->data &&
           mirror(left->left, right->right) &&
           mirror(left->right, right->left);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    cout << (mirror(root->left, root->right)
                 ? "The tree is symmetric."
                 : "The tree is not symmetric.")
         << endl;
}
