#include <iostream>
#include <climits>
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

void findDifference(Node *root, Node *&previous, int &answer)
{
    if (root == NULL)
        return;

    findDifference(root->left, previous, answer);

    if (previous != NULL)
        answer = min(answer, root->data - previous->data);
    previous = root;

    findDifference(root->right, previous, answer);
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    Node *previous = NULL;
    int answer = INT_MAX;
    findDifference(root, previous, answer);

    cout << "Minimum difference: " << answer << endl;
}


// 

#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* prev = NULL;
    int minDiffInBST(TreeNode* root) {
        if (root == NULL) return INT_MAX;

        int ans = INT_MAX;

        if(root->left != NULL){
            int leftMin = minDiffInBST(root->left);
            ans = min(ans, leftMin);
        }

        if(prev != NULL){
            ans = min(ans, root->val - prev->val);
        }
        
        prev = root;

        if(root-> right != NULL){
            int rightMin = minDiffInBST(root->right);
            ans = min(ans, rightMin);
        }
        return ans;
    }
};

int main(){
    
    return 0;
}