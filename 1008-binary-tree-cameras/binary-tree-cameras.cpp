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
    int camera;
    int dfs(TreeNode* root){
        // 2->need camera
        // 1->node covered by camera
        //  0->node have camera
       if(!root){
         return 1;
       }
       int left=dfs(root->left);
       int right=dfs(root->right);
       
       if(left==2 || right==2){
        camera++;
        return 0;
       }
        if(left==0||right==0){
          return 1;
       }
       return 2;
    }
public:
    int minCameraCover(TreeNode* root) {
        camera=0;
        if(dfs(root)==2){
            camera++;
        }
        return camera;
    }
};