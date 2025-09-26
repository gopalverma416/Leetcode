class Solution {
    long long ans = 0;
    long long mod = 1e9+7;
    
    int sum(TreeNode* root){
        if(!root) return 0;
        int leftSum = sum(root->left);
        int rightSum = sum(root->right);
        root->val += leftSum + rightSum;
        return root->val;
    }
    
    void dfs(TreeNode* root, int total){
        if(!root) return;
        if(root->left) {
            long long prod = (long long)root->left->val * (total - root->left->val);
            ans = max(ans, prod);
            dfs(root->left, total);
        }
        if(root->right){
            long long prod = (long long)root->right->val * (total - root->right->val);
            ans = max(ans, prod);
            dfs(root->right, total);
        }
    }
    
public:
    int maxProduct(TreeNode* root) {
        int total = sum(root);
        dfs(root, total);
        return ans % mod;
    }
};
