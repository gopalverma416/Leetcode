
class Solution {
    private:
    int camera=0;
    int dfs(TreeNode* root){
        if(!root){
            return 1;
        }
        // 2->node need camera
        // 1->node is covered by camera
        // 0->camera is placed at the node
        int left=dfs(root->left);
        int right=dfs(root->right);
        if(left==2 || right==2){
            camera++;
            return 0;
        }
        if(left==0 ||right==0){
            return 1;
        }
        return 2;
    }
    
public:
    int minCameraCover(TreeNode* root) {
        if(dfs(root)==2){
            camera++;
            return camera;
        }
        return camera;
    }
};