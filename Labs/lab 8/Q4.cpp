#include <iostream>
#include <vector>
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

Node *build(vector<int> preorder, vector<int> inorder,
            int start, int end, int &index)
{
    if (start > end)
        return NULL;

    Node *root = new Node(preorder[index++]);
    int position = start;

    while (inorder[position] != root->data)
        position++;

    root->left = build(preorder, inorder, start, position - 1, index);
    root->right = build(preorder, inorder, position + 1, end, index);
    return root;
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
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    int index = 0;

    Node *root = build(preorder, inorder, 0, inorder.size() - 1, index);

    cout << "Post-order traversal: ";
    postorder(root);
    cout << endl;
}
