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
    void solve(TreeNode* root,int& cnt){
        if(!root){
            return;
        }
        if(root->val%2==0){
            if(root->left){
                if(root->left->left){
                    cnt+=root->left->left->val;
                }
                if(root->left->right){
                    cnt+=root->left->right->val;
                }
            };
             if(root->right){
                if(root->right->left){
                   cnt+=root->right->left->val;
                }
                if(root->right->right){
                    cnt+=root->right->right->val;
                }
            }
        }
        solve(root->left,cnt);
        solve(root->right,cnt);
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        int cnt=0;
        solve(root,cnt);
        return cnt;
    }
};