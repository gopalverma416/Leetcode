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
    void dfs(TreeNode* root,int sum,int& total){
        
        if(!root){
            return;
        }
        int newSum=sum*10+ root->val;
        if(root && !root->left && !root->right){
            total+=newSum;
        }
        dfs(root->left,newSum,total);
        dfs(root->right,newSum,total);
        
    }
public:
    int sumNumbers(TreeNode* root) {
        int sum=0;
        int total=0;
        dfs(root,sum,total);
        return total;
    }
};