
class Solution {
    private:
    TreeNode* solve(int left,int right,vector<int>& nums){
        if(left>right){
            return NULL;
        }
        int maxi=INT_MIN;
        int idx=0;
        for(int i=left;i<=right;i++){
            int val=nums[i];
            if(val>maxi){
             maxi=max(maxi,val);
             idx=i;
            }
           
        }
        TreeNode* root=new TreeNode(maxi);
        root->left=solve(left,idx-1,nums);
        root->right=solve(idx+1,right,nums);
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
       int n=nums.size()-1;
        return solve(0,n,nums);
    }
};