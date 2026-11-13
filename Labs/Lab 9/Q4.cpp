#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val):data(val){
        left = right = NULL;
    };
};

static int idx = -1;

Node* buildtree(vector<int>& arr){
    idx++;

    if(arr[idx] == -1) return NULL;

    Node* root = new Node(arr[idx]);
    root->left = buildtree(arr);
    root->right = buildtree(arr);

    return root;
}

int sum(Node* root){
    if(root == NULL) return 0;

    return root->data + sum(root->left) + sum(root->right);
}

int main(){
    vector<int> arr = {5, 3, 4, -1, -1, 2, -1, -1, 5, -1, 6, -1, -1};

    idx = -1;
    Node* root = buildtree(arr);

    cout << "Sum of tree is " << sum(root) << endl;

    return 0;
}
