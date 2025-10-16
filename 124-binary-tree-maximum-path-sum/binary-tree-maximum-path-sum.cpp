class Solution {
    private:
    int dfs(TreeNode* root,int& sum,int& maxi){
        if(root==NULL){
            return 0;
        }

        int left=0;
        if(root->left){
            int samosa=root->left->val+dfs(root->left,sum,maxi);
            left=max(root->left->val,samosa);
        }
        int right=0;
        if(root->right){
            int samosa=root->right->val+dfs(root->right,sum,maxi);
            right=max(root->right->val,samosa);
        }
        sum=root->val;
        if(left>0){
        sum+=left;
        }
        if(right>0){
            sum+=right;
        }
    
        maxi=max(sum,maxi);
        return max(left,right);
    }
public:
    int maxPathSum(TreeNode* root) {
      
       int sum=0;
       int maxi=INT_MIN;
      int take= dfs(root,sum,maxi);
       return maxi;  
    }
};