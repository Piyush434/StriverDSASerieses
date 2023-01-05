#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

// 1. Preorder Recursive ->

    vector<int> ans;
    vector<int> preorderTraversal_Recursive(TreeNode* root) {
        if(!root) return ans;
        ans.push_back(root->val);
        preorderTraversal_Recursive(root->left);
        preorderTraversal_Recursive(root->right);
        return ans;
    }

// Preorder Iterative

vector<int> preorderTraversal(TreeNode* root) {
        // 1. stack
        // 2. push root
        // 3. pop root -> print -> push right -> push left
        vector<int> ans;

        // edge case
        if(!root) return ans;

        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()) {
            TreeNode* curr = stk.top();
            stk.pop();
            ans.push_back(curr->val);

            if(curr->right)
                stk.push(curr->right);
            if(curr->left)
                stk.push(curr->left);
        }
        return ans;
    }


// 2. Inorder Recursive ->
void helper(vector<int>& ans,TreeNode* root) {
        if(root == NULL) return;

        helper(ans,root->left);
        ans.push_back(root->val);
        helper(ans,root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(ans,root);
        return ans;
    }

// Inorder iterative

vector<int> inorderTraversal_Iter(TreeNode* root) {
        // 1st take root
        // keep going on left until not null
        // if null -> print ans -> if right is not null -> go on right

        vector<int> ans;
        if(!root) return ans;

        TreeNode* node = root;
        stack<TreeNode*> stk;
        while(true) {
            if(node != NULL) {
                stk.push(node);
                node = node->left;
            }
            else {
                if(stk.empty()) break; // node is null and stack is empty

                node = stk.top();
                stk.pop();
                ans.push_back(node->val);
                node = node->right;
            }
        }
        return ans;
    }

// 3. Postorder -->

vector<int> ans;
    void helper(TreeNode* root) {
        // base case
        if(root == NULL) return;

        helper(root->left);
        helper(root->right);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        helper(root);
        return ans;
    }

// postorder iterative using two stack -->

vector<int> postorderTraversal_twoStack(TreeNode* root) {
        // Using two stack
        
        // put root in stk1
        // pop from stk1 -> to stk2 -> add left then right in stk1
        vector<int> ans;
        if(!root) return ans;

        stack<TreeNode*>  stk1;
        stack<TreeNode*>  stk2;
        stk1.push(root);

        while(!stk1.empty()) {
            TreeNode* node = stk1.top();
            stk1.pop();
            stk2.push(node);
            if(node->left) stk1.push(node->left);
            if(node->right) stk1.push(node->right);
        }

        while(!stk2.empty()) {
            TreeNode* node = stk2.top();
            stk2.pop();
            ans.push_back(node->val);
        }

        return ans;
    }

// postorder iterative using one stack -->

vector<int> postorderTraversal_onestack(TreeNode* root) {
        // Using 1 stack
        vector<int> ans;
        if(!root) return ans;

        stack<TreeNode*> stk;
        TreeNode* curr = root;
        while(curr != NULL || !stk.empty()) {
            if(curr != NULL) {
                // going on left left left
                stk.push(curr);
                curr = curr->left;
            }
            else {
                TreeNode* temp = stk.top()->right;
                // If right is not there
                if(temp == NULL) {
                    temp = stk.top();
                    stk.pop();
                    ans.push_back(temp->val);
                    // while stack is not empty and at top there is right of temp
                    while(!stk.empty() && temp == stk.top()->right) {
                        temp = stk.top();
                        stk.pop();
                        ans.push_back(temp->val);
                    }
                }
                // if there is right then continue with same process
                else {
                    curr = temp;
                }
            }
        }
        return ans;
    }

int main() {
    return 0;
}