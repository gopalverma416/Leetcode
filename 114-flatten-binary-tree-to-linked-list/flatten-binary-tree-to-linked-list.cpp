/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    void inorder(TreeNode* root, vector<int>& ans) {
        if (!root) {
            return;
        }
         ans.push_back(root->val);
        inorder(root->left, ans);
       
        inorder(root->right, ans);
    }

public:
    void flatten(TreeNode* root) {
        if (!root) {
            return;
        }
        vector<int> ans;
        inorder(root, ans);
        TreeNode* temp = root;
        int n = ans.size();
        for (int i = 0; i < n; i++) {
            temp->val = ans[i]; 
            temp->left = NULL; 
            if (i < n - 1) {
                temp->right = new TreeNode(0);
                temp = temp->right; 
            }
        }
        root = temp;
    }
};