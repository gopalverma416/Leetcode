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
    int longestZigZag(TreeNode* root) {
        if(root==NULL){
            return -1;
        } 
        int step=0;
        bool goLeft=false;
        int maxi=0;
        find(root, step, goLeft, maxi);
        return maxi;
    }
    void find(TreeNode* root, int step, bool goLeft, int& maxi){
        if(root==NULL){
            return;
        }
        maxi = max(maxi, step);
        if(goLeft){
            find(root->left, step+1, false, maxi);
            find(root->right, 1, true, maxi);
        } else {
            find(root->right, step+1, true, maxi);
            find(root->left, 1, false, maxi);
        }
    }
};