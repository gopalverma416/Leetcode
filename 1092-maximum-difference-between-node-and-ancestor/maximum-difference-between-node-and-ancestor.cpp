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
public:
    int solve(TreeNode* root, int currMax, int currMin) {
        if (!root) {
            return abs(currMax - currMin);
        }
        int val = root->val;
        currMax = max(currMax, val);
        currMin = min(currMin, val);
        int left = solve(root->left, currMax, currMin);
        int right = solve(root->right, currMax, currMin);
        return max(left,right);
    }
    int maxAncestorDiff(TreeNode* root) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        return solve(root, maxi, mini);
    }
};