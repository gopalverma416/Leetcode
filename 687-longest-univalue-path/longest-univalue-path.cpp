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
    int dfs(TreeNode* root, int& maxi) {
        if (!root) return 0;

        int left = dfs(root->left, maxi);
        int right = dfs(root->right, maxi);

        int leftPath = 0, rightPath = 0;

        if (root->left && root->left->val == root->val) {
            leftPath = left + 1;
        }
        if (root->right && root->right->val == root->val) {
            rightPath = right + 1;
        }

        maxi = max(maxi, leftPath + rightPath); 
        return max(leftPath, rightPath);      
    }

public:
    int longestUnivaluePath(TreeNode* root) {
        int maxi = 0;
        dfs(root, maxi);
        return maxi;
    }
};
