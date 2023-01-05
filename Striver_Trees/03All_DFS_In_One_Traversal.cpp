#include <bits/stdc++.h> 
using namespace std;

template<typename T>
    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };



vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    // base case
    vector<vector<int>> ans;
    if(!root) return ans;
    stack<pair<BinaryTreeNode<int>*,int>> stk;
    stk.push(make_pair(root,1));
    
    vector<int> preorder;
    vector<int> postorder;
    vector<int> inorder;
    
    while(!stk.empty()) {
        pair<BinaryTreeNode<int>*,int> curr = stk.top();
        stk.pop();
        if(curr.second == 1) {
            preorder.push_back(curr.first->data);
            curr.second++;
            stk.push(curr);
            if(curr.first->left) {
                stk.push(make_pair(curr.first->left,1));
            }
        }
        else if(curr.second == 2) {
            inorder.push_back(curr.first->data);
            curr.second++;
            stk.push(curr);
            if(curr.first->right) {
                stk.push(make_pair(curr.first->right,1));
            }
        }
        else {
            postorder.push_back(curr.first->data);
        }

    }
    ans.push_back(inorder);
    ans.push_back(preorder);
    ans.push_back(postorder);
    
    return ans;
}