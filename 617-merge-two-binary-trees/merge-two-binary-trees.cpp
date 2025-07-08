class Solution {
private:
    TreeNode* solve(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return nullptr;
        
        
        int val = (root1 ? root1->val : 0) + (root2 ? root2->val : 0);
        TreeNode* temp = new TreeNode(val);
        
       
        temp->left = solve(root1 ? root1->left : nullptr, root2 ? root2->left : nullptr);
        temp->right = solve(root1 ? root1->right : nullptr, root2 ? root2->right : nullptr);
        
        return temp;
    }

public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return solve(root1, root2);
    }
};
