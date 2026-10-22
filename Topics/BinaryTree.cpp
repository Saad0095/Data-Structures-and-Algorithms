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

// PreOrder Traversal
void preOrder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << "\n";
    preOrder(root->left);
    preOrder(root->right);
};

// InOrder Traversal
void inOrder(Node *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << '\n';
    inOrder(root->right);
};

// PostOrder Traversal
void postOrder(Node *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    inOrder(root->right);
    cout << root->data << '\n';
};

// Normal LevelOrder Traversal
void levelOrder(Node *root)
{
    queue<Node *> q;

    q.push(root);
    while (q.size() > 0)
    {
        Node *curr = q.front();
        q.pop();

        cout << curr->data << ' ';
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
}

// Line wise LevelOrder Traversal
void lwLevelOrder(Node *root)
{
    queue<Node *> q;

    q.push(root);
    q.push(NULL);
    while (q.size() > 0)
    {
        Node *curr = q.front();
        q.pop();

        if (curr == NULL)
        {
            if (!q.empty())
            {
                cout << "\n";
                q.push(NULL);
                continue;
            }
            else
                break;
        }
        cout << curr->data << ' ';
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
}

int main()
{
    vector<int> arr = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(arr);

    cout << "\n**PreOrder Traversal**\n";
    preOrder(root);
    cout << "\n**InOrder Traversal**\n";
    inOrder(root);
    cout << "\n**PostOrder Traversal**\n";
    postOrder(root);

    cout << "\n**LevelOrder Traversal**\n";
    levelOrder(root);

    cout << "\n**Line Wise LevelOrder Traversal**\n";
    lwLevelOrder(root);
    return 0;
}