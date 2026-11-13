#include <iostream>
#include <stack>
using namespace std;

class Node
{
    public:
    int data;
    Node *left, *right;

    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

Node *insert(Node *root, int value)
{
    if (root == NULL)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void preorder(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> s;
    s.push(root);

    while (!s.empty())
    {
        Node *current = s.top();
        s.pop();
        cout << current->data << " ";

        if (current->right != NULL)
            s.push(current->right);
        if (current->left != NULL)
            s.push(current->left);
    }
}

void postorder(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> s1, s2;
    s1.push(root);

    while (!s1.empty())
    {
        Node *current = s1.top();
        s1.pop();
        s2.push(current);

        if (current->left != NULL)
            s1.push(current->left);
        if (current->right != NULL)
            s1.push(current->right);
    }

    while (!s2.empty())
    {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

int main()
{
    Node *root = NULL;
    for (int value : {50, 30, 20, 40, 70, 60, 80})
        root = insert(root, value);

    cout << "Preorder: ";
    preorder(root);
    cout << "\nPostorder: ";
    postorder(root);
    cout << endl;
}
