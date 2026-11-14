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

int height(Node *root, int &diameter)
{
    if (root == NULL)
        return 0;

    int left = height(root->left, diameter);
    int right = height(root->right, diameter);
    diameter = max(diameter, left + right);

    return max(left, right) + 1;
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(7);

    int diameter = 0;
    height(root, diameter);
    cout << "Diameter in edges: " << diameter << endl;
}
