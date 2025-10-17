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
    private:
    int solve(TreeNode* root,int& maxi){
        if(!root){
            return 0;
        }
        int left=solve(root->left,maxi);
        int right=solve(root->right,maxi);
        int sum=left+right;
        maxi=max(maxi,sum);
        return 1+ max(left,right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=INT_MIN;
        solve(root,maxi);
        return maxi;
    }
};