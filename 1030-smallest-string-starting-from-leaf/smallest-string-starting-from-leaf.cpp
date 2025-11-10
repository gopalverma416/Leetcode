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
    string smallest;
    void dfs(TreeNode* root,string curr){
       if(!root){
        return;
       }
       curr.push_back('a'+root->val);
       if(!root->left && !root->right){
        reverse(curr.begin(),curr.end());
        if(smallest.empty()|| curr< smallest){
            smallest=curr;
        }
        reverse(curr.begin(),curr.end());
       }
       dfs(root->left,curr);
       dfs(root->right,curr);
    }
    string smallestFromLeaf(TreeNode* root) {
        string curr="";
        dfs(root,curr);
      return smallest;
    }
};