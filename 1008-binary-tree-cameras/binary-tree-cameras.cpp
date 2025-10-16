class Solution {
    private:
    int dfs(TreeNode* root,int& cnt){
        if(root==NULL){
            return 1;
        }
        // 2->root->node need camera 
        // 1->camera by camera
        // 0->has camera 
        int left=dfs(root->left,cnt);
        int right=dfs(root->right,cnt);
        if(left==2||right==2){
            cnt++;
            return 0;
        }
        if(left==0||right==0){
            return 1;
        }
       return 2;

    }
public:
    int minCameraCover(TreeNode* root) {
        int cnt=0;
        if(dfs(root,cnt)==2){
            cnt++;
        }
     return cnt;
    }
};