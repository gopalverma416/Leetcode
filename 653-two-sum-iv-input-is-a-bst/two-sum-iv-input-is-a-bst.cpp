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
    unordered_map<int,int>mp;
    bool solve(TreeNode* root,int k){
        if(!root){
            return false;
        }
        bool left=solve(root->left,k);
        int val=root->val;
        int rem=k-root->val;
        if(mp.count(rem)){
            return true;
        }
        mp[val]++;
        bool right=solve(root->right,k);
        return left||right;
    }
    bool findTarget(TreeNode* root, int k) {
        return solve(root,k);
    }
};