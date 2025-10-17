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

    int solve(TreeNode* root,int& sum){
        if(!root){
            return 0;
        }
        int left=solve(root->left,sum);
        int right=solve(root->right,sum);
        sum+=(abs(left-right));
        return root->val+left+right;
    }
    int findTilt(TreeNode* root) {
        int sum=0;
       int take= solve(root,sum);
       return sum;
    }
};