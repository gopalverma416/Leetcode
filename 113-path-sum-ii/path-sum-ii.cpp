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

    vector<vector<int>>result;
    void dfs(TreeNode* root,int targetSum,vector<int>& temp){
        if(root==nullptr){
            return;
        }
        temp.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(targetSum==root->val){
                result.push_back(temp);
            }
        }
      
        dfs(root->left,targetSum-(root->val),temp);
        dfs(root->right,targetSum-(root->val),temp);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
        dfs(root,targetSum,temp);
        return result; 
    }
};