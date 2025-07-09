class Solution {
private:
    bool solve(TreeNode* root, TreeNode* target) {
        if (root == NULL) return false;
        if (root == target) return true;

        
        return solve(root->left, target) || solve(root->right, target);
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;

        
        if (root == p || root == q) return root;

        bool isPInLeft = solve(root->left, p);
        bool isQInLeft = solve(root->left, q);

        if (isPInLeft && isQInLeft) {
           
            return lowestCommonAncestor(root->left, p, q);
        } else if (!isPInLeft && !isQInLeft) {
            
            return lowestCommonAncestor(root->right, p, q);
        } else {
          
            return root;
        }
    }
};
